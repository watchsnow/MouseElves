
// MouseElvesDlg.h : ͷ�ļ�
//

#pragma once


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
};
