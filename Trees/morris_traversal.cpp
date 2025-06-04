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

vector<int> morrisInorderTraversal(Node* root) {

    vector<int> ans;

    //left
    //node
    //right

    while(root){

        // Left part doesn't exist
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }

        // Left part exist
        else{
            Node* curr = root->left;
            while(curr->right && curr->right!=root){
                curr = curr->right;
            }
            //Left subtree not traversed
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }
            //Left subtree traversed
            else{
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }

    }

    return ans;

}