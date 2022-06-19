/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getLeftView(TreeNode<int> *root)
{
  vector<int>v;
    if(!root)return v;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0 ; i<n ; i++){
            TreeNode<int>*cur= q.front();
            q.pop();
            if(i==0)v.push_back(cur->data);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
    }
    return v;
}
