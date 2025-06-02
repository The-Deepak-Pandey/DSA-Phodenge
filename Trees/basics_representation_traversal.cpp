#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// Reccursive Traversal Functions

void preOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right); 
}

void inOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

//Iterative Traversal Functions

vector<int> iterativePreorderTraversal(Node* A) {
    vector<int> ans;
    stack<Node*> st;
    st.push(A);
    
    while(!st.empty()){
        Node* topNode = st.top();
        st.pop();
        ans.push_back(topNode->data);
        if(topNode->right){
            st.push(topNode->right);
        }
        if(topNode->left){
            st.push(topNode->left);
        }
    }
    
    return ans;
}

vector<int> iterativeInorderTraversal(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    
    while(true){
        if(curr){
            st.push(curr);
            curr = curr->left;
        } 
        else{
            if(st.empty()) return ans;
            Node* topNode = st.top();
            ans.push_back(topNode->data);
            st.pop();
            curr = topNode->right;
        }
    }
    
    return ans;
}

vector<int> iterativePostorderTraversal(Node* A) {
     vector<int> ans;
    stack<Node*> st;
    st.push(A);
    
    while(!st.empty()){
        Node* topNode = st.top();
        st.pop();
        ans.push_back(topNode->data);
        if(topNode->left){
            st.push(topNode->left);
        }
        if(topNode->right){
            st.push(topNode->right);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

void levelOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* topNode = q.front();
        q.pop();
        cout << topNode->data << " ";
        if(topNode->left != nullptr){
            q.push(topNode->left);
        }
        if(topNode->right != nullptr){
            q.push(topNode->right);
        }
    }
}

int main() {
    // Create a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}