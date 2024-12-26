#pragma once
#include"identity.h"

class Teacher:public Identity
{
//变量
public:
	//教室编号
	int m_EmpId;

//函数
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empid, string name, string pwd);

	//菜单
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();
};