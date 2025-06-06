#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }

};

Node* insertIntoBST(Node* root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        // right part me insert kardiyo
        root->right = insertIntoBST(root->right, data);
    }
    else{
        // left part me insert krna hai
        root->left = insertIntoBST(root->left, data);
    }

    return root;

}

Node* searchInBST(Node* root, int val){

    while(root != NULL && root->data != val){
        if(root->data > val){
            root = root->left;
        } else{
            root = root->right;
        }
    }

    return root;

}

Node* findMin(Node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(root->data == key){
        //0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //1 child left
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child right
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        else{
            int mini = findMin(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
        }
        
    }

    else if(root->data > key){
        root->left = deleteNode(root->left, key);
    }

    else{
        root->right = deleteNode(root->right, key);
    }

    return root;
}

int main(){

    Node* root = NULL;

}