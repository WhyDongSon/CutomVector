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
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

	//��� �Լ�
	void SetAdress(T* TstartAdess);
	T* GetAdress(int nIndex);

private:
	//��� ����
	T		*pAdress;
};

#endif