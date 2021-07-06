
#include "stdafx.h"
#include <math.h>
#include "mm.h"
#include "tangent_bug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ��ǥ�迡�� Ÿ���� ��ġ�� ����
double _target_x = 10;
double _target_y = 7;
double _target_theta = _DEG2RAD*0;

// ���� ��ǥ�迡�� �κ��� ��ġ�� ����
double _robot_x = 1.5;
double _robot_y = 1.5;
double _robot_theta = _DEG2RAD*0;

// ������ �ּ�, �ִ� ���� �Ÿ�
double _sensor_min_range = 0.03;
double _sensor_max_range = 2.;
// ������ ��ĵ ���� ������ �� ���� �� �ػ�
double _sensor_scan_range = _DEG2RAD*360;
// ���� ���� ������ ���� �����ϴ� �迭
int _sensor_scan_count = 361;
double _sensor_value[361] = {0., };

// ���������� �κ��� ���� ũ�� �� ������ �Ÿ�
double _wheel_radius = 0.2;
double _axle_length = 0.4;

double _robot_diameter = 0.5;

extern int rpc_client_init();
extern int rpc_client_free();

double _target_direction = 0;
double _steer_magnitude = 0;
double _steer_direction = 0;

#define V_max		0.9
#define V_min		0.05
#define Omega_max	(_DEG2RAD*90)


bool _motion_to_goal = false;
double _d_followed = 1000.;


inline int H_ID(double theta)
{
	double alpha = 1.;
	return (int)(theta + 10*360. + alpha/2.)%360;
}

void expand_obstacle()
{
	double tmp[361];
	double robot_radius = _robot_diameter/2.;

	for (int j=0; j<_sensor_scan_count; ++j) {
		tmp[j] = _sensor_max_range;
	}

	for (int j=0; j<_sensor_scan_count; ++j) {
		double distance = _sensor_value[j];

		if (distance < _sensor_max_range) {
			double beta = _DEG2RAD*j;
			double gamma = asin(robot_radius/distance);

			for (double i = beta-gamma; i < beta+gamma; i+=1.*_DEG2RAD) {
				double gamma_i = fabs(i - beta);
				double r = distance*sin(gamma_i);

				if (r <= robot_radius) {
					double d_i = distance*cos(gamma_i) - sqrt(robot_radius*robot_radius - r*r);
					// if (d_i < _sensor_min_range) d_i = _sensor_min_range;

					int index = H_ID(i*_RAD2DEG);
					tmp[index] = min(tmp[index], d_i);
				}
			}
		}
	}

	tmp[360] = tmp[0];
	memcpy (_sensor_value, tmp, sizeof(double)*_sensor_scan_count);
}


double heuristic_distance ()
{
	double dx = _target_x - _robot_x;
	double dy = _target_y - _robot_y;

	return sqrt (dx*dx + dy*dy);
}

double heuristic_distance (double angle, double magnitude)
{
	double dtx = _target_x - _robot_x;
	double dty = _target_y - _robot_y;

	double dsx = magnitude*cos(angle);
	double dsy = magnitude*sin(angle);

	dtx -= dsx;
	dty -= dsy;

	return sqrt (dtx*dtx + dty*dty) + sqrt (dsx*dsx + dsy*dsy);
}

bool find_min_distance_of_path (double &distance_, double &direction_)
{
	double min_distance = 1e6;
	double min_direction = 0;

	for (int i=0; i<_sensor_scan_count-1; ++i) {
		if ((_sensor_value[i] == _sensor_max_range && _sensor_value[i+1] < _sensor_max_range) ||
			(_sensor_value[i] <  _sensor_max_range && _sensor_value[i+1] == _sensor_max_range) ||
			(_robot_diameter < fabs(_sensor_value[i] - _sensor_value[i+1])) ) {

			double direction = _robot_theta + _DEG2RAD*(i + 0.5 - _sensor_scan_count/2);
			double distance = heuristic_distance (direction, (_sensor_value[i] + _sensor_value[i+1])/2.);

			if (distance < min_distance) {
				min_distance = distance;
				min_direction = direction;
			}
		}
	}

	if (min_distance < 1e6) {
		direction_ = min_direction;
		distance_  = min_distance;
		return true;
	}
	else {
		return false;
	}
}

