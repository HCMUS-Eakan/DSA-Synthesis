// 4.
// Problem: A supermarket checkout counter serves more than n people per day. Write a chapter that makes payments to each person and calculates the total proceeds, knowing the value-added tax is 10%.
// Solution: Due to the supermarket's payment method, "first in, first out". Therefore, we create a queue with 3 operations adding n elements, taking n elements out and checking if the queue is empty (full of people)
// Code:
#include <iostream>
#include <ctime>

using namespace std;

struct node {
    int data;
	node* next;
};

node* createNode(int x) {
    node* temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

bool isEmpty(node* Q) {
    if (Q == NULL) 
        return true;
    return false;
}

void enQueue(node*& q, node*& t, int k) {
    node* p = createNode(k);
    if (q == NULL)
        q = t = p;
    else {
        t->next = p;
        t = p;
    }
}

node* deQueue(node*& q, node*& t, int& S) {
    node* p;
    if (isEmpty(q)) 
        return NULL;
    p = q;
    if (q == t)
        q = t = NULL;
    else {
        S = S + q->data;
        q = q->next;
    }
    p->next = NULL;
    return p;
}

int main(){
    srand((int)time(0));
    int n, x, S = 0;
    cout << "n= ";
    cin >> n;
    node* q = NULL, * t = NULL;
    for (int i = 0; i < n; i++) {
        x = rand() % 1000000;
        enQueue(q, t, x);
    }
    for (int i = 0; i < n; i++)
        deQueue(q, t, S);
    S = S * 1.1;
    bool flag = isEmpty(q);
    if (flag) {
        cout << "End of payment queue." << endl;
        cout << "Total amount: " << S << endl;
    }
    return 0;
}
