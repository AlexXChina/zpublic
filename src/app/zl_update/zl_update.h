
// zl_update.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Czl_updateApp: 
// �йش����ʵ�֣������ zl_update.cpp
//

class Czl_updateApp : public CWinApp
{
public:
	Czl_updateApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Czl_updateApp theApp;