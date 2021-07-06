
// VFF_clientDlg.h : header file
//

#pragma once

// ���� ��ǥ�迡�� Ÿ���� ��ġ�� ����
extern double _target_x;
extern double _target_y;
extern double _target_theta;

// ���� ��ǥ�迡�� �κ��� ��ġ�� ����
extern double _robot_x;
extern double _robot_y;
extern double _robot_theta;

// ������ �ּ�, �ִ� ���� �Ÿ�
extern double _sensor_min_range;
extern double _sensor_max_range;
// ������ ��ĵ ���� ������ �� ���� �� �ػ�
extern double _sensor_scan_range;
// ���� ���� ������ ���� �����ϴ� �迭
extern int _sensor_scan_count;
extern double _sensor_value[361];

// ���������� �κ��� ���� ũ�� �� ������ �Ÿ�
extern double _wheel_radius;
extern double _axle_length;
extern double _robot_diameter;


extern double _target_direction;
extern double _steer_magnitude;
extern double _steer_direction;

extern void expand_obstacle();
extern bool tangent_bug();
extern void speed_control();

