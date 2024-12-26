#include"student.h"
#include"teacher.h"
#include"manager.h"

//�������Ա�Ӳ˵�
void managerMenu(Identity* &manager)
{
	while (1)
	{
		//������ָ��תΪ����ָ��
		Manager* man = (Manager*)manager;

		//��ʼ������
		man->initVector();

		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//�鿴�˺� 
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if(select ==3)
		{
			//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�!" << endl;

			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (1)
	{
		Student* stu = (Student*)student;

		//��ʼ��
		stu->initVector();

		//ѧ���˵�
		student->operMenu();
	
		int select = 0;
		
		if (select == 1)	//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)	//�鿴����
		{
			stu->showMyOrder();
		}
		else if (select == 3)	//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)	//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else 
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void LoginIN(string fileName, int type)
{
	Identity* person = nullptr;	//����ָ�봴���������
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//ѧ����¼
	{
		cout << ">���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2  )	//��ʦ��¼
	{
		cout << ">���������ְ����:" << endl;
		cin >> id;
	}
	
	cout << ">�������û���:" << endl;
	cin >> name;
	cout << ">����������:" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//ѧ���˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//��ʦ�˵�

				return;
			}
		}
	}
	else
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//����Ա�˵�
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��¼ʧ��" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {
	int select = 0;	//�����û�ѡ��

	while (1)
	{
		cout << "====================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          1.ѧ������          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          2.��    ʦ          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          3.�� �� Ա          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          0.��    ��          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t--------------------------------\n";
		cout << ">��������ѡ��:";

		cin >> select;

		switch (select)
		{
		case 0:	//�˳�
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		case 1:	//ѧ��
			LoginIN(STUDENT_FILE,1);
			break;
		case 2:	//��ʦ
			LoginIN(TEACHER_FILE,2);
			break;
		case 3:	//����Ա
			LoginIN(ADMIN_FILE,3);
			break;
		default:
			cout << "�����������������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}