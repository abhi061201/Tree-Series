TC--O(N) amortised tc since at every node we go to left sub tree rightmost guy therefore we have to traverse extra every time to left there fore it is no
proper O(N) its like 1 + 2+4+ any left node ...approximately o(N)
SC--O(1)


vector<int> Solution::inorderTraversal(TreeNode* A) {

TreeNode* cur= A;
vector<int>ans;
while(cur){
    if(cur->left){
        TreeNode* prev= cur->left;
        while(prev->right && prev->right!=cur){
            prev= prev->right;
        }
        if(!prev->right){
            prev->right=cur;
            cur= cur->left;
        }
        else {
            prev->right=NULL;
            ans.push_back(cur->val);
            cur=cur->right;
        }
    }
    else {
        ans.push_back(cur->val);
        cur= cur->right;
    }
}
return ans;

}
