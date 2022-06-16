ITERATIVE
tc- O(NO. OF NODES)
sC= o(HEIGHT)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
            TreeNode* cur= st.top().first;
            int state= st.top().second;
            
            st.pop();
            if(!cur)continue;
            if(state==0){
                st.push({cur,1});
                st.push({cur->left,0});
            }
            else if(state==1){
                ans.push_back(cur->val);
                st.push({cur,2});
            }
            else{
                st.push({cur->right,0});
            }
            
        }
        return ans;
    }
};

RECURSIVE

class Solution {
public:
    void inorderhelper(TreeNode *root, vector <int>&v){
        if(!root)return;
        inorderhelper(root->left,v);
        v.push_back(root->val);
        inorderhelper(root->right,v);
        
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector <int> v;
        inorderhelper(root, v);
        
        return v;
        
    }
    
};
