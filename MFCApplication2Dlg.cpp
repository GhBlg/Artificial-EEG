
// MFCApplication2Dlg.cpp : fichier d'implémentation
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue de CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// gestionnaires de messages de CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButton1()
{
	CClientDC dc(this);
	double u11, u22, u100, u200;	double u2, v2, v1, v11, v22, u1, u10, u20;
	double yn2, yn1, yn0;	double xn2, xn1, xn0;
	double dt, alp;	long i, m;
	double p, u, v;
	double p1, p2, p3, q1, q2, q3;
	m = 1;	alp = 0.2;
	u1 = u10 = 0.1; u22 = u20 = 0.5;
	xn1 = sin(2 * 3.14 * 1); xn0 = 0;
	yn1 = sin(2 * 3.14 * 18); yn0 = 4; yn2 = 4;
	for (i = 1; i < 210000; i++)
	{

		xn2 = 2 * cos(2 * 3.14 * 223 / 17) * xn1 - xn0;
		yn2 = 2 * cos(2 * 3.14 * 223 / 17) * yn1 - yn0;
		//u11 = 0.25; u22= -0.5;
		u11 = 1.005 * yn2; u22 = 1.005 * xn2;
		v11 = 1.005 * yn2; v22 = 1.005 * xn2;
	



		
		p1 =1; 
		q1 = p1;
	
	
		u11 = u11 + alp * (-(u11 + p1) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1) , 2)));
		u22 = u22 + alp * (-1.6 * u22 - 1.6 * 9 * 25 * pow((u11 + q1), 2) * exp(-25 * pow((u11 + p1) , 2)));


		
		
		

		
		dc.SetPixel(450 + u11 * 115, 450 + u22 * 115, RGB(255, 0, 0));
		//	dc.SetPixel(550 + v11 * 152, 450 + v22 *152, RGB(0, 0,0));
		//	dc.SetPixel(550 + u11 * 252, 450 + v22 * 252, RGB(255, 0,0));
		yn0 = yn1;	yn1 = yn2;	xn0 = xn1;	xn1 = xn2;	m = -m;
		u10 = u11; u20 = u22;
	}

}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	CClientDC dc(this);
	double u11, u22, u100, u200;	double u2, v2, v1, v11, v22, u1, u10, u20;
	double yn2, yn1, yn0;	double xn2, xn1, xn0;
	double dt, alp;	long i, m;
	double p, u, v;
	double p1, p2, p3, q1, q2, q3;
	m = 1;	alp = 0.2;
	u1 = u10 = 0.1; u22 = u20 = 0.5;
	xn1 = sin(2 * 3.14 * 1); xn0 = 0;
	yn1 = sin(2 * 3.14 * 18); yn0 = 4; yn2 = 4;
	for (i = 1; i < 210000; i++)
	{

		xn2 = 2 * cos(2 * 3.14 * 223 / 17) * xn1 - xn0;
		yn2 = 2 * cos(2 * 3.14 * 223 / 17) * yn1 - yn0;
		//u11 = 0.25; u22= -0.5;
		u11 = 1.005 * yn2; u22 = 1.005 * xn2;
		v11 = 1.005 * yn2; v22 = 1.005 * xn2;

		p1 = 1; p2 = -1;
		q1 = p1;
		q2 = +p2;

		u11 = u11 + alp * (-(u11 + p1) / 1.5 + 9 * 25 * u22 * (u11 + p1) * (u11 + p2) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1) * (u11 + p2), 2)));
		u22 = u22 + alp * (-1.6 * u22 - 1.6 * 9 * 25 * pow((u11 + q1), 2) * pow((u11 + q2), 2) * exp(-25 * pow((u11 + p2) * (u11 + p1), 2)));








	//+pow((u22-1) , 2)
		dc.SetPixel(450 + u11 * 115, 250 + u22 * 115, RGB(255, 0, 0));
		//	dc.SetPixel(550 + v11 * 152, 450 + v22 *152, RGB(0, 0,0));
		//	dc.SetPixel(550 + u11 * 252, 450 + v22 * 252, RGB(255, 0,0));
		yn0 = yn1;	yn1 = yn2;	xn0 = xn1;	xn1 = xn2;	m = -m;
		u10 = u11; u20 = u22;
	}
}


