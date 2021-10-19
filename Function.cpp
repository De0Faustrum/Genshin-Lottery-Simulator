#include "Genshin.h"

struct Info infos[] = {                                       //初始化
					   {1  ,5  ,"*****","【胡桃】"        },  //up五星
					   {6  ,6  ,"*****","【莫娜】"        },
					   {7  ,7  ,"*****","【七七】"        },
					   {8  ,8  ,"*****","【迪卢克】"      },
					   {9  ,9  ,"*****","【刻晴】"        },
					   {10 ,10 ,"*****","【琴】"          },
					   {11 ,78 ,"***"  ,"【弹弓】"        },
					   {79 ,146,"***"  ,"【鸦羽弓】"      },
					   {147,214,"***"  ,"【翡玉法球】"    },
					   {215,282,"***"  ,"【讨龙英杰谭】"  },
					   {283,350,"***"  ,"【魔导绪论】"    },
					   {351,418,"***"  ,"【黑缨枪】"      },
					   {419,486,"***"  ,"【铁影阔剑】"    },
					   {487,554,"***"  ,"【以理服人】"    },
					   {555,622,"***"  ,"【沐浴龙血的剑】"},
					   {623,690,"***"  ,"【飞天御剑】"    },
					   {691,758,"***"  ,"【冷刃】"        },
					   {759,826,"***"  ,"【黎明神剑】"    },
					   {827,892,"***"  ,"【神射手之誓】"  },
					   {893,894,"****" ,"【行秋】"        },
					   {895,901,"****" ,"【芭芭拉】"        },  //up四星
					   {902,908,"****" ,"【托马】"        },  //up四星
					   {909,915,"****" ,"【诺艾尔】"      },  //up四星
					   {916,917,"****" ,"【早柚】"        },
					   {918,919,"****" ,"【九条裟罗】"    },
					   {920,921,"****" ,"【重云】"        },
					   {922,923,"****" ,"【北斗】"        },
					   {924,925,"****" ,"【香菱】"        },
					   {926,927,"****" ,"【菲谢尔】"      },
					   {928,929,"****" ,"【凝光】"        },
					   {930,931,"****" ,"【烟绯】"        },
					   {932,933,"****" ,"【辛焱】"        },
					   {934,935,"****" ,"【班尼特】"      },
					   {936,937,"****" ,"【雷泽】"      },
					   {938,939,"****" ,"【砂糖】"        },
					   {940,941,"****" ,"【迪奥娜】"      },
					   {942,943,"****" ,"【罗莎莉亚】"    },
					   {944,945,"****" ,"【弓藏】"        },
					   {946,947,"****" ,"【祭礼弓】"      },
					   {948,949,"****" ,"【绝弦】"        },
					   {950,951,"****" ,"【西风猎弓】"    },
					   {952,953,"****" ,"【昭心】"        },
					   {954,955,"****" ,"【祭礼残章】"    },
					   {956,957,"****" ,"【流浪乐章】"    },
					   {958,959,"****" ,"【西风秘典】"    },
					   {960,961,"****" ,"【西风长枪】"    },
					   {962,963,"****" ,"【匣里灭辰】"    },
					   {964,965,"****" ,"【雨裁】"        },
					   {966,967,"****" ,"【祭礼大剑】"    },
					   {968,969,"****" ,"【钟剑】"        },
					   {970,971,"****" ,"【西风大剑】"    },
					   {972,973,"****" ,"【匣里龙吟】"    },
					   {974,975,"****" ,"【祭礼剑】"      },
					   {976,977,"****" ,"【笛剑】"        },
					   {978,979,"****" ,"【西风剑】"      },
					   {980,981,"****" ,"【决斗之枪】"    },
					   {982,983,"****" ,"【黑剑】"        },
					   {984,985,"****" ,"【匣里日月】"    },
					   {986,987,"****" ,"【螭骨剑】"      },
					   {988,989,"****" ,"【苍翠猎弓】"    },
};

int const info_len = sizeof(infos) / sizeof(*infos);      //获取结构数组总长度

int StrToNum(char* ch)      //将字符串中的数字转为int型
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
	int isok = MessageBox(hand, "欢迎来到原神抽卡模拟器", "Welcome", MB_OK);
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
	settextstyle(80, 40, "楷体");
	outtextxy(780, 150, "赤团开时");

	settextcolor(LIGHTRED);
	settextstyle(20, 10, "楷体");
	outtextxy(780, 240, "本期up五星：胡桃");
	outtextxy(780, 270, "本期up四星：托马、芭芭拉、诺艾尔");
	return;
}

void button(int tx, int ty, int bx, int by, const char* ch)      //创建一个按钮
{
	settextstyle(33, 16, "仿宋");
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
	i = MessageBox(hand, "请问您现在的状态是：小保底请按是，大保底请按否", "Welcome", MB_YESNO);
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
		InputBox(ch, 10, _T("请问您垫了多少发？（0~89）"));
		i = StrToNum(ch);
		if (i >= 0 && i < 90) 
		{
			return i;
		}
		else
		{
			HWND hand = GetHWnd();
			SetWindowText(hand, "Enquiry");
			MessageBox(hand, "您的输入有误，请重新输入", "Warning", MB_OK);
		}

	}
}

