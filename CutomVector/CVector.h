#ifndef CVECTOR_H
#define CVECTOR_H

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
	~CVectorData();

	//������ �����ε�
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

private:
	T			*pData;
	Citerator	*Iterator; //Adress
};

//*******************************************************************
//CVectorData
//*******************************************************************
template<typename T>
class CVector
{
public:
	using CData = CVectorData<T>;

	//�⺻ ������
	CVector();

	//������
	CVector(int nSize); //Size �ʱ� ����(�ʱⰪ 0)
	CVector(int nSize, int nInit); //Size �� �ʱⰪ ����

	//�Ҹ���
	~CVector();

	//������ �����ε�
	CVector operator[](int nNum);

	//��� �Լ�
	T& Cfront(); // ù��° ������ ��ȯ
	T& Cback();	 // ������ ������ ��ȯ

private:
	CData		*pData;
	int			nSize;
	int			nCapasity;
};

#endif