#include"student.h"

//Ĭ�Ϲ���
Student::Student(){}

//�вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name=name;
	this->m_Pwd=pwd;
}

//��ʼ��
void Student::initVector()
{
	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

//�˵�
void Student::operMenu()
{
	cout << "��ӭѧ��:" << this->m_Name << "��¼!" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.����ԤԼ          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.�鿴����ԤԼ      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.ȡ��ԤԼ          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.ע����¼          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << ">��������ѡ��:";
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << ">����������ԤԼ��ʱ��:" << endl;
}

//�鿴����ԤԼ
void Student::showMyOrder()
{

}

//�鿴����ԤԼ
void Student::showAllOrder()
{

}

//ȡ��ԤԼ
void Student::cancelOrder()
{

}