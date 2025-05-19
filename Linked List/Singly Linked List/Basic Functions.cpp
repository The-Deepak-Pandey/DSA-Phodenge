#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void traverseLL(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int l = 0;
    while(temp!=nullptr){
        l++;
        temp = temp->next;
    }
    return l;
}

bool searchLL(Node* head, int val){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int main(){

    vector<int> arr = {2, 5, 8, 10, 12};

    Node* head = convertArr2LL(arr);

    // traverseLL(head);
    // cout << lengthOfLL(head);
    // cout << searchLL(head, 2);

    return 0;
}