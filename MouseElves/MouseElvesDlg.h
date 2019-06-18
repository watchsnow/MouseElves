
// MouseElvesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMouseElvesDlg �Ի���
class CMouseElvesDlg : public CDialogEx
{
// ����
public:
    CMouseElvesDlg(CWnd* pParent = NULL);   // ��׼���캯��

// �Ի�������
    enum { IDD = IDD_MOUSEELVES_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��


// ʵ��
protected:
    HICON m_hIcon;

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnStart();
	int m_nLkey;
	int m_nClick;
	afx_msg void OnBnClickedRdoLkey();
	afx_msg void OnBnClickedRdoClick();
	afx_msg void OnBnClickedRdoRkey();
	afx_msg void OnBnClickedRdoDouble();
	CEdit m_editPX;
	CEdit m_editPY;
	CEdit m_editFrequency;
	CEdit m_editPX2;
	CEdit m_editPY2;
	int m_nFrequency;
	int m_nPX;
	int m_nPX2;
	int m_nPY;
	int m_nPY2;
};
