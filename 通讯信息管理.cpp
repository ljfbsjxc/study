#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct addressperson
{
	string name;//联系人姓名
	string number;//联系人号码
	int sex;//联系人性别 1男2女
	int age;//联系人年龄
	string address;//联系人地址
};
struct addressbooks
{
	addressperson people[MAX];//联系人数组
	int size;
};
void showmenu()//菜单界面
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
void addperson(addressbooks *abs)//添加联系人
{
		if (abs->size == MAX)
		{
			cout << "联系人已满，无法添加" << endl;
			return;
		}
		else
		{
			string name;
			cout << "请输入联系人姓名" << endl;
			cin >> name;
			abs->people[abs->size].name = name;
			string number;
			cout << "请输入联系人电话" << endl;
			cin >> number;
			abs->people[abs->size].number = number;
			int sex = 0;
			cout << "请输入联系人性别  1.男  2.女" << endl;
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
					cout << "请重新输入" << endl;

				}
			}
			int age = 0;
			cout << "请输入联系人年龄" << endl;
			cin >> age;
			abs->people[abs->size].age = age;
			string address;
			cout << "请输入联系人地址" << endl;
			cin >> address;
			abs->people[abs->size].address = address;
			cout << "添加成功" << endl;
			abs->size++;
		}	
		
}
void showperson(addressbooks *abs)//显示联系人
{
	if (abs->size ==0)
	{
		cout << "当前无联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout <<"姓名："<< abs->people[i].name<<"\t"  ;
			cout<<"号码："<<abs->people[i].number<<"\t"  ;
			cout<<"性别："<<(abs->people[i].sex==1?"男":"女")<<"\t"  ;//三目运算符
			cout << "年龄："<<abs->people[i].age <<"\t" ;
			cout << "地址："<<abs->people[i].address << endl;
		}
	}
}
int isexist(addressbooks* abs, string name)//检测联系人是否存在
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->people[i].name == name)
		{
			return i;//存在就输出联系人的存储位置（实际还在，存储新联系人才会被置换，但在显示联系人部分时不会出现，因为size--了，所以不会被显示出来）
		}
	}		
	return -1;		
}
void deleteperson(addressbooks* abs)//删除联系人
{
	string name;
			cout << "请输入待删除者姓名" << endl;
			cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->people[i] = abs->people[i + 1];
		}
		abs->size--;//才不会有两个相同
			cout << "已删除" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void findperson(addressbooks* abs)//查找联系人
{
	string name;
	cout << "请输入联系人姓名" << endl;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->people[ret].name;
		cout << "号码：" << abs->people[ret].number;
		cout << "性别：" << (abs->people[ret].sex == 1 ? "男" : "女");//三目运算符
		cout << "年龄：" << abs->people[ret].age;
		cout << "地址：" << abs->people[ret].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void modifyperson(addressbooks* abs)//修改联系人
{
	string name;
	string number;
	int sex;
	int age;
	string address;
	cout << "请输入联系人姓名" << endl;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout<<"请输入修改后联系人姓名" << endl;
		cin >> name;
		abs->people[ret].name = name;
		cout<<"请输入修改后联系人号码" << endl;
		cin >> number;
		abs->people[ret].number=number;
		cout<<"请输入修改后联系人性别" << endl;
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
				cout << "请重新输入修改后联系人性别" << endl;
			}
		}
		cout<<"请输入修改后联系人年龄" << endl;
		cin >> age;
		abs->people[ret].age = age;
		cout<<"请输入修改后联系人地址" << endl;
		cin >> address;
		abs->people[ret].address = address;
	}
}
void cleanperson(addressbooks* abs)//清空联系人
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
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
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空通讯录
			cleanperson(&abs);
			break;
		case 0://退出程序
			cout << "欢迎下次使用!" << endl;
		system("pause");
		return 0;
		}
		system("pause");
			system("cls");
	}
	
	system("pause");
	return 0;
}