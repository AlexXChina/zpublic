
// test_qrcode.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest_qrcodeApp:
// �йش����ʵ�֣������ test_qrcode.cpp
//

class Ctest_qrcodeApp : public CWinApp
{
public:
	Ctest_qrcodeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest_qrcodeApp theApp;