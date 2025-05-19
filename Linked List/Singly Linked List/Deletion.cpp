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


Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = nullptr;
    delete temp2;
    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head==nullptr) return head;
    if(k==1) return deleteHead(head);
    Node* temp = head;
    int cnt = 1;
    Node* prev;
    while(cnt!=k && temp!=nullptr){
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    prev->next = temp->next;
    delete(temp);
    return head;
}

Node* deleteValue(Node* head, int val){
    if(head->data == val) return deleteHead(head);
    Node* temp = head;
    int curVal = temp->data;
    Node* prev;
    while(curVal!=val && temp!=nullptr){
        prev =temp;
        temp = temp->next;
        curVal = temp->data;
    }
    prev->next = temp->next;
    delete(temp);
    return head;
}


int main() {
    vector<int> arr = {2, 5, 3, 8, 4}; 
    Node* head = convertArr2LL(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthElement(head, 6);
    head = deleteValue(head, 4);

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