#include<iostream>
using namespace std;
#include<string>
#define MAX 1000  //人数设置

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];   // 人数设置
	int m_Size;               //记录通讯录人数
};

void showMenu();
void addPerson(Addressbooks* abs);
void showPerson(Addressbooks* abs);
int isExist(Addressbooks* abs, string name);
void deletePerson(Addressbooks* abs);
void findPerson(Addressbooks* abs);
void changePerson(Addressbooks* abs);
void cleanPerson(Addressbooks* abs);

int main()
{
	int select = 0;
	Addressbooks abs;
	abs.m_Size = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //1、添加联系人 
			addPerson(&abs);
			break;
		case 2:  //2、显示联系人
			showPerson(&abs);
			break;
		case 3:  //3、删除联系人	
			deletePerson(&abs);
			break;
		case 4:  //4、查找联系人
			findPerson(&abs);
			break;
		case 5:  //5、修改联系人
			changePerson(&abs);
			break;
		case 6:  //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:  //0、退出通讯录 
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	showMenu();
	system("pause");
	return 0;
}
