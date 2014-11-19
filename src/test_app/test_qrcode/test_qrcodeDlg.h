
// test_qrcodeDlg.h : ͷ�ļ�
//

#pragma once
#include "zqrcode_wrappage.h"
#include "z_win_utils\gdiplus.hpp"

// Ctest_qrcodeDlg �Ի���
class Ctest_qrcodeDlg : public CDialogEx
{
// ����
public:
	Ctest_qrcodeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_QRCODE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
    zl::WinUtils::ZLGdiPlusInit m_gdiplus;
    ZQRcodeWrappage             m_qrcode;
};
