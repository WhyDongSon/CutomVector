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

	//생성자
	CVectorData();
	CVectorData(int nSize); //Size 초기 설정(초기값 0)
	CVectorData(int nSize, int nInit); //Size 및 초기값 설정

	//소멸자
	~CVectorData();

	//연산자 오버로딩
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

	//기본 생성자
	CVector();

	//생성자
	CVector(int nSize); //Size 초기 설정(초기값 0)
	CVector(int nSize, int nInit); //Size 및 초기값 설정

	//소멸자
	~CVector();

	//연산자 오버로딩
	CVector operator[](int nNum);

	//기능 함수
	T& Cfront(); // 첫번째 참조값 반환
	T& Cback();	 // 마지막 참조값 반환

private:
	CData		*pData;
	int			nSize;
	int			nCapasity;
};

#endif