// CkxlolDlgBuild.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "kxlol.h"
#include "CkxlolDlgBuild.h"
#include "afxdialogex.h"


// CkxlolDlgBuild �Ի���

IMPLEMENT_DYNAMIC(CkxlolDlgBuild, CDialogEx)

CkxlolDlgBuild::CkxlolDlgBuild(CWnd* pParent /*=NULL*/)
    : CDialogEx(CkxlolDlgBuild::IDD, pParent)
{

}

CkxlolDlgBuild::~CkxlolDlgBuild()
{
}

void CkxlolDlgBuild::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CkxlolDlgBuild, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_BUILD_SHENMINXINQIU, &CkxlolDlgBuild::OnBnClickedBtnBuildShenminxinqiu)
    ON_BN_CLICKED(IDC_LUNHUISHENDIAN, &CkxlolDlgBuild::OnBnClickedLunhuishendian)
END_MESSAGE_MAP()


// CkxlolDlgBuild ��Ϣ�������


void CkxlolDlgBuild::OnBnClickedBtnBuildShenminxinqiu()
{
    GAME.Logic().Build().Build(L"shenminxinqiu");
}


void CkxlolDlgBuild::OnBnClickedLunhuishendian()
{
    GAME.Logic().Build().Build(L"lunhuishendian");
    // TODO: �ڴ���ӿؼ�֪ͨ����������
}
