
// MouseElvesDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMouseElvesDlg 对话框
class CMouseElvesDlg : public CDialogEx
{
// 构造
public:
    CMouseElvesDlg(CWnd* pParent = NULL);   // 标准构造函数

// 对话框数据
    enum { IDD = IDD_MOUSEELVES_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


// 实现
protected:
    HICON m_hIcon;

    // 生成的消息映射函数
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
