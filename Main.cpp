#include "Genshin.h"

int main()
{
	initgraph(1400, 800);       //EW_SHOWCONSOLE
	OutBackgroud();        //显示背景
	OutHeadline();        //显示标题
	button(865, 700, 1050, 800, "祈愿一次");      //显示按钮
	button(1065, 700, 1250, 800, "祈愿十次");
	changetitle("Genshin Lottery Simulator");
	int primogem, situ, pre;
	int a = 0, b = 0;       //a为截至目前为出金的次数，b为截至目前未出紫的次数
	int* p = &a, * q = &b;
	situ = GetSituation_1();      //获取保底状态
	pre = GetSituation_2();
	if (situ == 1) { (*p) = pre + 90; }
	else if(situ == 2) { (*p) = pre; }
	primogem = GetPrimoNum();      //获取原石数量
	Sleep(1000);
	ExMessage msg;
	while (primogem >= 160)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x > 865 && msg.x < 1050 && msg.y > 700 && msg.y < 800)
				{
					if (primogem >= 160)
					{
						primogem-= 160;
						flash();
						OutResult_1(p, q, primogem);
					}
					else if (primogem < 160) {  }
					OutBackgroud();
					OutHeadline();
					button(865, 700, 1050, 800, "祈愿一次");
					button(1065, 700, 1250, 800, "祈愿十次");
				}
				if (msg.x > 1065 && msg.x < 1250 && msg.y > 700 && msg.y < 800)
				{
					if (primogem >= 1600)
					{
						primogem -= 1600;
						flash();
						OutResult_2(p, q, primogem);
					}
					else if (primogem < 1600) 
					{
						HWND hand = GetHWnd();
						SetWindowText(hand, "Warning");
						MessageBox(hand, "原石数量不足", "Warning", MB_OK);
					}
					OutBackgroud();
					OutHeadline();
					button(865, 700, 1050, 800, "祈愿一次");
					button(1065, 700, 1250, 800, "祈愿十次");
				}
			}
		}
	}
	HWND hand = GetHWnd();
	SetWindowText(hand, "Warning");
	MessageBox(hand, "原石数量不足", "Warning", MB_OK);
	MessageBox(hand, "感谢您的使用，下次再见", "Farewell", MB_OK);
	closegraph();
	return 0;
}



