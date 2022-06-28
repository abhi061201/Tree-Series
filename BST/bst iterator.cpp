TC~ O(1)
sc= o(H)
  

class BSTIterator {
    
    private :stack <TreeNode*>st;
    public:
    
    BSTIterator(TreeNode* root) {
        
      while(root){
          st.push (root);
          root=root->left;
      }
        
    }
    
    int next() {
        
        TreeNode * cur= st.top();
        st.pop();
        int x= cur->val;
        cur= cur->right;
        while(cur){
            st.push(cur);
            cur= cur->left;
        }
        return x;
    }
    
    bool hasNext() {
        return st.size();
    }
};


BY STORING INORDER

Tc= o(1)
sc= o(N)
  
  
class BSTIterator {
public:
    int i=0;
    vector<int>v;
    TreeNode*node= new TreeNode(-1);
    BSTIterator(TreeNode* root) {
        node=root;
        inorder(node);
        
        
    }
    
    int next() {
         
        return v[i++];
       
    }
    
    bool hasNext() {
       return i<v.size();
    }
    void inorder( TreeNode*root){
        if(!root)return ;
        inorder( root->left);
        v.push_back(root->val);
        inorder( root->right);
        
    }
};



