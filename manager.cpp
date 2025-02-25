#include"manager.h"

//默认构造
Manager::Manager(){}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//菜单
void Manager::operMenu()
{
	cout << "欢迎管理员:" << this->m_Name << "登录!" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.添加账号          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.查看账号          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.查看机房          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.清空预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.注销登录          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << ">输入您的选择:";
}

//初始化容器
void Manager::initVector()
{
	//读取信息
	//学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();
	vCom.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量为:" << vStu.size() << endl;
	ifs.close();

	//老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为:" << vTea.size() << endl;
	ifs.close();
	
	//机房信息
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为:" << vCom.size() << endl;
	ifs.close();
}

//重复账号检测
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto i : vStu)
		{
			if (i.m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto i : vTea)
		{
			if (i.m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

//添加账号
void Manager::addPerson()
{
	cout << ">请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = ">请输入学号:";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = ">请输入职工编号:";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		//检测重复
		if (checkRepeat(id, select))
		{
			cout << ">账号重复,请重新输入:" ;
			continue;
		}		
		break;
	}
	cout << ">请输入姓名:" << endl;
	cin >> name;

	cout << ">请输入密码:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
}

//显示学生信息
void printStudent(Student& s)
{
	cout << "学号: " << s.m_Id << " 姓名: " << s.m_Name << " 密码: " << s.m_Pwd << endl;
}

//显示老师信息
void printTeacher(Teacher& t)
{
	cout << "职工号: " << t.m_EmpId << " 姓名: " << t.m_Name << " 密码: " << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << ">请选择查看内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		for (auto i:vStu)
		{
			printStudent(i);
		}
	}
	else
	{
		for (auto i : vTea)
		{
			printTeacher(i);
		}
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	for (auto i : vCom)
	{
		cout << "机房编号: " << i.m_ComId << " 机房最大容量: " << i.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}