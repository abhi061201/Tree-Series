TC- O(N)
SC- O(N) AST
*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    
    if(!root)return ;
    int t=0;
    if(root->left){
        t+= root->left->data;
        
    }
    if(root->right){
        t+=root->right->data;
        
    }
    if(root->data > t){
        if(root->left)root->left->data=root->data;
        if(root->right)root->right->data= root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    t=0;
    if(root->left){
        t+= root->left->data;
    }
    if(root->right){
        t+=root->right->data;
    }
    if(root->left || root->right)root->data= t;
    
    
}  