int GetPrimoNum()
{
	int i;
	char ch[11];
	while (1)
	{
		InputBox(ch, 10, _T("请输入您的原石数量（不超过9位数字）"));
		i = StrToNum(ch);
		if (strlen(ch) < 9)
		{
			return i;
		}
		else
		{
			HWND hand = GetHWnd();
			SetWindowText(hand, "Enquiry");
			MessageBox(hand, _T("您的输入有误，请重新输入"), "Warning", MB_OK);
		}
	}
}

void Resume()      //返回主界面
{
	button(600, 650, 800, 750, "返回");
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

void flash()      //抽卡特效
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

void OutResult_1(int *p, int *q, int x)      //单抽
{
	cleardevice();
	settextstyle(40, 20, "楷体");
	settextcolor(WHITE);
	if ((*p) == 179)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(400, 300, infos[0].level);
		outtextxy(600, 300, infos[0].name);  //大保底
		(*p) = 0;
		(*q) = 0;  //紫、金保底重置
	}

	else if ((*p) == 89)  //小保底
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
					(*q) = 0;  //小保底没歪，紫、金保底重置
				}
				else
				{
					(*p) = 90;
					(*q) = 0;  //小保底歪哩，紫保底重置
				}
			}
		}
	}

	else if ((*q) == 9)  //出紫保底
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

	else if (((*p) <= 72 || (*p) >= 90) && (*q) < 9)  //正常抽卡
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
				}  //出蓝
				else if (strlen(infos[i].level) == 4)
				{
					(*p)++;
					(*q) = 0;
					settextcolor(RGB(153, 0, 255));
				}  //不保底出紫
				else if (i == 0)
				{
					(*p) = 0;
					(*q) = 0;
					settextcolor(RGB(255, 255, 0));
				}  //不保底出up
				else if (i > 0 && i <= 5)
				{
					(*p) = 90;
					(*q) = 0;
					settextcolor(RGB(255, 255, 0));
				}  //不保底出金，但歪了
				outtextxy(400, 300, infos[i].level);
				outtextxy(600, 300, infos[i].name);
			}
		}
	}

	else if (((*p) > 72 || (*p) > 162) && (*q) != 9)  //72发之后，出金概率显著提高
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
					}  //出蓝
					else if (strlen(infos[i].level) == 4) 
					{ 
						(*p)++; 
						(*q) = 0; 
						settextcolor(RGB(153, 0, 255)); 
					}  //不保底出紫
					else if (i == 0) 
					{ 
						(*p) = 0; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //不保底出up
					else if (i > 0 && i <= 5) 
					{ 
						(*p) = 90; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //不保底出金，但歪了
					outtextxy(400, 300, infos[i].level);
					outtextxy(600, 300, infos[i].name);
				}
			}
	}
	ShowRemain(p, x);
	Resume();
}

void OutResult_2(int *p, int *q, int x)      //十连
{
	cleardevice();
	settextstyle(40, 20, "楷体");
	Sleep(500);
	srand((unsigned)time(NULL));
	for (int loop = 0; loop < 10; loop++)
	{
		Sleep(500);
		if ((*p) == 179)
		{
			settextcolor(RGB(255, 255, 0));
			outtextxy(400, 100 + 50 * loop, infos[0].level);
			outtextxy(600, 100 + 50 * loop, infos[0].name);  //大保底
			(*p) = 0; 
			(*q) = 0;  //紫、金保底重置
		}
		else if ((*p) == 89)  //小保底
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
						(*q) = 0;  //小保底没歪，紫、金保底重置
					}
					else
					{
						(*p) = 90; 
						(*q) = 0;  //小保底歪哩，紫保底重置
					}
				}
			}
		}
		else if ((*q) == 9)  //出紫保底
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
		else if (((*p) <= 72 || (*p) >= 90) && (*q) < 9)  //正常抽卡
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
					}  //出蓝
					else if (strlen(infos[i].level) == 4) 
					{ 
						(*p)++; 
						(*q) = 0; 
						settextcolor(RGB(153, 0, 255)); 
					}  //不保底出紫
					else if (i == 0) 
					{ 
						(*p) = 0; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //不保底出up
					else if (i > 0 && i <= 5) 
					{ 
						(*p) = 90; 
						(*q) = 0; 
						settextcolor(RGB(255, 255, 0));
					}  //不保底出金，但歪了
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
				}
			}
		}
		else if (((*p) > 72 || (*p) > 162) && (*q) != 9)  //72发之后，出金概率显著提高
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
					}  //出蓝
					else if (strlen(infos[i].level) == 4)
					{
						(*p)++;
						(*q) = 0;
						settextcolor(RGB(153, 0, 255));
					}  //不保底出紫
					else if (i == 0)
					{
						(*p) = 0;
						(*q) = 0;
						settextcolor(RGB(153, 0, 255));
					}  //不保底出up
					else if (i > 0 && i <= 5)
					{
						(*p) = 90;
						(*q) = 0;
						settextcolor(RGB(255, 255, 0));
					}
					outtextxy(400, 100 + 50 * loop, infos[i].level);
					outtextxy(600, 100 + 50 * loop, infos[i].name);
					  //不保底出金，但歪了
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
	settextstyle(24, 12, "楷体");
	outtextxy(1130, 680, "未出金的次数：");
	outtextxy(1130, 700, "离大保底抽数：");
	outtextxy(1130, 720, "剩余原石数量：");
	outtextxy(1300, 680, ch[0]);
	outtextxy(1300, 700, ch[1]);
	outtextxy(1300, 720, ch[2]);
	return;
}