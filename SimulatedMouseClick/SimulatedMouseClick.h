
// SimulatedMouseClick.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSimulatedMouseClickApp:
// �йش����ʵ�֣������ SimulatedMouseClick.cpp
//

class CSimulatedMouseClickApp : public CWinApp
{
public:
    CSimulatedMouseClickApp();

// ��д
public:
    virtual BOOL InitInstance();

// ʵ��

    DECLARE_MESSAGE_MAP()
};

extern CSimulatedMouseClickApp theApp;