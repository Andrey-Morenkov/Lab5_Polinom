template <class T>
class TLink
{
private:
	T Val;          // ��������
	TLink* pNext;   // ��������� �� ���� �������

public:
	explicit TLink(const T& _Val = T());
	TLink(const TLink& L);
	~TLink();

	T& GetVal() { return Val; }
};

template <class T>
TLink<T>::TLink(const T& _Val)
{
	Val = _Val;
	pNext = this;             // ������ �� ��������� - "������" �������
}

template <class T>
TLink<T>::TLink(const TLink& L)
{
	Val = L.Val;
	pNext = L.pNext;
}

template <class T>
TLink<T>::~TLink()
{
	delete pNext;
}
