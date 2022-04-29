#include "pch.h"
#include "CVector_iterator.h"
#include <Cstring>

//������
template<typename T>
CVector_iterator<T>::CVector_iterator() : pAdress(nullptr) , nSize(0)
{

}
template<typename T>
CVector_iterator<T>::CVector_iterator(int nSize, T* TstartAdress) : nSize(nSize)
{
	pAdress = new T*[nSize];

	// �ּҰ� ����
	for (int i = 0; i < nSize; i++)
	{
		*(pAdress + i) = (TstartAdress + i);
	}
}

//�Ҹ���
template<typename T>
CVector_iterator<T>::~CVector_iterator()
{
	if (pAdress)
	{
		delete[] pAdress;
		pAdress = nullptr;
	}
}

//��� �Լ�
template<typename T>
void CVector_iterator<T>::SetAdress(const T* TstartAdess)
{
	if (nSize <= 0 || pAdress == nullptr)
		return;

	if (pAdress)
	{
		delete[] pAdress;
	}

	pAdress = new T * [nSize];
	// �ּҰ� ����
	for (int i = 0; i < nSize; i++)
	{
		*(pAdress + i) = (TstartAdress + i);
	}
}
