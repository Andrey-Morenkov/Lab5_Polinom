#include "TLink.h"

template <class T>
class THeadList
{
protected:
	TLink<T>* pHead;                // ��������� �� ������
	TLink<T>* pFirst;               // ��������� �� ������
	TLink<T>* pLast;                // ��������� �� ���������
	TLink<T>* pPred;                // ��������� �� ����������
	TLink<T>* pCurr;                // ��������� �� ��������
	TLink<T>* pStop;                // ��������� ���������� �� ������
	int pos;                        // ������� �������� ��������
	int len;                        // ����� ������

public:
	THeadList();
	~THeadList();

	void InsFirst(const T elem);    // �������� ������ �������
	void InsCurrent(const T elem);  // �������� ������� �������
	void InsLast(const T elem);     // �������� ��������� �������
	void DelFirst();                // ������� ������ �������
	void DelCurrent();              // ������� ������� �������

	void Reset();
	void GoNext();
	bool IsEnd();

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
		}
	}
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(const T elem)
{
	TLink<T>* tmp = new TLink<T>;
	tmp->Val = elem;
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
		pHead->pNext = pFirst->pNext;
		delete pFirst;
		pFirst = pHead->pNext;
		len--;
		pos--;
	}
}

template <class T>
void THeadList<T>::InsCurrent(const T elem)
{
	if (pCurr == pFirst)
		InsFirst(T);
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
