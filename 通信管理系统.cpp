#include"ͨ�Ź���ϵͳ.h"

//�˵�ҳ��
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

}

void addPerson(Addressbooks* abs)  //�����ϵ��
{
	if (abs->m_Size >= MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�����1���С�����2��Ů" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1||sex==2 )
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������������������" << endl;

		}

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "������绰��" << endl;

		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "������סַ��" << endl;
		string  addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)   //��ʾ��ϵ��
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex ==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
		    cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
		
	}
	system("pause");
	system("cls");

}

int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}

	}
	return -1;
}

void deletePerson(Addressbooks* abs)    //ɾ����ϵ��
{
	cout << "��������Ҫɾ����ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "�鵽����" << endl;
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) //������ϵ��
{
	cout << "���������������" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "����" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "����" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ" << abs->personArray[ret].m_Addr << "\t" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(Addressbooks* abs)  //�޸���ϵ��
{
	cout << "�������޸���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "�������޸ĵ�����" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�1--�С�1--Ů" << endl;
		while (true)
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "��������" << endl;
		}

		cout << "�������޸ĵ�����" << endl;
		int  age;
		cin >>age;
		abs->personArray[ret].m_Age = age;

		cout << "�������޸ĵĵ绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�������޸ĵ�סַ" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Name = add;

		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
		
	}
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pausee");
	system("cls");
}


