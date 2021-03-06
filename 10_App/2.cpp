// 2.
// Problem: Make a list of names of n students in class
// Solution: Use a linked list to create data containing each student's name and make a list of student names according to the saved data.
// Code:
#include <iostream>
#include <string>

using namespace std;

struct node {
	string name;
	node* next;
};

node* createNode(string st) {
    node* temp = new node;
    temp->next = NULL;
    temp->name = st;
    return temp;
}

void printList(node* head) {
	node* p = head;
	cout << "Student list:" << endl;
	while (p != NULL) {
		cout << p->name << endl;
		p = p->next;
	}
}

node* addElement(node* p, string st) {
	node* temp = createNode(st);
	p->next = temp;
	return temp;
}

int main() {
	int n;
	string st;
	cout << "n= ";
	cin >> n;
	cin.ignore();
	cout << "Student's name: ";
	getline(cin, st);
	node* head = createNode(st);
	node* p = head;
	for (int i = 1; i < n; i++) {
		cout << "Student's name: ";
		getline(cin, st);
		p = addElement(p, st);
	}
	printList(head);
	return 0;
}
