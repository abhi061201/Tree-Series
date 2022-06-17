Coding ninja 
TC- O(n)
SC - O(!)
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root)return{};
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> * cur= q.front();
        q.pop();
        ans.push_back(cur->val);
        if(cur->left)q.push(cur->left);
        if(cur->right)q.push(cur->right);
    }
   return ans;
}
