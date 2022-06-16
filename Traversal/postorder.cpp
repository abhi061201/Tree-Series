iterative 
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root)return {};
        stack<pair<TreeNode* , int>>st;
        vector<int>ans;
        st.push({root,0});
        while(!st.empty()){
            TreeNode* cur= st.top().first;
            int state= st.top().second;a
            st.pop();
            if(!cur)continue;
            if(state==0){
                st.push({cur,1});
                st.push({cur->left,0});
            }
            else if(state==1){
                st.push({cur,2});
                st.push({cur->right,0});
                
            }
            else {
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};

recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
    void postorder(TreeNode* root,vector<int>&ans ){
        if(!root)return ;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
        
    }
};
