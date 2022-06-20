TC- O(N)
SC- O(N)

 #include<bits/stdc++.h>
 vector<int>ans;
 bool go(TreeNode* root, int n, vector<int> v){
     if(!root)return 0;
     v.push_back(root->val);
     if(root->val==n){ans=v;return 1;}
     if( go(root->left,n,v) || go(root->right, n,v) )return 1;
     v.pop_back();
     return 0;
 }


vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> v;
 if(!root)return {};
 go(root, B, v);   
    
    return ans;
}
