#include "Genshin.h"

struct Info infos[] = {                                       //��ʼ��
					   {1  ,5  ,"*****","�����ҡ�"        },  //up����
					   {6  ,6  ,"*****","��Ī�ȡ�"        },
					   {7  ,7  ,"*****","�����ߡ�"        },
					   {8  ,8  ,"*****","����¬�ˡ�"      },
					   {9  ,9  ,"*****","�����硿"        },
					   {10 ,10 ,"*****","���١�"          },
					   {11 ,78 ,"***"  ,"��������"        },
					   {79 ,146,"***"  ,"��ѻ�𹭡�"      },
					   {147,214,"***"  ,"��������"    },
					   {215,282,"***"  ,"������Ӣ��̷��"  },
					   {283,350,"***"  ,"��ħ�����ۡ�"    },
					   {351,418,"***"  ,"����ӧǹ��"      },
					   {419,486,"***"  ,"����Ӱ������"    },
					   {487,554,"***"  ,"��������ˡ�"    },
					   {555,622,"***"  ,"����ԡ��Ѫ�Ľ���"},
					   {623,690,"***"  ,"������������"    },
					   {691,758,"***"  ,"�����С�"        },
					   {759,826,"***"  ,"�������񽣡�"    },
					   {827,892,"***"  ,"��������֮�ġ�"  },
					   {893,894,"****" ,"�����"        },
					   {895,901,"****" ,"���Ű�����"        },  //up����
					   {902,908,"****" ,"������"        },  //up����
					   {909,915,"****" ,"��ŵ������"      },  //up����
					   {916,917,"****" ,"�����֡�"        },
					   {918,919,"****" ,"���������ޡ�"    },
					   {920,921,"****" ,"�����ơ�"        },
					   {922,923,"****" ,"��������"        },
					   {924,925,"****" ,"�����⡿"        },
					   {926,927,"****" ,"����л����"      },
					   {928,929,"****" ,"�����⡿"        },
					   {930,931,"****" ,"����糡�"        },
					   {932,933,"****" ,"�����͡�"        },
					   {934,935,"****" ,"�������ء�"      },
					   {936,937,"****" ,"������"      },
					   {938,939,"****" ,"��ɰ�ǡ�"        },
					   {940,941,"****" ,"���ϰ��ȡ�"      },
					   {942,943,"****" ,"����ɯ���ǡ�"    },
					   {944,945,"****" ,"�����ء�"        },
					   {946,947,"****" ,"�����񹭡�"      },
					   {948,949,"****" ,"�����ҡ�"        },
					   {950,951,"****" ,"�������Թ���"    },
					   {952,953,"****" ,"�����ġ�"        },
					   {954,955,"****" ,"��������¡�"    },
					   {956,957,"****" ,"���������¡�"    },
					   {958,959,"****" ,"�������ص䡿"    },
					   {960,961,"****" ,"�����糤ǹ��"    },
					   {962,963,"****" ,"��ϻ���𳽡�"    },
					   {964,965,"****" ,"����á�"        },
					   {966,967,"****" ,"������󽣡�"    },
					   {968,969,"****" ,"���ӽ���"        },
					   {970,971,"****" ,"������󽣡�"    },
					   {972,973,"****" ,"��ϻ��������"    },
					   {974,975,"****" ,"�����񽣡�"      },
					   {976,977,"****" ,"���ѽ���"        },
					   {978,979,"****" ,"�����罣��"      },
					   {980,981,"****" ,"������֮ǹ��"    },
					   {982,983,"****" ,"���ڽ���"        },
					   {984,985,"****" ,"��ϻ�����¡�"    },
					   {986,987,"****" ,"���ǽ���"      },
					   {988,989,"****" ,"���Դ��Թ���"    },
};

int const info_len = sizeof(infos) / sizeof(*infos);      //��ȡ�ṹ�����ܳ���

int StrToNum(char* ch)      //���ַ����е�����תΪint��
{
	int len, num = 0, temp = 1;
	len = strlen(ch);
	for (int i = 0; i < len; i++)
	{
		num += temp * (ch[len - i - 1] - 48);
		temp *= 10;
	}
	return num;
}

void changetitle(const char* windowsname)
{
	HWND hand = GetHWnd();
	SetWindowText(hand, windowsname);
	int isok = MessageBox(hand, "��ӭ����ԭ��鿨ģ����", "Welcome", MB_OK);
	return;
}

void OutBackgroud()
{
	IMAGE img;
	loadimage(&img, "Bgr.jpg", 1400, 800, false);
	putimage(0, 0, &img);
	return;
}

void OutHeadline()
{
	setbkmode(TRANSPARENT);

	settextcolor(RED);
	settextstyle(80, 40, "����");
	outtextxy(780, 150, "���ſ�ʱ");

	settextcolor(LIGHTRED);
	settextstyle(20, 10, "����");
	outtextxy(780, 240, "����up���ǣ�����");
	outtextxy(780, 270, "����up���ǣ������Ű�����ŵ����");
	return;
}

