
// kxlolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CkxlolDlg �Ի���
class CkxlolDlg : public CDialogEx
{
// ����
public:
	CkxlolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
    enum { IDD = IDD_KXLOL_DIALOG_ZHUSHENKONGJIAN };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnGotoDonglijian();
    afx_msg void OnBnClickedBtnGotoYuanshiyuzhou();
    afx_msg void OnBnClickedBtnNingjushenli();
    afx_msg void OnBnClickedBtnBuild();
    afx_msg void OnBnClickedBtnMake();
    afx_msg void OnBnClickedBtnPractioce();
    afx_msg void OnBnClickedBtnConnectXukong();

private:
    // ��ǰ����ֵ
    ULONGLONG m_ulShenli;
public:
    // ����ռ��������Ϣ��
    CListBox m_listMsg;
    // ����������ť
    CButton m_btnNingjushenli;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    // ��ǰӵ�е���Դ
    CTreeCtrl m_treeRes;
};
