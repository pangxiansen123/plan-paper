
// tangent_bug_clientDlg.h : header file
//

#pragma once


// Ctangent_bug_clientDlg dialog
class Ctangent_bug_clientDlg : public CDialog
{
// Construction
public:
	Ctangent_bug_clientDlg(CWnd* pParent = NULL);	// standard constructor

	void DrawRobot(CDC &dc, double x, double y, double theta, COLORREF color);
	void DrawVector(CDC &dc, double x, double y, double theta, double magnitude, COLORREF color);
	void DrawScanningLaser (CDC &dc, double x, double y);

	CRect    _memDCRect;
	CDC      _memDC;
	CBitmap  _bitmap;
	CBitmap* _bitmapOld;


// Dialog Data
	enum { IDD = IDD_TANGENT_BUG_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
};
