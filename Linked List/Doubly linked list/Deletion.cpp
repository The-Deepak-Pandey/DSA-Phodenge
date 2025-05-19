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

Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    head = head->next;
    if(head != nullptr) {
        head->back = nullptr;
    }
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
    if(temp == nullptr) return head; // If k is greater than the length of the list
    prev->next = temp->next;
    if(temp->next != nullptr) {
        temp->next->back = prev;
    }
    delete(temp);
    return head;
}

Node* deleteValue(Node* head, int val){
    if(head==nullptr) return head;
    Node* temp = head;
    while(temp!=nullptr && temp->data!=val){
        temp = temp->next;
    }
    if(temp == nullptr) return head; // Value not found
    if(temp == head) return deleteHead(head);
    Node* prev = temp->back;
    prev->next = temp->next;
    if(temp->next != nullptr) {
        temp->next->back = prev;
    }
    delete(temp);
    return head;
}

int main(){
    vector<int> arr = {2, 8, 4, 6, 5};
    Node* head = convertArr2DLL(arr);
    
    // head = deleteHead(head);
    head = deleteTail(head);

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
