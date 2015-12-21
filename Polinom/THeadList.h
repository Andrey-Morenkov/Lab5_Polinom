#include "TLink.h"

template <class T>
class THeadList
{
protected:
	TLink<T>* pHead;                // ��������� �� ������
	TLink<T>* pFirst;               // ��������� �� ������
	TLink<T>* pLast;                // ��������� �� ���������
	TLink<T>* pPred;                // ��������� �� ����������
	TLink<T>* pCurr;        // ��������� �� ��������
	TLink<T>* pStop;                // ��������� ���������� �� ������
	int pos;                // ������� �������� ��������
	int len;                        // ����� ������

public:
	THeadList();
	THeadList(const THeadList& hl);
	~THeadList();

	THeadList& operator=(const THeadList &hl);

	void InsFirst(const T& elem);    // �������� ������ �������
	void InsCurrent(const T& elem);  // �������� ������� �������
	void InsLast(const T& elem);     // �������� ��������� �������
	void DelFirst();                 // ������� ������ �������
	void DelCurrent();               // ������� ������� �������

	void Reset();                    // ���������� pCurr �� ������ �������
	void GoNext();                   // ������� �� ��������� �������
	bool IsEnd();                    // ����� ������?

};

template <class T>
THeadList<T>::THeadList()
{
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pStop;
	pFirst = pLast = pCurr = pPred = NULL;
	pos = -1;
	len = 0;
}

template <class T>
THeadList<T>::~THeadList()
{
	TLink<T>* tmp;
	if (pFirst != NULL)
	{
		pCurr = pFirst;
		while (len != 0)
		{
			pPred = pCurr;
			pCurr = pCurr->pNext;
			delete pPred;
			len--;
		}
	}
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(const T& elem)
{
	TLink<T>* tmp = new TLink<T>(elem);
	//tmp->Val = elem;
	pHead->pNext = tmp;
	if (len == 0)
	{
		tmp->pNext = pStop;
		pFirst = pLast = tmp;
	}
	else
	{
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	len++;
	pos++;
}

template <class T>
void THeadList<T>::DelFirst()
{
	if (len != 0)
	{
		if (pCurr != pFirst)
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			len--;
			pos--;
		}
		else
		{
			DelCurrent();
		}
	}
}

template <class T>
void THeadList<T>::InsCurrent(const T& elem)
{
	if (pCurr == pFirst)
		InsFirst(elem);
	else
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->Val = elem;
		pPred->pNext = tmp;
		tmp->pNext = pCurr;
		pCurr = tmp;
		len++;
	}
}

template <class T>
void THeadList<T>::DelCurrent()
{
	if (pCurr == pFirst)
		DelFirst();
	else
	{
		pPred->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPred->pNext;
		len--;
	}
}

template <class T>
void THeadList<T>::InsLast(const T& elem)
{
	if (len != 0)
	{
		TLink<T>* tmp = new TLink<T>(elem);
		pLast->pNext = tmp;
		tmp->pNext = pStop;
		pLast = tmp;
		len++;
	}
	else
	{
		InsFirst(elem);
	}
}

template <class T>
void THeadList<T>::Reset()
{
	pCurr = pFirst;
	pPred = pHead;
}

template <class T>
void THeadList<T>::GoNext()
{
	pCurr = pCurr->pNext;
	pPred = pPred->pNext;
}

template <class T>
bool THeadList<T>::IsEnd()
{
	if (pCurr == pStop)
		return true;
	else
		return false;
}
template <class T>
THeadList<T>::THeadList(const THeadList& hl)
{
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pStop;
	pFirst = pLast = pCurr = pPred = NULL;
	len = 0;
	pos = 0;
	for (TLink<T>*p = hl.pFirst; p != hl.pStop; p = p->pNext)
	{
		InsLast(p->Val);
	}
}

template <class T>
THeadList& THeadList<T>::operator=(const THeadList &hl)
{
	pos = 0;
	pCurr = NULL;
	while (len != 0)
		DelFirst();
	for (TLink<T>*p = hl.pFirst; p != hl.pStop; p = p->pNext)
		InsLast(p->Val);
}