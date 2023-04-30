#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct addressperson
{
	string name;//��ϵ������
	string number;//��ϵ�˺���
	int sex;//��ϵ���Ա� 1��2Ů
	int age;//��ϵ������
	string address;//��ϵ�˵�ַ
};
struct addressbooks
{
	addressperson people[MAX];//��ϵ������
	int size;
};
void showmenu()//�˵�����
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
void addperson(addressbooks *abs)//�����ϵ��
{
		if (abs->size == MAX)
		{
			cout << "��ϵ���������޷����" << endl;
			return;
		}
		else
		{
			string name;
			cout << "��������ϵ������" << endl;
			cin >> name;
			abs->people[abs->size].name = name;
			string number;
			cout << "��������ϵ�˵绰" << endl;
			cin >> number;
			abs->people[abs->size].number = number;
			int sex = 0;
			cout << "��������ϵ���Ա�  1.��  2.Ů" << endl;
			while (1)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->people[abs->size].sex = sex;
					break;
				}
				else
				{
					cout << "����������" << endl;

				}
			}
			int age = 0;
			cout << "��������ϵ������" << endl;
			cin >> age;
			abs->people[abs->size].age = age;
			string address;
			cout << "��������ϵ�˵�ַ" << endl;
			cin >> address;
			abs->people[abs->size].address = address;
			cout << "��ӳɹ�" << endl;
			abs->size++;
		}	
		
}
void showperson(addressbooks *abs)//��ʾ��ϵ��
{
	if (abs->size ==0)
	{
		cout << "��ǰ����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout <<"������"<< abs->people[i].name<<"\t"  ;
			cout<<"���룺"<<abs->people[i].number<<"\t"  ;
			cout<<"�Ա�"<<(abs->people[i].sex==1?"��":"Ů")<<"\t"  ;//��Ŀ�����
			cout << "���䣺"<<abs->people[i].age <<"\t" ;
			cout << "��ַ��"<<abs->people[i].address << endl;
		}
	}
}
int isexist(addressbooks* abs, string name)//�����ϵ���Ƿ����
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->people[i].name == name)
		{
			return i;//���ھ������ϵ�˵Ĵ洢λ�ã�ʵ�ʻ��ڣ��洢����ϵ�˲Żᱻ�û���������ʾ��ϵ�˲���ʱ������֣���Ϊsize--�ˣ����Բ��ᱻ��ʾ������
		}
	}		
	return -1;		
}
void deleteperson(addressbooks* abs)//ɾ����ϵ��
{
	string name;
			cout << "�������ɾ��������" << endl;
			cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->people[i] = abs->people[i + 1];
		}
		abs->size--;//�Ų�����������ͬ
			cout << "��ɾ��" << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void findperson(addressbooks* abs)//������ϵ��
{
	string name;
	cout << "��������ϵ������" << endl;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->people[ret].name;
		cout << "���룺" << abs->people[ret].number;
		cout << "�Ա�" << (abs->people[ret].sex == 1 ? "��" : "Ů");//��Ŀ�����
		cout << "���䣺" << abs->people[ret].age;
		cout << "��ַ��" << abs->people[ret].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void modifyperson(addressbooks* abs)//�޸���ϵ��
{
	string name;
	string number;
	int sex;
	int age;
	string address;
	cout << "��������ϵ������" << endl;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout<<"�������޸ĺ���ϵ������" << endl;
		cin >> name;
		abs->people[ret].name = name;
		cout<<"�������޸ĺ���ϵ�˺���" << endl;
		cin >> number;
		abs->people[ret].number=number;
		cout<<"�������޸ĺ���ϵ���Ա�" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->people[ret].sex = sex;
				break;
			}
			else
			{
				cout << "�����������޸ĺ���ϵ���Ա�" << endl;
			}
		}
		cout<<"�������޸ĺ���ϵ������" << endl;
		cin >> age;
		abs->people[ret].age = age;
		cout<<"�������޸ĺ���ϵ�˵�ַ" << endl;
		cin >> address;
		abs->people[ret].address = address;
	}
}
void cleanperson(addressbooks* abs)//�����ϵ��
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
}
int main()
{
	int select = 0;
	addressbooks abs;
	abs.size = 0;
	while (1)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://���ͨѶ¼
			cleanperson(&abs);
			break;
		case 0://�˳�����
			cout << "��ӭ�´�ʹ��!" << endl;
		system("pause");
		return 0;
		}
		system("pause");
			system("cls");
	}
	
	system("pause");
	return 0;
}