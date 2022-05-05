#include "pch.h"
#include "CVector_iterator.h"
#include "CVector.h"
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

//������ �����ε�
//template<typename T>
//T* CVector_iterator<T>::operator ++()
//{
//	return (this->pAdress + 1);
//}
//
//template<typename T>
//T* CVector_iterator<T>::operator ++(int)
//{
//	return (this->pAdress + 1);
//}

template<typename T>
CVector_iterator<T>& CVector_iterator<T>::operator ++()
{
	CVectorData<T>* Data = (CVectorData<T>*)ClassAdress;
	CVector_iterator<T>* Result = nullptr;

	Result = Data->GetCiterator(pAdress);

	return *(Result + 1);
}

template<typename T>
CVector_iterator<T>& CVector_iterator<T>::operator ++(int)
{
	CVectorData<T>* Data = (CVectorData<T>*)ClassAdress;
	CVector_iterator<T>* Result = nullptr;

	Result = Data->GetCiterator(pAdress);

	return *(Result + 1);

}
template<typename T>
bool CVector_iterator<T>::operator==(CVector_iterator<T>& Iterator)
{
	return (this->pAdress == Iterator.pAdress);
}

template<typename T>
bool CVector_iterator<T>::operator!=(CVector_iterator<T>& Iterator)
{
	return (this->pAdress != Iterator.pAdress);
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
T* CVector_iterator<T>::GetAdress()
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
