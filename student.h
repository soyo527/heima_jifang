#pragma once
#include"identity.h"
#include"computerRoom.h"

class Student:public Identity
{
//����
public:
	//ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;

//����
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//��ʼ��
	void initVector();

	//�˵�
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();
};