bool motion_to_goal ()
{
	// �κ��� ��ǥ���� ���̿� ��ֹ��� �����Ǵ��� Ȯ��
	int index = H_ID(_RAD2DEG*DeltaRad(_target_direction, _robot_theta) - _sensor_scan_count/2);
	bool not_intersect = _sensor_value[index] == _sensor_max_range;
	
	if (not_intersect) {
		// �κ��� ��ǥ���� ���̿� ��ֹ��� �������� �ʾҴ�.
		// �κ��� ��ǥ������ ���� �����Ѵ�.
		_steer_direction = _target_direction;
		_steer_magnitude = V_max;

		_d_followed = heuristic_distance ();
	}
	else {
		// �κ��� ��ǥ���� ���̿� ��ֹ��� �����Ǿ���.
		// �κ�-��ֹ��� �����-��ǥ������ �մ� ��ε� �߿��� �ִܰ�θ� �����Ͽ� �����Ѵ�.
		double direction;
		double d_reach;

		if (find_min_distance_of_path (d_reach, direction)) {
			_steer_direction = direction;
			_steer_magnitude = V_max;

			// ���̻� �ִܰ���� �Ÿ��� �ٿ����� �� ���� ��Ȳ�̴�.
			// boundary_following���� ��ȯ.
			if (d_reach > _d_followed + 0.1) {
				d_reach = _d_followed - 0.1;
				_motion_to_goal = false;
			}
		}
		else {
			// �κ��� �������� ������ ������ �ʴ´�.
			// �׺���̼� ����!
			_steer_magnitude = 0.;
			return false;
		}

		_d_followed = d_reach;
	}
	return true;
}

bool find_index_of_min_distance(int &index)
{
	double min_distance = _sensor_max_range;
	int min_index = -1;

	for (int i=0; i<_sensor_scan_count; ++i) {
		double distance = _sensor_value[i];
		if (distance < min_distance) {
			min_distance = distance;
			min_index = i;
		}
	}

	if (min_index != -1) {
		index = min_index;
		return true;
	}
	else {
		return false;
	}
}

bool seek_right_side_waypoint (int base_index, double &distance, double &direction)
{
	for (int i=1; i<_sensor_scan_count; ++i) {
		int ii = H_ID(base_index + i);

		if ((_sensor_value[ii] == _sensor_max_range) ||
			(_robot_diameter < fabs(_sensor_value[ii] - _sensor_value[ii-1])) ) {
				
			direction = _robot_theta + _DEG2RAD*(ii + 0.5 - _sensor_scan_count/2);
			distance = heuristic_distance (direction, (_sensor_value[ii] + _sensor_value[ii-1])/2.);
			return true;
		}
	}
	return false;
}

bool seek_left_side_waypoint (int base_index, double &distance, double &direction)
{
	for (int i=0; i<_sensor_scan_count-1; ++i) {
		int ii = H_ID(base_index - i);

		if ((_sensor_value[ii] == _sensor_max_range) ||
			(_robot_diameter < fabs(_sensor_value[ii] - _sensor_value[ii+1])) ) {
				
			direction = _robot_theta + _DEG2RAD*(ii - 0.5 - _sensor_scan_count/2);
			distance = heuristic_distance (direction, (_sensor_value[ii] + _sensor_value[ii+1])/2.);
			return true;
		}
	}
	return false;
}

bool boundary_following ()
{
	// �κ��� ��ǥ���� ���̿� ��ֹ��� �����Ǵ��� Ȯ��
	int index = H_ID(_RAD2DEG*DeltaRad(_target_direction, _robot_theta) - _sensor_scan_count/2);
	bool not_intersect = _sensor_value[index] == _sensor_max_range;
	
	if (not_intersect) {
		// �κ��� ��ǥ���� ���̿� ��ֹ��� �������� �ʾҴ�.
		// �κ��� ��ǥ������ ���� �����Ѵ�.
		_motion_to_goal = true;
	}

	int base_index;

	if (find_index_of_min_distance (base_index)) {
		bool ret;
		double direction = 0.;
		double distance = 1e6;

		if (base_index < _sensor_scan_count/2) {
			// ��ֹ��� ���� ����� ���� �κ��� ���� �ʿ� ����.
			ret = seek_right_side_waypoint (base_index, distance, direction);
		}
		else {
			// ��ֹ��� ���� ����� ���� �κ��� �� �ʿ� ����.
			ret = seek_left_side_waypoint (base_index, distance, direction);
		}

		if (ret) {
			_steer_direction = direction;
			_steer_magnitude = V_max;

			if (distance < _d_followed) {
				_steer_magnitude = 0.;
				_motion_to_goal = true;
			}
		}
		else {
			return false;
		}	
	}
	else {
		_motion_to_goal = true;
	}

	return true;
}

bool tangent_bug()
{
	_target_direction = atan2(_target_y - _robot_y, _target_x - _robot_x);

	if (_motion_to_goal) {
		return motion_to_goal ();
	}
	else { 
		return boundary_following ();
	}
}

void speed_control()
{
	if (_steer_magnitude < V_min) _steer_magnitude = V_min;

	double Omega = DeltaRad (_steer_direction, _robot_theta);

	_steer_magnitude = _steer_magnitude*(1. - fabs(Omega)/Omega_max);
	if (_steer_magnitude < V_min) _steer_magnitude = V_min;
}