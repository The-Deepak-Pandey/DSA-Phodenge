#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr);

Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head->back = newNode;
    return newNode;
}

Node* insertAtTheEnd(Node* head, int val){
    Node* newNode = new Node(val);
    if(head==nullptr) return newNode;
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
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
    newNode->back = prev;
    newNode->next = temp;
    if(temp != nullptr) {
        temp->back = newNode;
    }
    return head;
}

Node* insertBeforeValueX(Node* head, int val, int x){
    if(head==nullptr) return head;
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp!=nullptr && temp->data!=x){
        temp = temp->next;
    }
    if(temp==nullptr) return head;
    if(temp->back!=nullptr) {
        temp->back->next = newNode;
    } else {
        head = newNode;
    }
    newNode->back = temp->back;
    newNode->next = temp;
    temp->back = newNode;
    return head;
}

int main(){
    vector<int> arr = {2, 8, 4, 6, 5};
    Node* head = convertArr2DLL(arr);

    head = insertBeforeHead(head, 1);
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}



Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}