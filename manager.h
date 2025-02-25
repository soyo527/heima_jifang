#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager:public Identity
{
//变量
public:
	//教室编号
	int m_EmpId;

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;

//函数
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//重复账号检测
	bool checkRepeat(int id, int type);
};