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

TC- O(N)
SC=O(H)

void findPreSuc(Node* root, Node*& pred, Node*& suc, int key)
{
 
pred= new Node(INT_MIN);
suc= new Node (INT_MAX);
if(!root){
    pred->key= -1;
suc->key= -1;
return;

}
queue<Node * >q;
q.push(root);
while(!q.empty()){
    
    Node * cur= q.front();
    q.pop();
    
    if(cur->key <key && pred->key <cur->key )pred= cur;
    if(cur->key >key && suc->key >cur->key )suc= cur;
    
    if(cur->left)q.push(cur->left);
    if(cur->right)q.push(cur->right);
    
    
}

if(suc->key==INT_MAX)suc->key=-1;
if(pred->key==INT_MIN)pred->key=-1;








// Your code goes here

}
