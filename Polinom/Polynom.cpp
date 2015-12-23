// Polinom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TPolynom.h"
//#include "THeadList.h"
//#include "TLink.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	TLink<int> a;
	THeadList<int> b;
	TPolynom p1;
	p1.InsPoly_v1();
	p1.OutPoly_v1();
	return 0;
}

