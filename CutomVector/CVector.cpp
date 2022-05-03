#include "pch.h"
#include "CVector.h"

//*******************************************************************
//CVectorData
//*******************************************************************
template<typename T>
CVectorData<T>::CVectorData():pData(nullptr), Iterator(nullptr), nSize(0), nCapacity (0)
{
}

template<typename T>
CVectorData<T>::CVectorData(int nSize) : nSize(nSize) , nCapacity(static_cast<int>(nSize * 1.5))
{
	pData = new T[nCapacity];
	Iterator = new CVector_iterator<T>[nCapacity];

	for (int i = 0; i < nSize; i++)
	{
		pData[i] = 0;
		Iterator[i].SetAdress(&pData[i]);
	}
}


template<typename T>
CVectorData<T>::CVectorData(int nSize, int nCapacity, int nInit) : nSize(nSize), nCapacity(nCapacity)
{
	pData = new T[nCapacity];
	Iterator = new CVector_iterator<T>[nCapacity];

	for (int i = 0; i < nSize; i++)
	{
		pData[i] = nInit;
		Iterator[i].SetAdress(&pData[i]);
	}
}


template<typename T>
CVectorData<T>::CVectorData(int nSize, int nInit) : nSize(nSize), nCapacity(static_cast<int>(nSize * 1.5))
{
	pData = new T[nCapacity];
	Iterator = new CVector_iterator<T>[nCapacity];

	for (int i = 0; i < nSize; i++)
	{
		pData[i] = nInit;
		Iterator[i].SetAdress(&pData[i]);
	}
}

