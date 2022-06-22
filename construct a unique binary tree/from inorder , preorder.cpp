TC- O(N)
SC- O(N) + AST(O(h))  
class Solution {
public:
    unordered_map<int, int>indexmap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        for(int i=0 ; i<inorder.size() ; i++){
            indexmap[inorder[i]]=i;
        }
        return go(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
    }
TreeNode* go(vector<int>& preorder,int prestart, int preend, vector<int>& inorder,int instart, int inend  ){

    if(prestart>preend || instart> inend)return NULL;
    TreeNode* root= new TreeNode(preorder[prestart]);
    int indexroot = indexmap[root->val];
    int countleft= indexroot- instart;
    root->left = go(preorder,prestart+1,prestart+countleft, inorder, instart, indexroot-1 );
    root->right= go(preorder, prestart+countleft+1, preend, inorder, indexroot+1, inend);
    
        
        return root;
}
};
