#ifndef CVECTOR_ITERATOR_H
#define CVECTOR_ITERATOR_H

#pragma once

template<typename T>
class CVector_iterator
{
public:
	//������
	CVector_iterator();
	CVector_iterator(int nSize, T* TstartAdress);

	//�Ҹ���
	~CVector_iterator();

	//������ �����ε�
	//CVectorData operator()(int nSize);
	//CVectorData operator()(int nSize, int nInit);

	//��� �Լ�
	void SetAdress(const T* TstartAdess);

private:
	//��� ����
	T		**pAdress;
	int		nSize;
};

#endif