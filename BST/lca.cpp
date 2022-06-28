Iterative code:

TC- O(H)
SC- o(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(p->val > q->val)swap(p,q);
        while((root->val> p->val&& root->val > q->val) || (root->val< p->val && root->val < q->val)){
            if(root->val > p->val&& root->val > q->val)root= root->left;
            else root=root->right;
        }
        return root;
            
    }
};



Recursive code

TC- O(H)
SC- O(H) - AST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)return root;
        if(root->val > p->val && root->val > q->val)return lowestCommonAncestor(root->left , p , q); 
        if(root->val <p->val && root->val <q-> val )return lowestCommonAncestor(root->right , p,q ); 
        return root; 
        
            
    }
};
