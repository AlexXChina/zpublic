
// kxlol.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CkxlolApp: 
// �йش����ʵ�֣������ kxlol.cpp
//

class CkxlolApp : public CWinApp
{
public:
	CkxlolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CkxlolApp theApp;