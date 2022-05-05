#ifndef CVECTOR_ITERATOR_H
#define CVECTOR_ITERATOR_H

#pragma once

template<typename T>
class CVector_iterator
{
public:
	//������
	CVector_iterator();
	CVector_iterator(T* TstartAdress);

	//�Ҹ���
	virtual ~CVector_iterator();

	//������ �����ε�
	//T* operator++();
	//T* operator++(int);

	CVector_iterator<T>& operator++();
	CVector_iterator<T>& operator++(int);
	bool operator == (CVector_iterator<T>&Iterator);
	bool operator != (CVector_iterator<T>& Iterator);

	//������ �����ε�
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

	//��� �Լ�
	void SetAdress(T* TstartAdess);
	T* GetAdress();

private:
	//��� ����
	T		*pAdress;
};

#endif