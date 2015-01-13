
// kxlolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "kxlol.h"
#include "kxlolDlg.h"
#include "afxdialogex.h"
#include "CkxlolDlgBuild.h"
#include "TimerBaiscTask.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkxlolDlg �Ի���



CkxlolDlg::CkxlolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkxlolDlg::IDD, pParent)
    , m_ulShenli(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkxlolDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_CURRENT_SHENLI, m_ulShenli);
    DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
    DDX_Control(pDX, IDC_BTN_NINGJUSHENLI, m_btnNingjushenli);
    DDX_Control(pDX, IDC_TREE_RES, m_treeRes);
}

BEGIN_MESSAGE_MAP(CkxlolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_GOTO_DONGLIJIAN, &CkxlolDlg::OnBnClickedBtnGotoDonglijian)
    ON_BN_CLICKED(IDC_BTN_GOTO_YUANSHIYUZHOU, &CkxlolDlg::OnBnClickedBtnGotoYuanshiyuzhou)
    ON_BN_CLICKED(IDC_BTN_NINGJUSHENLI, &CkxlolDlg::OnBnClickedBtnNingjushenli)
    ON_BN_CLICKED(IDC_BTN_BUILD, &CkxlolDlg::OnBnClickedBtnBuild)
    ON_BN_CLICKED(IDC_BTN_MAKE, &CkxlolDlg::OnBnClickedBtnMake)
    ON_BN_CLICKED(IDC_BTN_PRACTIOCE, &CkxlolDlg::OnBnClickedBtnPractioce)
    ON_BN_CLICKED(IDC_BTN_CONNECT_XUKONG, &CkxlolDlg::OnBnClickedBtnConnectXukong)
    ON_WM_TIMER()
	ON_MESSAGE(KXLOL_WM_UPDATEGUI, &CkxlolDlg::OnUpdateGUI)
	ON_MESSAGE(KXLOL_WM_UPDATETREENODE, &CkxlolDlg::OnUpdateTreeNode)
	ON_MESSAGE(KXLOL_WM_UPDATEGUI,      &CkxlolDlg::OnUpdateGUI)
    ON_MESSAGE(KXLOL_WM_INFO_OUTPUT,    &CkxlolDlg::OnInfoOutput)
END_MESSAGE_MAP()


// CkxlolDlg ��Ϣ�������

BOOL CkxlolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    HTREEITEM h2 = m_treeRes.InsertItem(L"����");
    m_treeRes.InsertItem(L"ʳ��ħ��3", h2);
    m_treeRes.InsertItem(L"λ�������ߣ�1", h2);

    HTREEITEM h3 = m_treeRes.InsertItem(L"����");
    m_treeRes.InsertItem(L"���棺2", h3);

    m_ulShenli = GAME.Player().BasicInfo().GetShenli();

    zl::TimerTaskNolmal* t = new zl::TimerTaskNolmal(TimerBaiscTask::BasicMinuteTask);
    t->Timeout(zl::TimerCalcMilliseconds(1, 0));
    t->Repeat(true);
    GAME.Timer().AddNormalTask(t);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CkxlolDlg::OnPaint()
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
HCURSOR CkxlolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CkxlolDlg::OnBnClickedBtnGotoDonglijian()
{
    MessageBox(L"�����뻹û��������");
}


void CkxlolDlg::OnBnClickedBtnGotoYuanshiyuzhou()
{
    MessageBox(L"ԭʼλ�滹û��������");
}


void CkxlolDlg::OnBnClickedBtnNingjushenli()
{
    m_listMsg.AddString(L"��ʼ��������...");
    m_btnNingjushenli.EnableWindow(FALSE);
    m_btnNingjushenli.SetWindowText(L"������������");
    SetTimer(1, 2000, NULL);
}


void CkxlolDlg::OnBnClickedBtnBuild()
{
    CkxlolDlgBuild dlg;
    dlg.DoModal();
}


void CkxlolDlg::OnBnClickedBtnMake()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CkxlolDlg::OnBnClickedBtnPractioce()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CkxlolDlg::OnBnClickedBtnConnectXukong()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}

LRESULT CkxlolDlg::OnUpdateGUI(WPARAM, LPARAM)
{
	m_ulShenli = GAME.Player().BasicInfo().GetShenli();
	UpdateData(FALSE);

	return 0L;
}

LRESULT CkxlolDlg::OnUpdateTreeNode(WPARAM pRootName, LPARAM pNodeName)
{
	auto pwszRootName = (LPCWSTR)pRootName;
	auto pwszNodeName = (LPCWSTR)pNodeName;
	auto itRoot = m_treeNodeHandles.find(pwszRootName);
	if(m_treeNodeHandles.end() != itRoot)
	{
		auto itNode = itRoot->second.second.find(pwszNodeName);
		if(itRoot->second.second.end() != itNode)
		{
			UpdateNode(pwszRootName, pwszNodeName);
			return 0L;
		}
	}

	CreateNode(pwszRootName, pwszNodeName);

	return 0L;
}

void CkxlolDlg::CreateNode(const wchar_t* rootName, const wchar_t* nodeName)
{
	auto resNum = GAME.Player().RegBag().GetResNum(rootName, nodeName);
	if(0 != resNum)
	{
		auto itRoot = m_treeNodeHandles.find(rootName);
		if(m_treeNodeHandles.end() == itRoot)
		{
			HTREEITEM hRoot = m_treeRes.InsertItem(rootName);
			m_treeNodeHandles.insert(std::make_pair(rootName, std::make_pair(hRoot, TREENODEHANDLE())));
			itRoot = m_treeNodeHandles.find(rootName);
		}
		HTREEITEM hRoot = itRoot->second.first;
		std::wstring temp;
		std::wstringstream wsstemp;
		wsstemp << nodeName << L":" << resNum;
		wsstemp >> temp;
		HTREEITEM hNode = m_treeRes.InsertItem(temp.c_str(), hRoot);

		itRoot->second.second.insert(std::make_pair(nodeName, hNode)); 
	}
}

void CkxlolDlg::UpdateNode(const wchar_t* rootName, const wchar_t* nodeName)
{
	auto resNum = GAME.Player().RegBag().GetResNum(rootName, nodeName);
	auto itRoot = m_treeNodeHandles.find(rootName);
	if(m_treeNodeHandles.end() != itRoot)
	{
		auto& nodes = itRoot->second.second;
		auto itNode = nodes.find(nodeName);
		if(nodes.end() != itNode)
		{
			HTREEITEM hNode = itNode->second;
			if(0 == resNum)
				m_treeRes.DeleteItem(hNode);
			else
			{
				std::wstring temp;
				std::wstringstream wsstemp;
				wsstemp << nodeName << L":" << resNum;
				wsstemp >> temp;
				m_treeRes.SetItemText(hNode, temp.c_str());
			}
		}
	}
}

void CkxlolDlg::OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent)
    {
    case 1:
        KillTimer(1);
        m_listMsg.AddString(L"����������ɣ�����1���������");
        m_btnNingjushenli.EnableWindow(TRUE);
        m_btnNingjushenli.SetWindowText(L"��������");
        GAME.Player().BasicInfo().AddShenli(1);
        m_ulShenli = GAME.Player().BasicInfo().GetShenli();
        UpdateData(FALSE);
        break;
    default:
        break;
    }

    CDialogEx::OnTimer(nIDEvent);
}

LRESULT CkxlolDlg::OnInfoOutput(WPARAM wp, LPARAM)
{
    m_listMsg.AddString((const wchar_t *)wp);
    return 0;
}
