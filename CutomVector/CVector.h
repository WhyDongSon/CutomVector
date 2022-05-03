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

	//생성자
	CVectorData();
	CVectorData(int nSize); //Size 초기 설정(초기값 0)
	CVectorData(int nSize, int nCapacity, int nInit); //Size 초기 설정(초기값 0)
	CVectorData(int nSize, int nInit); //Size 및 초기값 설정
	CVectorData(const CVectorData& Data);

	//소멸자
	virtual ~CVectorData();

	//기능 함수
	Citerator* GetCiterator(int nIdex);
	T* GetpData(int nIdex);
	T  GetBackData();

	void SetBackData(T nData);
	void SetSize(int nSize, int nCapacity); // Size, Capacity 설정.

	//연산자 오버로딩
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

	//기본 생성자
	CVector();

	//생성자
	CVector(int nSize); //Size 초기 설정(초기값 0)
	CVector(int nSize, int nInit); //Size 및 초기값 설정

	//소멸자
	virtual ~CVector();

	//연산자 오버로딩
	T& operator[](int nNum);

	//기능 함수
	T& Cfront(); // 첫번째 참조값 반환
	T& Cback();	 // 마지막 참조값 반환

	int Csize();
	int Ccapacity();
	bool Creserve(int nNum);
	bool Cempty();
	bool Cresize(int size);
	bool Cresize(int size, int nNum);

	void Cpush_back(T nData);
	T Cpop_back();

	Citerator* Cbegin(); // 첫번째 위치값 반화
	Citerator* Cend();	 // 마지막 위치값 반환

private:
	CData		*pData;	// Data 한개만 만듬 (그 안에서 동적 할당으로 늘려 나감)
	int			nSize;
	int			nCapasity;
};

#endif