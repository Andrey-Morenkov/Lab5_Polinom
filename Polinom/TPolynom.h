#include "THeadList.h"
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

struct Monom
{
	int type;
	int coeff;

	Monom()
	{
		type = -1;
		coeff = 0;
	}

	Monom(int t, int c) : type(t), coeff(c) {}
};

class TPolynom : public THeadList<Monom>
{
public:
	TPolynom() {}
	TPolynom(const Monom& m);

	TPolynom & operator +=(TPolynom & p);

	void InsPoly_v1();
	void OutPoly_v1();
};

TPolynom & TPolynom::operator += (TPolynom & p)   // прибавление полинома к текущему
{
	Reset();
	p.Reset();
	while (!IsEnd() && !p.IsEnd())
	{
		if (pCurr->GetVal().type > p.pCurr->GetVal().type)
			GoNext();
		else 
		    if (pCurr->GetVal().type < p.pCurr->GetVal().type)
		    {
			    InsCurrent(p.pCurr->GetVal());
				p.GoNext();
		    }
			else
			{
				pCurr->GetVal().coeff += p.pCurr->GetVal().coeff;
				if (pCurr->GetVal().coeff == 0)
					DelCurrent();
			}
	}
	while (!p.IsEnd())
	{
		InsLast(p.pCurr->GetVal());
		p.GoNext();
	}
	return *this;
}

TPolynom operator + (TPolynom & p1,TPolynom & p2)
{
	TPolynom p(p1);
	p += p2;
	return p;
}


void TPolynom::InsPoly_v1()
{
	Monom monom;
	char tmp1=NULL;
	while (tmp1 != 'x')
	{
		cout << "Введи коэфф" << endl;
		cin >> monom.coeff;
		cout << "Введи тип звена" << endl;
		cin >> monom.type;
		InsLast(monom);
		cout << "Введи x для завершения" << endl;
		cin >> tmp1;
	}
}

void TPolynom::OutPoly_v1()
{
	int len1 = len;
	Reset();
	while (len1 != 0)
	{
		cout << "Type: " << pCurr->GetVal().type << endl;
		cout << "Coeff: " << pCurr->GetVal().coeff << endl;
		cout << "---" << endl;
		pCurr = pCurr->pNext;
		len1--;
	}
}