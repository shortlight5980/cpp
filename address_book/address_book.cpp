#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

struct Node {//����ڵ�
	Node* pre;
	string name;
	string number;
	Node* next;
	Node(string name, string number) :pre(nullptr),name(name), number(number), next(nullptr) {};
};

//ͨѶ¼������
class AddressBook {
private:
	Node* phead;

public:
	AddressBook() :phead(nullptr) {};

	//β��
	void append(string name,string number) {
		Node* newnode = new Node(name, number);
		if (phead == nullptr)
			phead = newnode;
		else {
			Node* current = phead;
			while (current->next != nullptr)
				current = current->next;
			current->next = newnode;
			newnode->pre = current;
		}
	}
	//������ϵ��
	Node* find(string name) {
		Node* current = phead;
		while (current != nullptr && name.compare(current->name) != 0) {
			current = current->next;
		}
		if (current == nullptr) {
			cout << name << " not found" << endl;
			return nullptr;
		}
		else return current;
	}
	//�޸���ϵ��
	void change(string name) {
		Node* pf = find(name);
		cout << "�������µ�����:";
		cin >> pf->name;
		cout << endl;
		cout << "�������µĺ���:";
		cin >> pf->number;
	}
	//ɾ����ϵ��
	void pop(string name) {
		Node* pf = find(name);
		if (pf == nullptr) return;
		else {
			Node* temp;
			temp = pf;
			pf->pre->next = pf->next;
			pf->next->pre = pf->pre;
			delete pf;
		}
	}

	//��ӡ
	void print() {
		Node* current = phead;
		while (current != nullptr) {
			cout << "Name:" << current->name << " Number:" << current->number << endl;
			current = current->next;
		}
	}
};
//��ӡ�˵�
void PrintMenu() {
	cout << "******************************************" << endl;
	cout << "*******1.�����ϵ��**2.ɾ����ϵ��*******" << endl;
	cout << "*******3.������ϵ��**4.�޸���ϵ��*******" << endl;
	cout << "*******5.��ӡͨѶ¼**6.�˳�ͨѶ¼*******" << endl;
	cout << "******************************************" << endl;
}
int main() {
	AddressBook a1;
	a1.append("lisi", "13900000000");
	a1.append("wangwu", "15900000000");
	a1.append("zhangsan", "12300000000");
	while (true) {
		system("cls");
		PrintMenu();
		int choice;
		cin >> choice;
		switch (choice) {
		case 1://���
		{
			string newname;
			string newnumber;
			cout << "�����������ϵ�˵�����:";
			cin >> newname;
			cout << endl;
			cout << "�����������ϵ�˵ĺ���:";
			cin >> newnumber;
			a1.append(newname, newnumber);
			break;
		}
		case 2://ɾ��
		{
			string name;
			cout << "������Ҫɾ����ϵ�˵�����:" ;
			cin >> name;
			a1.pop(name);
			break;
		}
		case 3://����
		{
			string name;
			cout << "������Ҫ������ϵ�˵�����:" ;
			cin >> name;
			Node* pf = a1.find(name);
			if (pf != nullptr)
				cout << "Number:" << pf->number << endl;
			system("pause");
			break;
		}
		case 4://�޸�
		{
			string name;
			cout << "������Ҫ�޸���ϵ�˵�����:" ;
			cin >> name;
			a1.change(name);
			break;
		}
		case 5://��ӡ
			a1.print();
			system("pause");
			break;
		case 6://�˳�
			cout << "��ӭ�´�ʹ��!"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "ѡ�����������ѡ��" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}