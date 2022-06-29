TC- O(N)
SC= O(1)

class Solution {
public:
    
      TreeNode* first=NULL, * last= NULL, *mid= NULL,*prev;
        
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        inorder(root);
        
        if(first && last)swap(first->val, last->val);
        else  swap (first->val , mid->val);
      
        
    }
    void inorder(TreeNode* root){
        if(root== NULL)return ; 
        inorder(root->left); 
        if(prev && root->val < prev->val ){
            
            if(!first){
                first= prev; 
                mid = root; 
            }
            else {
                last = root; 
            }
           
            
        } prev=root;
        inorder(root->right);
    }
};


TC= O(nlogn +n)
sc= O(N)


class Solution {
public:
    vector<int>v; 
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        vector<int>temp= v;
        sort(v.begin(), v.end());
         int a=-1, b=-1;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i]!=temp[i]){
                a=v[i];
                b= temp[i];
                break;
            }
        }
       
        recover(root, a, b);
        
        
    }
    void inorder(TreeNode* root){
        
        if(root==NULL){
            return ;
        }
        inorder(root->left); 
        v.push_back(root->val);
        inorder(root->right);
        
    }
    void recover(TreeNode* root, int a, int b){
        if(!root)return ;
        recover(root->left,a,b);
        if(root->val==a){
            root->val=b;
        }
        else if(root->val==b)root->val=a;
        recover(root->right, a, b);
    }
   
};
