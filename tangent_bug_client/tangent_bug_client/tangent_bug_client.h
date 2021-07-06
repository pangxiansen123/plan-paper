
// tangent_bug_client.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ctangent_bug_clientApp:
// See tangent_bug_client.cpp for the implementation of this class
//

class Ctangent_bug_clientApp : public CWinAppEx
{
public:
	Ctangent_bug_clientApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctangent_bug_clientApp theApp;