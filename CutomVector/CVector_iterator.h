#ifndef CVECTOR_ITERATOR_H
#define CVECTOR_ITERATOR_H

#pragma once

template<typename T>
class CVector_iterator
{
public:
	//생성자
	CVector_iterator();
	CVector_iterator(T* TstartAdress);

	//소멸자
	virtual ~CVector_iterator();

	//연산자 오버로딩
	//T* operator++();
	//T* operator++(int);

	CVector_iterator<T>& operator++();
	CVector_iterator<T>& operator++(int);
	bool operator == (CVector_iterator<T>&Iterator);
	bool operator != (CVector_iterator<T>& Iterator);

	//연산자 오버로딩
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

	//기능 함수
	void SetAdress(T* TstartAdess);
	T* GetAdress();

private:
	//멤버 변수
	T		*pAdress;
};

#endif