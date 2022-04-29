#ifndef CVECTOR_ITERATOR_H
#define CVECTOR_ITERATOR_H

#pragma once

template<typename T>
class CVector_iterator
{
public:
	//생성자
	CVector_iterator();
	CVector_iterator(int nSize, T* TstartAdress);

	//소멸자
	~CVector_iterator();

	//연산자 오버로딩
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

	//기능 함수
	void SetAdress(const T* TstartAdess);

private:
	//멤버 변수
	T		**pAdress;
	int		nSize;
};

#endif