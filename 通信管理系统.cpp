#include"通信管理系统.h"

//菜单页面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}

void addPerson(Addressbooks* abs)  //添加联系人
{
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：数字1是男、数字2是女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1||sex==2 )
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "你输入有误，请重新输入" << endl;

		}

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "请输入电话：" << endl;

		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入住址：" << endl;
		string  addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)   //显示联系人
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为零" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex ==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
		    cout << "住址：" << abs->personArray[i].m_Addr << endl;
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

void deletePerson(Addressbooks* abs)    //删除联系人
{
	cout << "请输入你要删除联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "查到此人" << endl;
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) //查找联系人
{
	cout << "请输入查找人姓名" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名" << abs->personArray[ret].m_Name << "\t";
		cout << "性别" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄" << abs->personArray[ret].m_Age << "\t";
		cout << "电话" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址" << abs->personArray[ret].m_Addr << "\t" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(Addressbooks* abs)  //修改联系人
{
	cout << "请输入修改联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入修改的姓名" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：1--男、1--女" << endl;
		while (true)
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "重新输入" << endl;
		}

		cout << "请输入修改的年龄" << endl;
		int  age;
		cin >>age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入修改的电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入修改的住址" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Name = add;

		cout << "修改成功" << endl;
		system("pause");
		system("cls");
		
	}
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已经清空" << endl;
	system("pausee");
	system("cls");
}


