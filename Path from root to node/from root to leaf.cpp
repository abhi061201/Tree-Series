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
class Solution {
public:
    vector<string >ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {};
        
        go(root,to_string(root->val));
        
        return ans;
    }
    void go(TreeNode* root, string s){
        if(!root->left && !root->right){
           
            ans.push_back(s);
            return ;
        }
       
       if(root->left) go(root->left, s +"->"+to_string(root->left->val));
        if(root->right)go(root->right, s +"->"+to_string(root->right->val));
        
        
        
    }
};
