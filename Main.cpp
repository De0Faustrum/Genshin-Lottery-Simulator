#include "Genshin.h"

int main()
{
	initgraph(1400, 800);       //EW_SHOWCONSOLE
	OutBackgroud();        //��ʾ����
	OutHeadline();        //��ʾ����
	button(865, 700, 1050, 800, "��Ըһ��");      //��ʾ��ť
	button(1065, 700, 1250, 800, "��Ըʮ��");
	changetitle("Genshin Lottery Simulator");
	int primogem, situ, pre;
	int a = 0, b = 0;       //aΪ����ĿǰΪ����Ĵ�����bΪ����Ŀǰδ���ϵĴ���
	int* p = &a, * q = &b;
	situ = GetSituation_1();      //��ȡ����״̬
	pre = GetSituation_2();
	if (situ == 1) { (*p) = pre + 90; }
	else if(situ == 2) { (*p) = pre; }
	primogem = GetPrimoNum();      //��ȡԭʯ����
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
					button(865, 700, 1050, 800, "��Ըһ��");
					button(1065, 700, 1250, 800, "��Ըʮ��");
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
						MessageBox(hand, "ԭʯ��������", "Warning", MB_OK);
					}
					OutBackgroud();
					OutHeadline();
					button(865, 700, 1050, 800, "��Ըһ��");
					button(1065, 700, 1250, 800, "��Ըʮ��");
				}
			}
		}
	}
	HWND hand = GetHWnd();
	SetWindowText(hand, "Warning");
	MessageBox(hand, "ԭʯ��������", "Warning", MB_OK);
	MessageBox(hand, "��л����ʹ�ã��´��ټ�", "Farewell", MB_OK);
	closegraph();
	return 0;
}



