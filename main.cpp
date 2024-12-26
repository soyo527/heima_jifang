#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入管理员子菜单
void managerMenu(Identity* &manager)
{
	while (1)
	{
		//将父类指针转为子类指针
		Manager* man = (Manager*)manager;

		//初始化容器
		man->initVector();

		//调用管理员子菜单
		manager->operMenu();

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//查看账号 
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if(select ==3)
		{
			//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功!" << endl;

			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单
void studentMenu(Identity*& student)
{
	while (1)
	{
		Student* stu = (Student*)student;

		//初始化
		stu->initVector();

		//学生菜单
		student->operMenu();
	
		int select = 0;
		
		if (select == 1)	//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)	//查看自身
		{
			stu->showMyOrder();
		}
		else if (select == 3)	//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)	//取消预约
		{
			stu->cancelOrder();
		}
		else 
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void LoginIN(string fileName, int type)
{
	Identity* person = nullptr;	//父类指针创建子类对象
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << ">请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2  )	//教师登录
	{
		cout << ">请输入你的职工号:" << endl;
		cin >> id;
	}
	
	cout << ">请输入用户名:" << endl;
	cin >> name;
	cout << ">请输入密码:" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//学生菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//教师菜单

				return;
			}
		}
	}
	else
	{
		//管理员登录验证
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//管理员菜单
				managerMenu(person);

				return;
			}
		}
	}

	cout << "登录失败" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {
	int select = 0;	//接收用户选择

	while (1)
	{
		cout << "====================  欢迎来到传智播客机房预约系统  ====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          1.学生代表          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          2.老    师          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          3.管 理 员          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          0.退    出          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t--------------------------------\n";
		cout << ">输入您的选择:";

		cin >> select;

		switch (select)
		{
		case 0:	//退出
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		case 1:	//学生
			LoginIN(STUDENT_FILE,1);
			break;
		case 2:	//老师
			LoginIN(TEACHER_FILE,2);
			break;
		case 3:	//管理员
			LoginIN(ADMIN_FILE,3);
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}