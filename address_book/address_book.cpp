#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

struct Node {//链表节点
	Node* pre;
	string name;
	string number;
	Node* next;
	Node(string name, string number) :pre(nullptr),name(name), number(number), next(nullptr) {};
};

//通讯录链表类
class AddressBook {
private:
	Node* phead;

public:
	AddressBook() :phead(nullptr) {};

	//尾插
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
	//查找联系人
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
	//修改联系人
	void change(string name) {
		Node* pf = find(name);
		cout << "请输入新的姓名:";
		cin >> pf->name;
		cout << endl;
		cout << "请输入新的号码:";
		cin >> pf->number;
	}
	//删除联系人
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

	//打印
	void print() {
		Node* current = phead;
		while (current != nullptr) {
			cout << "Name:" << current->name << " Number:" << current->number << endl;
			current = current->next;
		}
	}
};
//打印菜单
void PrintMenu() {
	cout << "******************************************" << endl;
	cout << "*******1.添加联系人**2.删除联系人*******" << endl;
	cout << "*******3.查找联系人**4.修改联系人*******" << endl;
	cout << "*******5.打印通讯录**6.退出通讯录*******" << endl;
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
		case 1://添加
		{
			string newname;
			string newnumber;
			cout << "请输入添加联系人的姓名:";
			cin >> newname;
			cout << endl;
			cout << "请输入添加联系人的号码:";
			cin >> newnumber;
			a1.append(newname, newnumber);
			break;
		}
		case 2://删除
		{
			string name;
			cout << "请输入要删除联系人的姓名:" ;
			cin >> name;
			a1.pop(name);
			break;
		}
		case 3://查找
		{
			string name;
			cout << "请输入要查找联系人的姓名:" ;
			cin >> name;
			Node* pf = a1.find(name);
			if (pf != nullptr)
				cout << "Number:" << pf->number << endl;
			system("pause");
			break;
		}
		case 4://修改
		{
			string name;
			cout << "请输入要修改联系人的姓名:" ;
			cin >> name;
			a1.change(name);
			break;
		}
		case 5://打印
			a1.print();
			system("pause");
			break;
		case 6://退出
			cout << "欢迎下次使用!"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "选择出错，请重新选择" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}