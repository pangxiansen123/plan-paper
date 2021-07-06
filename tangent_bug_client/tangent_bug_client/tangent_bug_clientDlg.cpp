
// tangent_bug_clientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tangent_bug_client.h"
#include "tangent_bug_clientDlg.h"

#include "mm.h"
#include "mrs_rpc.h"
#include "tangent_bug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 윈도우 화면에서 시작 위치와 m를 pixel로 바꾸기 위한 스케일 값 설정
#define X0		100
#define Y0		500
#define SCALE	50

inline int DLG_X(double x) { return (int)(X0 + x*SCALE); }
inline int DLG_Y(double y) { return (int)(Y0 - y*SCALE); }

extern int rpc_client_init();
extern int rpc_client_free();

// Ctangent_bug_clientDlg dialog

Ctangent_bug_clientDlg::Ctangent_bug_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ctangent_bug_clientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctangent_bug_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctangent_bug_clientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctangent_bug_clientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Ctangent_bug_clientDlg message handlers

BOOL Ctangent_bug_clientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	rpc_client_init();

	
	SetTimer(1000, 33, NULL);

	OnBnClickedButton1();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctangent_bug_clientDlg::OnPaint()
{
	CPaintDC dc(this); 

	if (_memDC.GetSafeHdc() == NULL) {
		GetClientRect (&_memDCRect);

		_memDC.CreateCompatibleDC(&dc);
		_bitmap.CreateCompatibleBitmap(&dc, _memDCRect.Width(), _memDCRect.Height());
		_bitmapOld = _memDC.SelectObject(&_bitmap);
		ASSERT (_bitmapOld);
	}

	if (_memDC.GetSafeHdc() != NULL) {
		dc.BitBlt(_memDCRect.left, _memDCRect.top, _memDCRect.Width(), _memDCRect.Height(), &_memDC, 0,0, SRCCOPY);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctangent_bug_clientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Ctangent_bug_clientDlg::OnTimer(UINT_PTR nIDEvent)
{
	double leftMotor = 0;
	double rightMotor = 0;

	RpcTryExcept
	{
		GetRobotPosition (&_robot_x, &_robot_y, &_robot_theta);
		GetMotorPosition (&leftMotor, &rightMotor);
		GetScanningLaserData (_sensor_value, (long *)&_sensor_scan_count);
	}
	RpcExcept(1)
	{
		char text[1024];
		sprintf (text, "Runtime exception occured: %l \n", (long)RpcExceptionCode());
		TRACE (text);
	}
	RpcEndExcept

	expand_obstacle();
	tangent_bug();
	speed_control();

	double v = _steer_magnitude;
	double w = DeltaRad (_steer_direction, _robot_theta);

	double theta_r = v/_wheel_radius + w*_axle_length/(2*_wheel_radius);
	double theta_l = v/_wheel_radius - w*_axle_length/(2*_wheel_radius);

	RpcTryExcept
	{
		GoMotorVelocity(theta_l, theta_r);
	}
	RpcExcept(1)
	{
		char text[1024];
		sprintf (text, "Runtime exception occured: %l \n", (long)RpcExceptionCode());
		TRACE (text);
	}
	RpcEndExcept


	_memDC.SelectStockObject (WHITE_PEN);
	_memDC.SelectStockObject (WHITE_BRUSH);
	_memDC.Rectangle(0, 0, 3000, 3000);

	DrawScanningLaser (_memDC, _robot_x, _robot_y);

	extern bool _motion_to_goal;
	DrawRobot(_memDC, _robot_x, _robot_y, _robot_theta, _motion_to_goal ? RGB(0,0,255) : RGB(0,255,255));
	DrawRobot(_memDC, _target_x, _target_y, _target_theta, RGB(0,255,0));

	DrawVector(_memDC, _robot_x, _robot_y, _target_direction, 1, RGB(0,255,0));
	DrawVector(_memDC, _robot_x, _robot_y, _steer_direction, 2, RGB(0,0,255));
	

	InvalidateRect (&_memDCRect, FALSE);

	CDialog::OnTimer(nIDEvent);
}


void Ctangent_bug_clientDlg::DrawRobot(CDC &dc, double x, double y, double theta, COLORREF color)
{
	dc.SelectStockObject (WHITE_BRUSH);

	CPen pen (PS_SOLID, 2, color);
	dc.SelectObject (pen);

	int cx = DLG_X(x);
	int cy = DLG_Y(y);
	int cr = (int)(_axle_length/2*SCALE);

	int dx = (int)(cr*cos(theta));
	int dy = (int)(cr*sin(theta));

	dc.Ellipse (cx-cr, cy-cr, cx+cr, cy+cr);
	dc.MoveTo (cx, cy);
	dc.LineTo (cx+dx, cy-dy);
}

void Ctangent_bug_clientDlg::DrawVector(CDC &dc, double x, double y, double theta, double magnitude, COLORREF color)
{
	CPen pent (PS_SOLID, 2,color);
	dc.SelectObject (pent);

	int sx = DLG_X(x);
	int sy = DLG_Y(y);

	int ex = sx + (int)(magnitude*cos(theta)*SCALE);
	int ey = sy - (int)(magnitude*sin(theta)*SCALE);

	dc.MoveTo (sx, sy);
	dc.LineTo (ex, ey);
}

void Ctangent_bug_clientDlg::DrawScanningLaser (CDC &dc, double x, double y)
{
	CPen pen (PS_SOLID, 1, RGB(255,0,0));
	dc.SelectObject (pen);

	double dang = _sensor_scan_range/(_sensor_scan_count - 1);

	for (int i=0; i<_sensor_scan_count; ++i) {
		double ang = _robot_theta - _sensor_scan_range/2 + i*dang;

		double dx = x + _sensor_value[i]*cos(ang);
		double dy = y + _sensor_value[i]*sin(ang);

		dc.MoveTo (DLG_X(x), DLG_Y(y));
		dc.LineTo (DLG_X(dx), DLG_Y(dy));
	}
}


void Ctangent_bug_clientDlg::OnDestroy()
{
	CDialog::OnDestroy();

	rpc_client_free ();
}

void Ctangent_bug_clientDlg::OnBnClickedButton1()
{
	RpcTryExcept
	{
		SetRobotPosition(1.5, 1.5, _DEG2RAD*0);
	}
	RpcExcept(1)
	{
		char text[1024];
		sprintf (text, "Runtime exception occured: %l \n", (long)RpcExceptionCode());
		TRACE (text);
	}
	RpcEndExcept
}
