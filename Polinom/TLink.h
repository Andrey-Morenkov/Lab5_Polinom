template <class T>
class TLink
{
private:
	T Val;          // ��������
	TLink* pNext;   // ��������� �� ���� �������
	int Type;       // ��� �����

public:
	TLink(T _Val);
	TLink(const TLink& L);
	~TLink();
};

template <class T>
TLink<T>::TLink(T _Val = 0)
{
	Val = _Val;
	pNext = this;             // ������ �� ��������� - "������" �������
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
