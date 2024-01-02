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
		cout << "学生学号为:" << id << endl;
		cout << "学生姓名为:" << name << endl;
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