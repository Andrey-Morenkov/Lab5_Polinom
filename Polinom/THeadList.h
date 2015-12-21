#include "TLink.h"

template <class T>
class THeadList
{
protected:
	TLink<T>* pHead;                // указатель на голову
	TLink<T>* pFirst;               // указатель на первый
	TLink<T>* pLast;                // указатель на последний
	TLink<T>* pPred;                // указатель на предыдущий
	TLink<T>* pCurr;                // указатель на следущий
	TLink<T>* pStop;                // указатель последнего на голову
	int pos;                        // позиция текущего элемента
	int len;                        // длина списка

public:
	THeadList();
	~THeadList();

	void InsFirst(const T elem);    // Вставить первый элемент
	void InsCurrent(const T elem);  // Вставить текущий элемент
	void InsLast(const T elem);     // Вставить последний элемент
	void DelFirst();                // Удалить первый элемент
	void DelCurrent();              // Удалить текущий элемент

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
