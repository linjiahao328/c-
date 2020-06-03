#include<iostream>
using namespace std;
#include<string>
#define MAX 1000  //��������

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
	struct Person personArray[MAX];   // ��������
	int m_Size;               //��¼ͨѶ¼����
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
		case 1:  //1�������ϵ�� 
			addPerson(&abs);
			break;
		case 2:  //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //3��ɾ����ϵ��	
			deletePerson(&abs);
			break;
		case 4:  //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:  //5���޸���ϵ��
			changePerson(&abs);
			break;
		case 6:  //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:  //0���˳�ͨѶ¼ 
			cout << "��ӭ�´�ʹ��" << endl;
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
