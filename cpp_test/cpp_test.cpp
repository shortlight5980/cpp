#include<iostream>
#include<string>
using namespace std;
class student {
public:
	string name;
	int id;
	char gender;
	void inname() {
		cin >> name;
	}
	void inid() {
		cin >> id;
	}
	void print() {
		cout << "ѧ��ѧ��Ϊ:" << id << endl;
		cout << "ѧ������Ϊ:" << name << endl;
	}
};
int main() {
	student s1;
	s1.inid();
	s1.inname();
	s1.print();
	system("pause");
	return 0;
}