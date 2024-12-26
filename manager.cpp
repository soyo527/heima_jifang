#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager(){}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��¼!" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.����˺�          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.�鿴�˺�          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.�鿴����          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.���ԤԼ          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.ע����¼          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << ">��������ѡ��:";
}

//��ʼ������
void Manager::initVector()
{
	//��ȡ��Ϣ
	//ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
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

	cout << "��ǰѧ������Ϊ:" << vStu.size() << endl;
	ifs.close();

	//��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vTea.size() << endl;
	ifs.close();
	
	//������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ:" << vCom.size() << endl;
	ifs.close();
}

//�ظ��˺ż��
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

//����˺�
void Manager::addPerson()
{
	cout << ">����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = ">������ѧ��:";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = ">������ְ�����:";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		//����ظ�
		if (checkRepeat(id, select))
		{
			cout << ">�˺��ظ�,����������:" ;
			continue;
		}		
		break;
	}
	cout << ">����������:" << endl;
	cin >> name;

	cout << ">����������:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
}

//��ʾѧ����Ϣ
void printStudent(Student& s)
{
	cout << "ѧ��: " << s.m_Id << " ����: " << s.m_Name << " ����: " << s.m_Pwd << endl;
}

//��ʾ��ʦ��Ϣ
void printTeacher(Teacher& t)
{
	cout << "ְ����: " << t.m_EmpId << " ����: " << t.m_Name << " ����: " << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << ">��ѡ��鿴����:" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

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

//�鿴������Ϣ
void Manager::showComputer()
{
	for (auto i : vCom)
	{
		cout << "�������: " << i.m_ComId << " �����������: " << i.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}