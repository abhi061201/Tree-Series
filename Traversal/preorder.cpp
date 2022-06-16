ITERATIVE PREORDER
TC-O(n)
 SC- O(N)

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
 very easy approach can done all iterative by this
 iterative by raveet sir
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<pair<TreeNode* , int>> st;
        vector<int>ans;
        st.push({root,0});
        while(!st.empty()){
            TreeNode* cur= st.top().first;
            int state= st.top().second;
            st.pop();
            if(!cur)continue;
            if(state==0){
                ans.push_back(cur->val);
                st.push({cur,1});
            }
            else if(state==1){
                st.push({cur,2});
                st.push({cur->left,0});
            }
            else {
                st.push({cur->right,0});
            }
            
        }
        return ans;
    }
};

Iterative striver
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return{};
        stack<TreeNode*>st;
        vector<int>ans;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* cur= st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->right)st.push(cur->right);
            if(cur->left)st.push(cur->left);
            
        }
        return ans;
        
    }
};

RECURSIVE
TC- O(N)
SC- O(N)-ast

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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        pre(root,ans);
     return ans;   
    }
    void pre(TreeNode* root,  vector<int>&ans){
        if(!root)return;
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);
    }
};