void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	CClientDC dc(this);
	double u11, v11, v22, w11, u10, v10, w22, w10;

	double yn2, yn1, yn0, u22, u20;
	double xn2, xn1, xn0;
	double zn2, zn1, zn0;
	double x2, x3, x10, x20, x30;
	double p1, p2, p3, p4, p5, p6, p7;
	double q11, q22, q33, q44, q55, q66, q77;
	double alp, i, s;
	double F, j, u0, v0, u1, v1, xk, yk, zk, x0, x1;
	double b, a, y0, y1, dt;
	double  xn, yn, xg, yg, xc, yc;
	dt = 0.002;
	alp = 0.2;
	xg = yg = 0;
	zn1 = sin(2 * 3.14 * 1); zn0 = 0;

	u11 = u10 = 1; u22 = u20 = 5;
	xc = -1.5; yc = 1;
	x1 = x10 = -0.2; x2 = x20 = 0.2;	x3 = x30 = -1.2;
	b = a = 0;
	//for (p2 = -5;p2 <5;p2=p2+0.75)
	xn1 = sin(2 * 3.14 * 1); xn0 = 0;
	yn1 = sin(2 * 3.14 * 12); yn0 = 9;
	v11 = v22 = 0;
	//{
	for (i = 1; i < 510000; i++)
	{

		xn2 = 2 * cos(2 * 3.14 * 3144) * xn1 - xn0;
		yn2 = 2 * cos(2 * 3.14 * 3144) * yn1 - yn0;
		zn2 = 2 * cos(2 * 3.14 * 61) * zn1 - zn0;
		u11 = 2 * yn2;
		u22 = 2 * xn2;
		v11 = 2 * yn2;
		v22 = 2 * xn2;
		/*if (x1 > 1) { F = 10; }
		if ((x1 > -1) && (x1 < 1)) { F = 10 * x1; }
		if (x1 < 1) { F = -10; }

		x1 = x10 + dt * alp * (x2);
		x2 = x20 + dt * alp * (x3);//y1*y3);
		x3 = x30 + dt * alp * (-0.7 * x1 - 0.7 * x2 - 0.7 * x3 + 0.7 * F);

		*/
		if ((yn2 > 4) && (yn2 < 8)) { a = 2 * yn2; }
		if ((yn2 > 8) && (yn2 < 12)) { b = 2 * yn2; }
	//	FONCT(xc + 1, yc, sqrt, sqrt, 0.125);
		//a = 5;
		s = 0.015;
		p1 = -1;		q11 = -s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22 - 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 /= 1.6;

		p1 = -2;		  q11 = s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22+ 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 *= 1.6;


		p1 = -3.25;		  q11 = -s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22 - 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 /= 1.6;

		p1 = 0;		q11 = +p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22 + 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 *= 1.6;
	
		p1 = 1.;		q11 = s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22 - 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));

		u22 /= 1.6;

		p1 = 1.75;		  q11 = -s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (u22 - 1.6 * 9 * 25 * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 *= 1.6;

		p1 = 2.75;		  q11 = s + p1;

		u11 = u11 + alp * (-(u11) / 1.5 + 9 * 25 * u22 * (u11 + p1) * exp(-25 * u22 * u22 / 2) * exp(-25 * pow((u11 + p1), 2)));
		u22 = u22 + alp * (-u22 + 1.6 * 9 * 25 * sin(u11 * 2 * 3.14 * 5) * pow((u11 + q11), 2) * exp(-25 * pow((u11 + p1), 2)));



		s = 0.0175;
		p1 = -0.95;		q11 = -s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 - 1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 /= 1.6;

		p1 = -1.9;		  q11 = s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 + 1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 *= 1.6;

		p1 = -2.75;		  q11 = -s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 + 1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 *= 1.6;

		p1 = 0;		q11 = +p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 - 1.6 * 9 * sin(u11 * 2 * 3.14 * 8) * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 *= 1.6;


		p1 = 0.95;		q11 = s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 - 1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));

		v22 *= 1.6;
		p1 = 0; p2 = 2; p3 = -2;
		q11 = p1;
		q22 = +p2;
		q33 = +p3;
		v11 = v11 + alp * (-(v11 + p1) / 1.5 + 9 * 25 * v22 * (v11 + p1) * (v11 + p2) * (v11 + p3) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1) * (v11 + p2) * (v11 + p3), 2)));
		v22 = v22 + alp * (-1.6 * v22 - 1.6 * 9 * 25 * pow((v11 * sin(v11 * 2 * 3.14 * 3) + q11), 5) * pow((v11 * sin(v11 * 2 * 3.14 * 2) + q33), 2) * pow((v11 * sin(v11 * 2 * 3.14 * 1) + q22), 2) * exp(-25 * pow((v11 + p2) * (v11 + p1) * (v11 + p3), 2)));


		p1 = 1.8;		  q11 = -s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (v22 +1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 /= 1.6;
		p1 = 2.75;		  q11 = s + p1;

		v11 = v11 + alp * (-(v11) / 1.5 + 9 * 25 * v22 * (v11 + p1) * exp(-25 * v22 * v22 / 2) * exp(-25 * pow((v11 + p1), 2)));
		v22 = v22 + alp * (-v22 - 1.6 * 9 * 25 * pow((v11 + q11), 2) * exp(-25 * pow((v11 + p1), 2)));



		w11 = u22;
		w22 = v22;


		dc.SetPixel(550 + u11 *90, 350 + u22 *90, RGB(255, 0, 0));
		yn0 = yn1;	yn1 = yn2;
		xn0 = xn1;	xn1 = xn2;
		zn0 = zn1;	zn1 = zn2;
		//	u20 = u22;	u10 = u11;
		xc = xg; yc = yg;
		x10 = x1;	x20 = x2;	x30 = x3;

		//}


	}

	
}