void button(int tx, int ty, int bx, int by, const char* ch)      //����һ����ť
{
	settextstyle(33, 16, "����");
	setlinecolor(WHITE);
	setfillcolor(BROWN);
	setlinestyle(PS_SOLID, 5);
	roundrect(tx, ty, bx, by, 40, 40);
	fillroundrect(tx, ty, bx, by, 40, 40);
	int textx = tx + (bx - tx - textwidth(ch)) / 2;
	int texty = ty - (ty - by + textheight(ch)) / 2;
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(textx, texty, ch);
	return;
}

int GetSituation_1()
{
	int i;
	HWND hand = GetHWnd();
	SetWindowText(hand, "Enguiry");
	i = MessageBox(hand, "���������ڵ�״̬�ǣ�С�����밴�ǣ��󱣵��밴��", "Welcome", MB_YESNO);
	if (i == 6)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int GetSituation_2()
{
	char ch[11];
	int i;
	while (1)
	{
		InputBox(ch, 10, _T("���������˶��ٷ�����0~89��"));
		i = StrToNum(ch);
		if (i >= 0 && i < 90) 
		{
			return i;
		}
		else
		{
			HWND hand = GetHWnd();
			SetWindowText(hand, "Enquiry");
			MessageBox(hand, "����������������������", "Warning", MB_OK);
		}

	}
}

int GetPrimoNum()
{
	int i;
	char ch[11];
	while (1)
	{
		InputBox(ch, 10, _T("����������ԭʯ������������9λ���֣�"));
		i = StrToNum(ch);
		if (strlen(ch) < 9)
		{
			return i;
		}
		else
		{
			HWND hand = GetHWnd();
			SetWindowText(hand, "Enquiry");
			MessageBox(hand, _T("����������������������"), "Warning", MB_OK);
		}
	}
}

void Resume()      //����������
{
	button(600, 650, 800, 750, "����");
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x > 650 && msg.x < 750 && msg.y > 650 && msg.y < 750)
				{
					return;
				}
			}
		}
	}
}

void flash()      //�鿨��Ч
{
	int sleeptime=180;
	cleardevice();
	IMAGE img;
	for (int i = 1; i <= 24; i++)
	{

		char a[15] = "Lottery", b[5];
		sprintf(b, "%d" , i);
		strcat(a, b);
		strcat(a, ".jpg");
		Sleep(sleeptime);
		loadimage(&img, a, 1400, 800, false);
		putimage(0, 0, &img);
	}
}

