TC= o(nlogn + N+ N)
 SC= O(N+N+N)


class Solution {
public:
    vector<int>inorder;
    vector<int>preorder;
    map<int, int>mp;
    TreeNode* bstFromPreorder(vector<int>& Preorder) {
        inorder=Preorder;
        preorder  = Preorder; 
        sort (inorder.begin(), inorder.end()); 
        
        int n= inorder.size(); 
        for(int i=0 ; i<n ; i++){
            mp[inorder[i]]=i; 
        }
            return go(0,n-1, 0, n-1);

        
    }
    TreeNode* go(int ps, int pe,int  is,int ie){
        if(ps>pe || is>ie)return 0 ; 
        TreeNode* root= new TreeNode(preorder[ps]);
        int ind= mp[root->val];
        int eleleft = ind- is; 
        
        root->left = go(ps+1, ps+eleleft, is,ind-1);
        root->right= go(ps+eleleft+1,pe, ind+1,ie );
        return root;
        
    }
};
TC- O(3N)
SC=O(1)


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
        return go(i,pre, 1e9 );
        
    }
    TreeNode * go(int &i, vector<int>&pre, int up){
        if(i==pre.size()|| pre[i] > up){
            return NULL;
        }
        TreeNode* root= new TreeNode(pre[i++]);
        root->left= go(i, pre, root->val);
        root->right= go(i, pre, up);
        return root;
    }
};
