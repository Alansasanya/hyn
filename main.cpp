#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
typedef struct Contact {
	string m_Name;
	int m_Sex;
	//1�� 2Ů
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
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
}
void Addcontact(Books& abs) {
	if (abs.m_Size >= MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		cout << "������ϵ������" << endl;
		cin >> abs.personArray[abs.m_Size].m_Name;
		cout << "������ϵ���Ա�1 �� 2 Ů��" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs.personArray[abs.m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "������ϵ������" << endl;
		cin >> abs.personArray[abs.m_Size].m_Age;
		cout << "������ϵ�˵绰" << endl;
		cin >> abs.personArray[abs.m_Size].m_Phone;
		cout << "������ϵ�˵�ַ" << endl;
		cin >> abs.personArray[abs.m_Size].m_Address;
		abs.m_Size++;
		cout << "�ɹ������ϵ��" << endl;
		system("pause");
		system("cls");
	}
}
void showMenber(Books abs) {
	if (abs.m_Size == 0)
		cout << "��ǰͨѶ¼Ϊ��" << endl;
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
		cout << "��ǰͨѶ¼Ϊ�գ��޷�ɾ��" << endl;
	else {
		cout << "������Ҫɾ������Ա����" << endl;
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
				cout << "����ϵ�˲�������ͨѶ¼��" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void findemember(Books abs) {
	if (abs.m_Size == 0)
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	else {
		cout << "������Ҫ���ҵ���Ա����" << endl;
		string del;
		cin >> del;
		for (int i = 0; i < abs.m_Size; i++) {
			if (del == abs.personArray[i].m_Name) {
				cout << abs.personArray[i].m_Name << " " << abs.personArray[i].m_Sex << " " << abs.personArray[i].m_Age << " " << abs.personArray[i].m_Phone << " " << abs.personArray[i].m_Address << endl;
			}
			else {
				cout << "����ϵ�˲�������ͨѶ¼��" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void emptymember(Books& abs) {
	abs.m_Size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}
void exchangemember(Books& abs) {
	if (abs.m_Size == 0)
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	else {
		cout << "������Ҫ�޸ĵ���ϵ������" << endl;
		string exchange;
		cin >> exchange;
		for (int i = 0; i < abs.m_Size; i++) {
			if (exchange == abs.personArray[i].m_Name) {
				cout << "������Ҫ�޸ĵ���ϵ�����ԣ�1.���� 2.�Ա� 3.���� 4.�ֻ����� 5.��ַ ���������������˵�" << endl;
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
					cout << "�������µ���ϵ������" << endl;
					cin >> n_name;
					abs.personArray[i].m_Name = n_name;
					cout << "�޸���ϵ�������ɹ�" << endl;
					break;
				case 2:
					cout << "�������µ���ϵ���Ա�" << endl;
					cin >> n_sex;
					abs.personArray[i].m_Sex = n_sex;
					cout << "�޸���ϵ���Ա�ɹ�" << endl;
					break;
				case 3:
					cout << "�������µ���ϵ������" << endl;
					cin >> n_age;
					abs.personArray[i].m_Age = n_age;
					cout << "�޸���ϵ������ɹ�" << endl;
					break;
				case 4:
					cout << "�������µ���ϵ�˵绰����" << endl;

					cin >> n_phone;
					abs.personArray[i].m_Phone = n_phone;
					cout << "�޸���ϵ�˵绰����ɹ�" << endl;
					break;
				case 5:
					cout << "�������µ���ϵ�˵�ַ" << endl;
					cin >> n_address;
					abs.personArray[i].m_Address = n_address;
					cout << "�޸���ϵ�˵�ַ�ɹ�" << endl;
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
				cout << "����ϵ�˲�����" << endl;
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
		case 1://�����ϵ��
			Addcontact(abs);
			break;
		case 2://��ʾ��ϵ��
			showMenber(abs);
			break;
		case 3://ɾ����ϵ��
			deletemember(abs);
			break;
		case 4://������ϵ��
			findemember(abs);
			break;
		case 5://�޸���ϵ��
			exchangemember(abs);
			break;
		case 6://�����ϵ��
			emptymember(abs);
			break;
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}    