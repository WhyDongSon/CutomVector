#include "pch.h"
#include "CVector.h"

//*******************************************************************
//CVectorData
//*******************************************************************
template<typename T>
CVectorData<T>::CVectorData():pData(nullptr), Iterator(nullptr), nSize(0)
{
}

template<typename T>
CVectorData<T>::CVectorData(int nSize) : nSize(nSize)
{
	pData = new T[nSize];
	Iterator = new CVector_iterator<T>[nSize];

	for (int i = 0; i < nSize; i++)
	{
		pData[i] = 0;
		Iterator[i].SetAdress(&pData[i]);
	}
}

template<typename T>
CVectorData<T>::CVectorData(int nSize, int nInit) : nSize(nSize)
{
	pData = new T[nSize];
	Iterator = new CVector_iterator<T>[nSize];

	for (int i = 0; i < nSize; i++)
	{
		pData[i] = nInit;
		Iterator[i].SetAdress(&pData[i]);
	}
}

template<typename T>
 CVectorData<T>::~CVectorData()
{
	if (pData)
	{
		delete[] pData;
		pData = nullptr;
	}

	if (Iterator)
	{
		delete[] Iterator;
		Iterator = nullptr;
	}
}

 //기능함수
 template<typename T>
 CVector_iterator<T>* CVectorData<T>::GetCiterator(int nIdex)
 {
	 if (Iterator[nIdex] != nullptr)
	 {
		 return &Iterator[nIdex];
	 }
	 else
	 {
		 return nullptr;
	 }
 }

 template<typename T>
 T* CVectorData<T>::GetpData(int nIdex)
 {
	 if (nIdex >= nSize)
		 return nullptr;

	 return &pData[nIdex];
 }

 //연산자 오버로딩
//template<typename T>
//CVectorData<T> CVectorData<T> :: operator()(int nSize)
//{
//	if (nSize <= 0)
//		return nullptr;
//
//	if (pData)
//	{
//		delete[] pData;
//	}
//
//	pData = new T(nSize);
//
//	//값 초기화
//	for (int i = 0; i < nSize; i++)
//	{
//		pData[i] = 0;
//	}
//
//	//주소값 저장
//	Iterator.SetAdress(&pData[0]);
//}

//template<typename T>
//CVectorData<T> CVectorData<T> :: operator()(int nSize, int nInit)
//{
//	if (nSize <= 0)
//		return nullptr;
//
//	if (pData)
//	{
//		delete[] pData;
//	}
//
//	pData = new T(nSize);
//
//	//값 초기화
//	for (int i = 0; i < nSize; i++)
//	{
//		pData[i] = nInit;
//	}
//
//	//주소값 저장
//	Iterator.SetAdress(&pData[0]);
//}

//*******************************************************************
//CVectorData
//*******************************************************************
//기본 생성자
template<typename T>
CVector<T>::CVector() :  nSize(0), nCapasity(0)
{
	pData = new CData();
}

// 생성시 기본 메모리 할당
template<typename T>
CVector<T>::CVector(int nSize) : nSize(nSize), nCapasity(nSize)
{
	pData = new CData(nSize);
}

//생성시 기본 메모리 할당 And 초기화
template<typename T>
CVector<T>::CVector(int nSize, int nInit) : nSize(nSize), nCapasity(nSize)
{
	pData = new CData(nSize, nInit);
}

// 소멸자
template<typename T>
CVector<T>::~CVector()
{
	if (pData)
	{
		delete pData;
		pData = nullptr;
	}
}

// 연산자 오버로딩
template<typename T>
T& CVector<T>::operator[](int nNum)
{
	return *(pData->GetpData(nNum));
}

// 기능 함수
template<typename T>
T& CVector<T>::Cfront()
{
	if (pData[0] != nullptr)
		return pData[0];
	else
		return nullptr;
}

template<typename T>
T& CVector<T>::Cback()
{
	int nIndex = nSize - 1;

	if (pData[nIndex] != nullptr)
		return pData[nSize - 1];
	else
		return nullptr;
}

template<typename T>
T* CVector<T>::Cbegin()
{
	CVector_iterator<T> *citerator;

	citerator = pData->GetCiterator(FIST_ITERATOR);

	if (citerator)
	{
		return citerator;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
T* CVector<T>::Cend()
{
	CVector_iterator<T> *citerator;

	citerator = pData->GetCiterator(LAST_ITERATOR);

	if (citerator)
	{
		return citerator;
	}
	else
	{
		return nullptr;
	}
}