template<typename T>
CVectorData<T>::CVectorData(const CVectorData& Data)
{
	nSize = Data.nSize;
	nCapacity = Data.nCapacity;

	pData = new T[nCapacity];
	Iterator = new Citerator[nCapacity];

	memcpy(pData, Data.pData, sizeof(T) * nSize);
	memcpy(Iterator, Data.Iterator, sizeof(Citerator) * nSize);
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

 //����Լ�
 template<typename T>
 CVector_iterator<T>* CVectorData<T>::GetCiterator(int nIdex)
 {
	 if (&Iterator[nIdex] != nullptr)
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

 template<typename T>
 void CVectorData<T>::SetSize(int Size, int Capacity)
 {
	 nSize = Size;
	 nCapacity = Capacity;
 }

 template<typename T>
 void CVectorData<T>::SetBackData(T nData)
 {
	 //Szie �ø������� ȣ���.
	 pData[nSize - 1] = nData;
	 Iterator[nSize - 1].SetAdress(&pData[nSize - 1]);
 }

 template<typename T>
 T CVectorData<T>::GetBackData()
 {
	 //Size ���δ����� ȣ��
	 T ReturnData = pData[nSize];

	 pData[nSize] = 0;
	 Iterator[nSize].SetAdress(nullptr);
 }

 //������ �����ε�
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
//	//�� �ʱ�ȭ
//	for (int i = 0; i < nSize; i++)
//	{
//		pData[i] = 0;
//	}
//
//	//�ּҰ� ����
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
//	//�� �ʱ�ȭ
//	for (int i = 0; i < nSize; i++)
//	{
//		pData[i] = nInit;
//	}
//
//	//�ּҰ� ����
//	Iterator.SetAdress(&pData[0]);
//}

//*******************************************************************
//CVectorData
//*******************************************************************
//�⺻ ������
template<typename T>
CVector<T>::CVector() :  nSize(0), nCapasity(0)
{
	pData = new CData();
}

// ������ �⺻ �޸� �Ҵ�
template<typename T>
CVector<T>::CVector(int nSize) : nSize(nSize), nCapasity(static_cast<int>(nSize * 1.5))
{
	pData = new CData(nSize, nCapasity, 0);
}

//������ �⺻ �޸� �Ҵ� And �ʱ�ȭ
template<typename T>
CVector<T>::CVector(int nSize, int nInit) : nSize(nSize), nCapasity(static_cast<int>(nSize * 1.5))
{
	pData = new CData(nSize, nCapasity, nInit);
}

// �Ҹ���
template<typename T>
CVector<T>::~CVector()
{
	if (pData)
	{
		delete pData;
		pData = nullptr;
	}
}

// ������ �����ε�
template<typename T>
T& CVector<T>::operator[](int nNum)
{
	return *(pData->GetpData(nNum));
}

// ��� �Լ�
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
CVector_iterator<T>* CVector<T>::Cbegin()
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
CVector_iterator<T>* CVector<T>::Cend()
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

template<typename T>
int CVector<T>::Csize()
{
	return nSzie;
}

template<typename T>
int CVector<T>::Ccapacity()
{
	return nCapacity;
}

template<typename T>
bool CVector<T>::Creserve(int nNum)
{
	if (nNum <= nCapasity)
		return FALSE;

	//���� ������ ����
	CData* PreData = new CData(*pData);

	nCapasity = nNum;

	if (pData != nullptr)
	{
		//���� ������ ����
		delete pData;

		pData = new CData(nSize, nCapasity, 0);

		memcpy(pData->GetpData(0), PreData->GetpData(0), sizeof(T) * nSize);
		//memcpy(pData->GetCiterator(0), PreData->GetCiterator(0), sizeof(Citerator) * nSize);
	}
	else{ return FALSE;}

	delete PreData;

	return TRUE;
}

template<typename T>
bool CVector<T>::Cresize(int size)
{
	if (nSize >= size)
		return FALSE;

	int preSzie = nSize;

	//���� ������ ����
	CData* PreData = new CData(*pData);

	nSize = size;
	
	if (nCapasity < nSize)
		nCapasity = nSize;

	if (pData != nullptr)
	{
		//���� ������ ����
		delete pData;

		pData = new CData(nSize, nCapasity, 0);

		//������ ����
		memcpy(pData->GetpData(0), PreData->GetpData(0), sizeof(T) * preSzie);
		//memcpy(pData->GetCiterator(0), PreData->GetCiterator(0), sizeof(Citerator) * preSzie);
	}
	else
	{
		return nullptr;
	}

	delete preData;

	return TRUE;
}

template<typename T>
bool CVector<T>::Cresize(int size, int nNum)
{
	if (nSize >= size)
		return FALSE;

	int preSzie = nSize;

	//���� ������ ����
	CData* PreData = new CData(*pData);

	nSize = size;

	if (nCapasity < nSize)
		nCapasity = nSize;

	if (pData != nullptr)
	{
		//���� ������ ����
		delete pData;

		pData = new CData(nSize, nCapasity, 0);

		//������ ����
		memcpy(pData->GetpData(0), PreData->GetpData(0), sizeof(T) * preSzie);
		//memcpy(pData->GetCiterator(0), PreData->GetCiterator(0), sizeof(Citerator) * nSize);

		for (int i = preSzie; i < nSize; i++)
		{
			//push_back �� �ڸ�
		}
	}
	else
	{
		return nullptr;
	}

	delete preData;

	return TRUE;
}

template<typename T>
void CVector<T>::Cpush_back(T nData)
{
	int preSzie = nSize;

	if (nSize == nCapasity)
	{
		//������ ����
		CData* PreData = new CData(*pData);

		if (pData)
			delete pData;

		if (nSize == 0 && nCapasity == 0)
		{
			nSize++;
			nCapasity = 1;

			pData = new CData(nSize, nCapasity, 0);
			pData->SetBackData(nData);
		}
		else
		{
			nSize++;

			nCapasity = static_cast<int>(nSize * 1.5);

			pData = new CData(nSize, nCapasity, 0);
			memcpy(pData->GetpData(0), PreData->GetpData(0), sizeof(T) * preSzie);

			pData->SetBackData(nData);

			delete PreData;
		}
	}
	else
	{
		nSize++;

		pData->SetSize(nSize, nCapasity); // Size, Capacity ����.
		pData->SetBackData(nData);
	}
}
template<typename T>
T CVector<T>::Cpop_back()
{
	if (nSize <= 0)
		return 0;

	nSize--;

	pData->SetSize(nSize, nCapasity);
	pData->GetBackData();
}

template<typename T>
bool CVector<T>::Cempty()
{
	if (nSize <= 0)
		return TRUE;
	else
		return FALSE;
}