
// SimulatedMouseClickDlg.h : ͷ�ļ�
//

#pragma once


// CSimulatedMouseClickDlg �Ի���
class CSimulatedMouseClickDlg : public CDialogEx
{
// ����
public:
    CSimulatedMouseClickDlg(CWnd* pParent = NULL);  // ��׼���캯��

// �Ի�������
    enum { IDD = IDD_SIMULATEDMOUSECLICK_DIALOG };

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
    afx_msg void OnBnClickedButtonStart();
};
