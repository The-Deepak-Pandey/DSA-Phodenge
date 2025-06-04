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

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> preOrder = iterativePreorderTraversal(root);
    vector<int> inOrder = iterativeInorderTraversal(root);
    vector<int> postOrder = iterativePostorderTraversal(root);
    
    cout << "Pre-order Traversal: ";
    for(int val : preOrder) cout << val << " ";
    cout << endl;
    
    cout << "In-order Traversal: ";
    for(int val : inOrder) cout << val << " ";
    cout << endl;
    
    cout << "Post-order Traversal: ";
    for(int val : postOrder) cout << val << " ";
    cout << endl;

    return 0;
}