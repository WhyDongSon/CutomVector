#ifndef CVECTOR_H
#define CVECTOR_H

#define FIST_ITERATOR (0)

#pragma once
#include "CVector_iterator.h"

//*******************************************************************
//CVectorData
//*******************************************************************
template<typename T>
class CVectorData
{
public:
	using Citerator = CVector_iterator<T>;

	//������
	CVectorData();
	CVectorData(int nSize); //Size �ʱ� ����(�ʱⰪ 0)
	CVectorData(int nSize, int nInit); //Size �� �ʱⰪ ����

	//�Ҹ���
	virtual ~CVectorData();

	//��� �Լ�
	Citerator* GetCiterator(int nIdex);
	T* GetpData(int nIdex);

	//������ �����ε�
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

private:
	T			*pData;
	Citerator	*Iterator; //Adress
	int			nSize;
};

//*******************************************************************
//CVectorData
//*******************************************************************
template<typename T>
class CVector
{
public:
	using CData = CVectorData<T>;
	using Citerator = CVector_iterator<T>;

	//�⺻ ������
	CVector();

	//������
	CVector(int nSize); //Size �ʱ� ����(�ʱⰪ 0)
	CVector(int nSize, int nInit); //Size �� �ʱⰪ ����

	//�Ҹ���
	virtual ~CVector();

	//������ �����ε�
	T& operator[](int nNum);

	//��� �Լ�
	T& Cfront(); // ù��° ������ ��ȯ
	T& Cback();	 // ������ ������ ��ȯ

	T* Cbegin(); // ù��° ��ġ�� ��ȭ(iterator�� �ּҰ�)
	T* Cend();	 // ������ ��ġ�� ��ȯ(iterator�� �ּҰ�)


private:
	CData		*pData;
	int			nSize;
	int			nCapasity;
};

#endif