#pragma once
#include <bits/stdc++.h>
#include "globalFile.h"
using namespace std;
class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0;

	string m_Name;	//用户名
	string m_Pwd;	//密码
};