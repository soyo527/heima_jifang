#include"student.h"

//默认构造
Student::Student(){}

//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name=name;
	this->m_Pwd=pwd;
}

//初始化
void Student::initVector()
{
	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

//菜单
void Student::operMenu()
{
	cout << "欢迎学生:" << this->m_Name << "登录!" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.申请预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.查看我的预约      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.查看所有预约      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.取消预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.注销登录          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << ">输入您的选择:";
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五!" << endl;
	cout << ">请输入申请预约的时间:" << endl;
}

//查看自身预约
void Student::showMyOrder()
{

}

//查看所有预约
void Student::showAllOrder()
{

}

//取消预约
void Student::cancelOrder()
{

}