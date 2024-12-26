#pragma once
#include"identity.h"
#include"computerRoom.h"

class Student:public Identity
{
//变量
public:
	//学号
	int m_Id;

	//机房容量
	vector<ComputerRoom> vCom;

//函数
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//初始化
	void initVector();

	//菜单
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();
};