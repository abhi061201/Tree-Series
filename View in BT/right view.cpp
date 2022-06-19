/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>

vector<int> printRightView(BinaryTreeNode<int>* root) {
  vector<int>v;
    if(!root)return v;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0 ; i<n ; i++){
            BinaryTreeNode<int>*cur= q.front();
            q.pop();
            if(i==n-1)v.push_back(cur->data);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
    }
    return v;
}
