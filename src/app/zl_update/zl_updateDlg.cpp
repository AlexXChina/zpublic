
// zl_updateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zl_update.h"
#include "zl_updateDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Czl_updateDlg �Ի���



Czl_updateDlg::Czl_updateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Czl_updateDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Czl_updateDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, m_listbox);
    DDX_Control(pDX, IDC_BUTTON1, m_btn);
}

BEGIN_MESSAGE_MAP(Czl_updateDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &Czl_updateDlg::OnBnClickedButton1)
    
    ON_MESSAGE(WM_USER_ADD_STRING, OnAddString)
    ON_MESSAGE(WM_USER_ENABLE_BTN, OnEnableBtn)
END_MESSAGE_MAP()


// Czl_updateDlg ��Ϣ�������

BOOL Czl_updateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

    m_listbox.AddString(L"���\"����\"��ť���и��£�");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Czl_updateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Czl_updateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Czl_updateDlg::OnBnClickedButton1()
{
    SendMessage(WM_USER_ADD_STRING, (WPARAM)L"��ʼ���¡�����");
    HANDLE h = (HANDLE)_beginthreadex(NULL, 0, ThreadUpdate, this, 0, NULL);
    if (h)
    {
        m_btn.EnableWindow(FALSE);
        ::CloseHandle(h);
    }
    else
    {
        SendMessage(WM_USER_ADD_STRING, (WPARAM)L"���������߳�ʧ��");
    }
}

unsigned int __stdcall Czl_updateDlg::ThreadUpdate(void* param)
{
    Czl_updateDlg* p = (Czl_updateDlg*)param;
    p->_ThreadUpdate();
    return 0;
}

void Czl_updateDlg::_ThreadUpdate()
{
    PostMessage(WM_USER_ADD_STRING, (WPARAM)L"���������ļ�");

    zl::http::ZLHttpClient http;
    zl::http::ZLMemWrite m;
    if (0 == http.DownloadMem(L"http://www.laorouji.com/kxlol/data.json", &m, 20000))
    {
        PostMessage(WM_USER_ADD_STRING, (WPARAM)L"���������ļ��ɹ�");
        Json::Reader read;
        Json::Value v;
        if (read.parse(
            (const char*)m.GetData(),
            (const char*)(m.GetData() + m.GetLength() - 1),
            v))
        {


            PostMessage(WM_USER_ADD_STRING, (WPARAM)L"�������");
        }
        else
        {
            PostMessage(WM_USER_ADD_STRING, (WPARAM)L"���������ļ�ʧ��");
        }
    }
    else
    {
        PostMessage(WM_USER_ADD_STRING, (WPARAM)L"���������ļ�ʧ��");
    }
    PostMessage(WM_USER_ENABLE_BTN);
}

LRESULT Czl_updateDlg::OnAddString(WPARAM w, LPARAM l)
{
    m_listbox.AddString((LPCWSTR)(w));
    m_listbox.SetSel(m_listbox.GetCount() - 1, FALSE);
    return 0;
}

LRESULT Czl_updateDlg::OnEnableBtn(WPARAM w, LPARAM l)
{
    m_btn.EnableWindow(TRUE);
    return 0;
}