void OutResult_1(int *p, int *q, int x)      //����
{
	cleardevice();
	settextstyle(40, 20, "����");
	settextcolor(WHITE);
	if ((*p) == 179)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(400, 300, infos[0].level);
		outtextxy(600, 300, infos[0].name);  //�󱣵�
		(*p) = 0;
		(*q) = 0;  //�ϡ��𱣵�����
	}

	else if ((*p) == 89)  //С����
	{
		int random_ex = 1 + rand() % 10;
		for (int i = 0; i < info_len; i++)
		{
			if (random_ex >= infos[i].m && random_ex <= infos[i].n)
			{
				settextcolor(RGB(255, 255, 0));
				outtextxy(400, 300, infos[i].level);
				outtextxy(600, 300, infos[i].name);
				if (i == 0)
				{
					(*p) = 0;
					(*q) = 0;  //С����û�ᣬ�ϡ��𱣵�����
				}
				else
				{
					(*p) = 90;
					(*q) = 0;  //С�����������ϱ�������
				}
			}
		}
	}

	else if ((*q) == 9)  //���ϱ���
	{
		int random_ey = 895 + rand() % 85;
		(*q) = 0;
		for (int i = 0; i < info_len; i++)
		{
			if (random_ey >= infos[i].m && random_ey <= infos[i].n)
			{
				settextcolor(RGB(153, 0, 255));
				outtextxy(400, 300, infos[i].level);
				outtextxy(600, 300, infos[i].name);
				(*q) = 0;
				(*p)++;
			}
		}
	}

	else if (((*p) <= 72 || (*p) >= 90) && (*q) < 9)  //�����鿨
	{
		int random = 1 + rand() % 979;
		for (int i = 0; i < info_len; i++)
		{
			if (random >= infos[i].m && random <= infos[i].n)
			{
				if (strlen(infos[i].level) == 3)
				{
					(*p)++;
					(*q)++;
					settextcolor(LIGHTCYAN);
				}  //����
				else if (strlen(infos[i].level) == 4)
				{
					(*p)++;
					(*q) = 0;
					settextcolor(RGB(153, 0, 255));
				}  //�����׳���
				else if (i == 0)
				{
					(*p) = 0;
					(*q) = 0;
					settextcolor(RGB(255, 255, 0));
				}  //�����׳�up
				else if (i > 0 && i <= 5)
				{
					(*p) = 90;
					(*q) = 0;
					settextcolor(RGB(255, 255, 0));
				}  //�����׳��𣬵�����
				outtextxy(400, 300, infos[i].level);
				outtextxy(600, 300, infos[i].name);
			}
		}
	}

	else if (((*p) > 72 || (*p) > 162) && (*q) != 9)  //72��֮�󣬳�������������
	{
		int random = 1 + rand() % 979;
			for (int i = 0; i < info_len; i++)
			{
				if (random >= infos[i].m && random <= infos[i].n)
				{
					if (strlen(infos[i].level) == 3) 
					{ 
						(*p)++; 
						(*q)++; 
						settextcolor(LIGHTCYAN); 
					}  //����
					else if (strlen(infos[i].level) == 4) 
					{ 
						(*p)++; 
						(*q) = 0; 
						settextcolor(RGB(153, 0, 255)); 
					}  //�����׳���
					else if (i == 0) 
					{ 
						(*p) = 0; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //�����׳�up
					else if (i > 0 && i <= 5) 
					{ 
						(*p) = 90; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //�����׳��𣬵�����
					outtextxy(400, 300, infos[i].level);
					outtextxy(600, 300, infos[i].name);
				}
			}
	}
	ShowRemain(p, x);
	Resume();
}

void OutResult_2(int *p, int *q, int x)      //ʮ��
{
	cleardevice();
	settextstyle(40, 20, "����");
	Sleep(500);
	srand((unsigned)time(NULL));
	for (int loop = 0; loop < 10; loop++)
	{
		Sleep(500);
		if ((*p) == 179)
		{
			settextcolor(RGB(255, 255, 0));
			outtextxy(400, 100 + 50 * loop, infos[0].level);
			outtextxy(600, 100 + 50 * loop, infos[0].name);  //�󱣵�
			(*p) = 0; 
			(*q) = 0;  //�ϡ��𱣵�����
		}
		else if ((*p) == 89)  //С����
		{
			int random_ex = 1 + rand() % 10;
			for (int i = 0; i < info_len; i++)
			{
				if (random_ex >= infos[i].m && random_ex <= infos[i].n)
				{
					settextcolor(RGB(255, 255, 0));
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
					if (i == 0)
					{
						(*p) = 0; 
						(*q) = 0;  //С����û�ᣬ�ϡ��𱣵�����
					}
					else
					{
						(*p) = 90; 
						(*q) = 0;  //С�����������ϱ�������
					}
				}
			}
		}
		else if ((*q) == 9)  //���ϱ���
		{
			int random_ey = 895 + rand() % 85;
			(*q) = 0;
			for (int i = 0; i < info_len; i++)
			{
				if (random_ey >= infos[i].m && random_ey <= infos[i].n)
				{
					settextcolor(RGB(153, 0, 255));
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
					(*q) = 0; 
					(*p)++;
				}
			}
		}
		else if (((*p) <= 72 || (*p) >= 90) && (*q) < 9)  //�����鿨
		{
			int random = 1 + rand() % 979;
			for (int i = 0; i < info_len; i++)
			{
				if (random >= infos[i].m && random <= infos[i].n)
				{
					if (strlen(infos[i].level) == 3) 
					{ 
						(*p)++; 
						(*q)++; 
						settextcolor(LIGHTCYAN); 
					}  //����
					else if (strlen(infos[i].level) == 4) 
					{ 
						(*p)++; 
						(*q) = 0; 
						settextcolor(RGB(153, 0, 255)); 
					}  //�����׳���
					else if (i == 0) 
					{ 
						(*p) = 0; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //�����׳�up
					else if (i > 0 && i <= 5) 
					{ 
						(*p) = 90; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //�����׳��𣬵�����
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
				}
			}
		}
		else if (((*p) > 72 || (*p) > 162) && (*q) != 9)  //72��֮�󣬳�������������
		{
			int random_ez = 1 + rand() % (989 - ((*p) - 70) * 49);
			for (int i = 0; i < info_len; i++)
			{
				if (random_ez >= infos[i].m && random_ez <= infos[i].n)
				{
					if (strlen(infos[i].level) == 3)
					{
						(*p)++;
						(*q)++;
						settextcolor(LIGHTCYAN);
					}  //����
					else if (strlen(infos[i].level) == 4)
					{
						(*p)++;
						(*q) = 0;
						settextcolor(RGB(153, 0, 255));
					}  //�����׳���
					else if (i == 0)
					{
						(*p) = 0;
						(*q) = 0;
						settextcolor(RGB(153, 0, 255));
					}  //�����׳�up
					else if (i > 0 && i <= 5)
					{
						(*p) = 90;
						(*q) = 0;
						settextcolor(RGB(255, 255, 0));
					}
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
					  //�����׳��𣬵�����
				}
			}
		}
	}
		ShowRemain(p, x);
		Resume();
}

void ShowRemain(const int *p, int x)  
{
	char ch[3][10];
	sprintf(ch[0], "%d", ((*p)%90));
	sprintf(ch[1], "%d", (180-(*p)));
	sprintf(ch[2], "%d", x);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(24, 12, "����");
	outtextxy(1130, 680, "δ����Ĵ�����");
	outtextxy(1130, 700, "��󱣵׳�����");
	outtextxy(1130, 720, "ʣ��ԭʯ������");
	outtextxy(1300, 680, ch[0]);
	outtextxy(1300, 700, ch[1]);
	outtextxy(1300, 720, ch[2]);
	return;
}