#pragma once
#include"identity.h"

class Teacher:public Identity
{
//����
public:
	//���ұ��
	int m_EmpId;

//����
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empid, string name, string pwd);

	//�˵�
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();
};