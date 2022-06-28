TC= o(H+H)
Sc= O(1)  

void gopre(Node* root, int key, Node*& pre, Node*& suc){
    
    if(!root)return;
    if(root->key < key){pre=root; gopre(root->right, key,pre,suc);}
    else gopre(root->left, key,pre,suc);
    
    
}
void gosuc(Node* root, int key, Node*& pre, Node*& suc){
    
    if(!root)return;
    if(root->key > key){suc=root; gosuc(root->left, key,pre,suc);}
    else gosuc(root->right, key,pre,suc);
    
    
}
void findPreSuc(Node* root, Node*& Pre, Node*& Suc, int key)
{
   
    gopre(root, key,Pre,Suc);
    gosuc(root, key,Pre,Suc);

}
