#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function prototype
Node* convertArr2LL(vector<int> &arr);

Node* insertBeforeHead(Node* head, int val){
    return new Node(val, head);
}

Node* insertAtTheEnd(Node* head, int val){
    Node* newNode = new Node(val);
    if(head==nullptr) return newNode;
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int val, int k){
    if(head==nullptr){
        if(k==1) return insertBeforeHead(head, val);
        else return head;
    }
    if(k==1) return insertBeforeHead(head, val);
    Node* newNode = new Node(val);
    Node* temp = head;
    Node* prev;
    int curK = 1;
    int len = 0;
    while(curK!=k && temp!=nullptr){
        prev = temp;
        temp = temp->next;
        curK++;
        len++;
    }
    if(k > len+1) return head;
    prev->next = newNode;
    newNode->next = temp;
    return head;
}

Node* insertBeforeValueX(Node* head, int val, int x){
    if(head==nullptr) return head;
    if(head->data == x) return insertBeforeHead(head, val);
    Node* newNode = new Node(val);
    Node* temp = head;
    Node* prev;
    int curX = temp->data;
    while(temp != nullptr && curX != x){
        prev = temp;
        temp = temp->next;
        if(temp != nullptr) curX = temp->data;
    }
    if(curX!=x) return head;
    prev->next = newNode;
    newNode->next = temp;
    return head;
}

int main() {
    vector<int> arr = {2, 5, 3, 8, 4}; 
    Node* head = convertArr2LL(arr);

    // head = insertBeforeHead(head, 99);
    // head = insertAtTheEnd(head, 9999);
    // head = insertBeforeKthElement(head, 9999, 6);
    head = insertBeforeValueX(head, 9999, 4);

    // Print the linked list to verify
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}