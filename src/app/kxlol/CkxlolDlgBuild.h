#pragma once


// CkxlolDlgBuild �Ի���

class CkxlolDlgBuild : public CDialogEx
{
	DECLARE_DYNAMIC(CkxlolDlgBuild)

public:
	CkxlolDlgBuild(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CkxlolDlgBuild();

// �Ի�������
	enum { IDD = IDD_KXLOL_DIALOG_BUILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnBuildShenminxinqiu();
};
