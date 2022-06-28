
TC= O(N)+O(N)
sc= O(N)+O(H)-ast
class Solution {
public:
    vector<int>v; 
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        
        int i=0, j= v.size()-1;
        
        while(i<j){
            if(v[i]+v[j] == k)return 1;
             if(v[i]+v[j] < k)i++;
             if(v[i]+v[j] > k)j--;
        }
        return 0;
        
    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};
