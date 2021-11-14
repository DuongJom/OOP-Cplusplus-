#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

class Person {
public:
	char name[31];
	char phone[11];

	Person() {
		strcpy_s(name,sizeof(name), "");
		strcpy_s(phone,sizeof(phone), "");
	}
	void inputInfo() {
		cout << "\tEnter the name: ";
		cin.getline(name, sizeof(name));
		cout << "\tEnter the phone: ";
		cin >> phone;
		cin.ignore();
	}
	void showInfo() {
		cout << "Name: " << name << "\tPhone: " << phone;
	}
};

class Student : public Person {
public:
	char ID[11];
	float mark;
	char rank[15];

	void inputInfo() {
		cout << "\tEnter the ID: ";
		cin >> ID;
		cin.ignore();
		Person::inputInfo();
		cout << "\tEnter the mark: ";
		cin >> mark;
		cin.ignore();
	}
	void showInfo() {
		cout << "ID: " << ID << "\t";
		Person::showInfo();
		cout << "\tMark: " << mark << "\tRank: " << calculateRank() << endl;
	}
	char* calculateRank() {
		if (mark >= 8) {
			strcpy_s(rank,sizeof(rank),"Gioi");
		}
		else if (mark >= 6.5 && mark < 8) {
			strcpy_s(rank, sizeof(rank), "Kha");
		}
		else if (mark >= 5 && mark < 6.5) {
			strcpy_s(rank, sizeof(rank), "Trung binh");
		}
		else {
			strcpy_s(rank, sizeof(rank), "Kem");
		}
		return rank;
	}
};
int main() {
	Student st[MAX];
	int n;
	cout << "Enter number of student: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << "Enter the 1st student: " << endl;
		}
		else {
			cout << "Enter the " << i + 1 << "th student: " << endl;
		}
		st[i].inputInfo();
	}
	for (int i = 0; i < n; i++) {
		st[i].showInfo();
	}
	return 0;
}