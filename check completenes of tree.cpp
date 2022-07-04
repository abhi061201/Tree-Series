Approach 1

      Hme agr null k baad bhi queue m element mill rhe h to complete tree nhi hoga vo
      
      
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        if(!root)return 1;
        queue<TreeNode*>q; 
        q.push(root); 
        bool nullmila= false;
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(!cur){
                nullmila=true;
            }
            else {
                if(nullmila)return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
        
    }
};





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
#define pb push_back
class Solution {
public:
      int n=0;
    bool isCompleteTree(TreeNode* root) {
        if(!root)return 1;
        queue<TreeNode*>q;
        q.push(root);
       
       int node=0;
       while(!q.empty()){
           TreeNode* cur= q.front();
           q.pop();
           node++;
           if(!cur->left)break;
           else q.push(cur->left);
           if(!cur->right)break;
           else q.push(cur->right);
       }
         
        preorder(root);
        // cout<<node<<" , "<<n;
      return node+q.size()==n;
        
    }
    void preorder(TreeNode* root){
        if(!root)return ;
        n++;
        preorder(root->left);
        preorder(root->right);
    }

        
};





