#include "pch.h"
#include "CVector_iterator.h"
#include <Cstring>

//������
template<typename T>
CVector_iterator<T>::CVector_iterator() : pAdress(nullptr)
{

}
template<typename T>
CVector_iterator<T>::CVector_iterator(T* TstartAdress)
{
	pAdress = TstartAdress;
}

//template<typename T>
//CVector_iterator<T>::CVector_iterator(int nSize, T* TstartAdress) : nSize(nSize)
//{
//	pAdress = new T*[nSize];
//
//	// �ּҰ� ����
//	for (int i = 0; i < nSize; i++)
//	{
//		*(pAdress + i) = (TstartAdress + i);
//	}
//}

//�Ҹ���
template<typename T>
CVector_iterator<T>::~CVector_iterator()
{

}

//��� �Լ�
//template<typename T>
//void CVector_iterator<T>::SetAdress(const T* TstartAdess)
//{
//	if (nSize <= 0 || pAdress == nullptr)
//		return;
//
//	if (pAdress)
//	{
//		delete[] pAdress;
//	}
//
//	pAdress = new T * [nSize];
//	// �ּҰ� ����
//	for (int i = 0; i < nSize; i++)
//	{
//		*(pAdress + i) = (TstartAdress + i);
//	}
//}

//template<typename T>
//T* CVector_iterator<T>::GetAdress(int nIdex)
//{
//	if (pAdress)
//	{
//		return *(pAdress + nIdex)
//	}
//	else
//	{
//		return nullptr;
//	}
//}

//����Լ�
template<typename T>
void CVector_iterator<T>::SetAdress(T* TstartAdess)
{
	pAdress = TstartAdess;
}

template<typename T>
T* CVector_iterator<T>::GetAdress(int nIndex)
{
	if (pAdress != nullptr)
	{
		return pAdress;
	}
	else
	{
		return nullptr;
	}
}
