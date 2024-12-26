#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager:public Identity
{
//����
public:
	//���ұ��
	int m_EmpId;

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;

//����
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//�ظ��˺ż��
	bool checkRepeat(int id, int type);
};