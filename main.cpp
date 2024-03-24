#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
typedef struct Contact {
	string m_Name;
	int m_Sex;
	//1男 2女
	int m_Age;
	string m_Phone;
	string m_Address;
}Contact;
typedef struct Books {
	Contact personArray[MAX];
	int m_Size;
};
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
}
void Addcontact(Books& abs) {
	if (abs.m_Size >= MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		cout << "输入联系人姓名" << endl;
		cin >> abs.personArray[abs.m_Size].m_Name;
		cout << "输入联系人性别（1 男 2 女）" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs.personArray[abs.m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "输入联系人年龄" << endl;
		cin >> abs.personArray[abs.m_Size].m_Age;
		cout << "输入联系人电话" << endl;
		cin >> abs.personArray[abs.m_Size].m_Phone;
		cout << "输入联系人地址" << endl;
		cin >> abs.personArray[abs.m_Size].m_Address;
		abs.m_Size++;
		cout << "成功添加联系人" << endl;
		system("pause");
		system("cls");
	}
}
void showMenber(Books abs) {
	if (abs.m_Size == 0)
		cout << "当前通讯录为空" << endl;
	else {
		for (int i = 0; i < abs.m_Size; i++) {
			cout << abs.personArray[i].m_Name << " " << abs.personArray[i].m_Sex << " " << abs.personArray[i].m_Age << " " << abs.personArray[i].m_Phone << " " << abs.personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}
void deletemember(Books& abs) {
	if (abs.m_Size == 0)
		cout << "当前通讯录为空，无法删除" << endl;
	else {
		cout << "请输入要删除的人员名字" << endl;
		string del;
		cin >> del;
		for (int i = 0; i < abs.m_Size; i++) {
			if (del == abs.personArray[i].m_Name) {
				for (int j = i; j < abs.m_Size; j++) {
					abs.personArray[j] = abs.personArray[j + 1];
				}
				abs.m_Size--;
			}
			else {
				cout << "该联系人不存在再通讯录中" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void findemember(Books abs) {
	if (abs.m_Size == 0)
		cout << "当前通讯录为空" << endl;
	else {
		cout << "请输入要查找的人员名字" << endl;
		string del;
		cin >> del;
		for (int i = 0; i < abs.m_Size; i++) {
			if (del == abs.personArray[i].m_Name) {
				cout << abs.personArray[i].m_Name << " " << abs.personArray[i].m_Sex << " " << abs.personArray[i].m_Age << " " << abs.personArray[i].m_Phone << " " << abs.personArray[i].m_Address << endl;
			}
			else {
				cout << "该联系人不存在再通讯录中" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void emptymember(Books& abs) {
	abs.m_Size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}
void exchangemember(Books& abs) {
	if (abs.m_Size == 0)
		cout << "当前通讯录为空" << endl;
	else {
		cout << "请输入要修改的联系人姓名" << endl;
		string exchange;
		cin >> exchange;
		for (int i = 0; i < abs.m_Size; i++) {
			if (exchange == abs.personArray[i].m_Name) {
				cout << "请输入要修改的联系人属性：1.姓名 2.性别 3.年龄 4.手机号码 5.地址 按其他键返回主菜单" << endl;
				int slect;
				cin >> slect;
				string n_name;
				int n_age;
				int n_sex;
				string n_address;
				string n_phone;
				switch (slect)
				{
				case 1:
					cout << "请输入新的联系人姓名" << endl;
					cin >> n_name;
					abs.personArray[i].m_Name = n_name;
					cout << "修改联系人姓名成功" << endl;
					break;
				case 2:
					cout << "请输入新的联系人性别" << endl;
					cin >> n_sex;
					abs.personArray[i].m_Sex = n_sex;
					cout << "修改联系人性别成功" << endl;
					break;
				case 3:
					cout << "请输入新的联系人年龄" << endl;
					cin >> n_age;
					abs.personArray[i].m_Age = n_age;
					cout << "修改联系人年龄成功" << endl;
					break;
				case 4:
					cout << "请输入新的联系人电话号码" << endl;

					cin >> n_phone;
					abs.personArray[i].m_Phone = n_phone;
					cout << "修改联系人电话号码成功" << endl;
					break;
				case 5:
					cout << "请输入新的联系人地址" << endl;
					cin >> n_address;
					abs.personArray[i].m_Address = n_address;
					cout << "修改联系人地址成功" << endl;
					break;
				default:
					system("pause");
					system("cls");
					return;
				}
				break;
			}
			else
			{
				cout << "该联系人不存在" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
int main() {
	Books abs;
	abs.m_Size = 0;
	int select;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			Addcontact(abs);
			break;
		case 2://显示联系人
			showMenber(abs);
			break;
		case 3://删除联系人
			deletemember(abs);
			break;
		case 4://查找联系人
			findemember(abs);
			break;
		case 5://修改联系人
			exchangemember(abs);
			break;
		case 6://清空联系人
			emptymember(abs);
			break;
		case 0: //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}    