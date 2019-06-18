
// MouseElvesDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MouseElves.h"
#include "MouseElvesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseElvesDlg 对话框



CMouseElvesDlg::CMouseElvesDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CMouseElvesDlg::IDD, pParent)
    , m_nLkey(0)
    , m_nClick(0)
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


// CMouseElvesDlg 消息处理程序

BOOL CMouseElvesDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);         // 设置大图标
    SetIcon(m_hIcon, FALSE);        // 设置小图标
    // TODO:  在此添加额外的初始化代码
    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMouseElvesDlg::OnPaint()
{
    if(IsIconic())
    {
        CPaintDC dc(this); // 用于绘制的设备上下文
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;
        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMouseElvesDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMouseElvesDlg::OnBnClickedRdoLkey()
{
}

void CMouseElvesDlg::OnBnClickedRdoRkey()
{
}

void CMouseElvesDlg::OnBnClickedRdoClick()
{
}

void CMouseElvesDlg::OnBnClickedRdoDouble()
{
}

void CMouseElvesDlg::OnBnClickedBtnStart()
{
    //CPoint point;
    //GetCursorPos(&point);
    //int i = 3;
    //while(i--)
    //{
    //    SetCursorPos(440, 255);
    //    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    //    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    //    SetCursorPos(502, 238);
    //    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    //    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    //}
    CString t_szFrequency;
    m_editFrequency.GetWindowText(t_szFrequency);
    AfxMessageBox(t_szFrequency);
    t_szFrequency.ReleaseBuffer();
}