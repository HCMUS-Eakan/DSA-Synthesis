// 8.
// Problem: Find the present age of n people. Find the largest and smallest number of ages without sorting.
// Solution: Build a binary search tree, find the last leaf on the left branch and the last leaf on the right branch corresponding to the minimum and maximum age to find.
// Code:
#include <iostream>
#include <ctime>

using namespace std;

typedef struct node {
	int data;
	node* left;
	node* right;
}NodeType;

void insert(NodeType*& t, int x) {
	if (t == NULL) {
		t = new NodeType;
		t->data = x;
		t->left = NULL;
		t->right = NULL;
	}
	else {
		if (x < t->data) 
			return insert(t->left, x);
		else 
			return insert(t->right, x);
	}
}

int minValue(const NodeType* t) {
	while (t->left != NULL)
		t = t->left;
	return t->data;
}

int maxValue(const NodeType* t) {
	while (t->right != NULL)
		t = t->right;
	return t->data;
}

int main() {
	srand((int)time(0));
	int n, x, min, max;
	cout << "n= ";
	cin >> n;
	NodeType* t = NULL;

	for (int i = 0; i < n; i++) {
		x = rand() % 100 + 1;
		insert(t, x);
	}
	min = minValue(t);
	max = maxValue(t);
	cout << "Minimum age: " << min << endl;
	cout << "Oldest age: " << max << endl;
	return 0;
}
