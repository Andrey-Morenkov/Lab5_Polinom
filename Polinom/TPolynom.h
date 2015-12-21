#include "THeadList.h"
#include <string>
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

	void StrToPoly(const string& str);
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
}

TPolynom operator + (TPolynom & p1,TPolynom & p2)
{
	TPolynom p(p1);
	p += p2;
	return p;
}


void TPolynom::StrToPoly(const string& str)
{

}