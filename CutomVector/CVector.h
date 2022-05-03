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
	CVectorData(int nSize, int nCapacity, int nInit); //Size �ʱ� ����(�ʱⰪ 0)
	CVectorData(int nSize, int nInit); //Size �� �ʱⰪ ����
	CVectorData(const CVectorData& Data);

	//�Ҹ���
	virtual ~CVectorData();

	//��� �Լ�
	Citerator* GetCiterator(int nIdex);
	T* GetpData(int nIdex);
	T  GetBackData();

	void SetBackData(T nData);
	void SetSize(int nSize, int nCapacity); // Size, Capacity ����.

	//������ �����ε�
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

private:
	T			*pData;
	Citerator	*Iterator; //Adress
	int			nSize;
	int			nCapacity;
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

	int Csize();
	int Ccapacity();
	bool Creserve(int nNum);
	bool Cempty();
	bool Cresize(int size);
	bool Cresize(int size, int nNum);

	void Cpush_back(T nData);
	T Cpop_back();

	Citerator* Cbegin(); // ù��° ��ġ�� ��ȭ
	Citerator* Cend();	 // ������ ��ġ�� ��ȯ

private:
	CData		*pData;	// Data �Ѱ��� ���� (�� �ȿ��� ���� �Ҵ����� �÷� ����)
	int			nSize;
	int			nCapasity;
};

#endif