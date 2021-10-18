#ifndef Prep
#define Prep

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <easyx.h>
#include <stdio.h>

using namespace std;

struct Info
{
    int m;
    int n;
    char level[10];
    char name[20];
};

void flash();
int StrToNum(char* ch);
void changetitle(const char* windowsname);
void OutBackgroud();
void OutHeadline();
void button(int tx, int ty, int bx, int by, const char* ch);
int GetSituation_1();
int GetSituation_2();
int GetPrimoNum();
void Resume();
void OutResult_1(int *p, int *q, int x);
void OutResult_2(int* p, int* q, int x);
void ShowRemain(const int* p, int x);

#endif // Prep