
// VFF_clientDlg.h : header file
//

#pragma once

// 전역 좌표계에서 타겟의 위치와 방향
extern double _target_x;
extern double _target_y;
extern double _target_theta;

// 전역 좌표계에서 로봇의 위치와 방향
extern double _robot_x;
extern double _robot_y;
extern double _robot_theta;

// 센서의 최소, 최대 감지 거리
extern double _sensor_min_range;
extern double _sensor_max_range;
// 센서의 스캔 시작 각도와 끝 각도 및 해상도
extern double _sensor_scan_range;
// 센서 값의 개수와 값을 저장하는 배열
extern int _sensor_scan_count;
extern double _sensor_value[361];

// 차동바퀴형 로봇의 바퀴 크기 및 바퀴간 거리
extern double _wheel_radius;
extern double _axle_length;
extern double _robot_diameter;


extern double _target_direction;
extern double _steer_magnitude;
extern double _steer_direction;

extern void expand_obstacle();
extern bool tangent_bug();
extern void speed_control();

