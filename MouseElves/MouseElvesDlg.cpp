
// MouseElvesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MouseElves.h"
#include "MouseElvesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseElvesDlg �Ի���



CMouseElvesDlg::CMouseElvesDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CMouseElvesDlg::IDD, pParent)
    , m_nLkey(0)
    , m_nClick(0)
    , m_nFrequency(0)
    , m_nPX(0)
    , m_nPX2(0)
    , m_nPY(0)
    , m_nPY2(0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseElvesDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_RDO_LKEY, m_nLkey);
    DDX_Radio(pDX, IDC_RDO_CLICK, m_nClick);
    DDX_Control(pDX, IDC_EDT_PX, m_editPX);
    DDX_Control(pDX, IDC_EDT_PY, m_editPY);
    DDX_Control(pDX, IDC_EDT_FREQUENCY, m_editFrequency);
    DDX_Control(pDX, IDC_EDT_PX2, m_editPX2);
    DDX_Control(pDX, IDC_EDT_PY2, m_editPY2);
    DDX_Text(pDX, IDC_EDT_FREQUENCY, m_nFrequency);
    DDX_Text(pDX, IDC_EDT_PX, m_nPX);
    DDX_Text(pDX, IDC_EDT_PX2, m_nPX2);
    DDX_Text(pDX, IDC_EDT_PY, m_nPY);
    DDX_Text(pDX, IDC_EDT_PY2, m_nPY2);
}

BEGIN_MESSAGE_MAP(CMouseElvesDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_START, &CMouseElvesDlg::OnBnClickedBtnStart)
    ON_BN_CLICKED(IDC_RDO_LKEY, &CMouseElvesDlg::OnBnClickedRdoLkey)
    ON_BN_CLICKED(IDC_RDO_CLICK, &CMouseElvesDlg::OnBnClickedRdoClick)
    ON_BN_CLICKED(IDC_RDO_RKEY, &CMouseElvesDlg::OnBnClickedRdoRkey)
    ON_BN_CLICKED(IDC_RDO_DOUBLE, &CMouseElvesDlg::OnBnClickedRdoDouble)
END_MESSAGE_MAP()


// CMouseElvesDlg ��Ϣ�������

BOOL CMouseElvesDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    // ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);         // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);        // ����Сͼ��
    // TODO:  �ڴ���Ӷ���ĳ�ʼ������
    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMouseElvesDlg::OnPaint()
{
    if(IsIconic())
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
HCURSOR CMouseElvesDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMouseElvesDlg::OnBnClickedRdoLkey()
{
    ((CButton *)GetDlgItem(IDC_RDO_DOUBLE))->EnableWindow(TRUE);
}

void CMouseElvesDlg::OnBnClickedRdoRkey()
{
    ((CButton *)GetDlgItem(IDC_RDO_CLICK))->SetCheck(TRUE);

    if(((CButton *)GetDlgItem(IDC_RDO_DOUBLE))->GetCheck())
    {
        ((CButton *)GetDlgItem(IDC_RDO_DOUBLE))->SetCheck(FALSE);
        ((CButton *)GetDlgItem(IDC_RDO_DOUBLE))->EnableWindow(FALSE);
    }
}

void CMouseElvesDlg::OnBnClickedRdoClick()
{
}

void CMouseElvesDlg::OnBnClickedRdoDouble()
{
}

void CMouseElvesDlg::OnBnClickedBtnStart()
{
    UpdateData(TRUE);

    if(((CButton *)GetDlgItem(IDC_RDO_LKEY))->GetCheck())
    {
        while(m_nFrequency--)
        {
            if(((CButton *)GetDlgItem(IDC_RDO_CLICK))->GetCheck())
            {
                SetCursorPos(m_nPX, m_nPY);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                SetCursorPos(m_nPX2, m_nPY2);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                AfxMessageBox(_T("1"));
            }
            else if(((CButton *)GetDlgItem(IDC_RDO_DOUBLE))->GetCheck())
            {
                SetCursorPos(m_nPX, m_nPY);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                SetCursorPos(m_nPX2, m_nPY2);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                AfxMessageBox(_T("1"));
            }
        }
    }
    else if(((CButton *)GetDlgItem(IDC_RDO_RKEY))->GetCheck())
    {
        while(m_nFrequency--)
        {
            if(((CButton *)GetDlgItem(IDC_RDO_CLICK))->GetCheck())
            {
                SetCursorPos(m_nPX, m_nPY);
                mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                SetCursorPos(m_nPX2, m_nPY2);
                mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                AfxMessageBox(_T("1"));
            }
        }
    }
}