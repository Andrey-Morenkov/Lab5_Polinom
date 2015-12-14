template <class T>
class TLink
{
private:
	T Val;          // «начение
	TLink* pNext;   // ”казатель на след элемент
	int Type;       // “ип звена

public:
	TLink(T _Val);
	TLink(const TLink& L);
	~TLink();
};

template <class T>
TLink<T>::TLink(T _Val = 0)
{
	Val = _Val;
	pNext = this;             // шаблон по умолчанию - "пустой" полином
	Type = -1;
}

template <class T>
TLink<T>::TLink(const TLink& L)
{
	Val = L.Val;
	pNext = L.pNext;
	Type = L.Type;
}

template <class T>
TLink<T>::TLink()
{
	delete pNext;
}
