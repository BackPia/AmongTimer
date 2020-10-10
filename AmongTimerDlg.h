
// AmongTimerDlg.h: 헤더 파일
//

#pragma once


// CAmongTimerDlg 대화 상자
class CAmongTimerDlg : public CDialogEx
{
// 생성입니다.
public:
	CAmongTimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AMONGTIMER_DIALOG };
#endif

private:
	int SideTimer;
	BOOL SideTimerPause;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtStart();
	afx_msg void OnBnClickedBtTimer();
	afx_msg void OnBnClickedBtTimerTime();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int SetSideTimer(int Time);
	int GetSideTimer(void);
	BOOL SetSideTimerPause(BOOL check);
	BOOL GetSideTimerPause(void);
	CButton mBT_Timer_time;
};
