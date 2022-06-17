/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TC- O(n)
SC= O(height)=O(n)in worst case
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
            if((!p && q)||(!q && p))return 0; 
            if(!q && !p)return 1;
         if( p->val!=q->val )return 0;
        return  isSameTree( p->left, q->left) &  isSameTree( p->right,  q->right);
       
        
    }
};
