TC- O(N)
SC- O(N+N+N)--- vector, map, AST


#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    if(!root)return {};
    vector<int>ans;
    map <int ,int >mp;
    queue<pair<TreeNode<int>*, int>>q;
    q.push({root,0});
    while(!q.empty()){
       TreeNode<int> *cur = q.front().first;
        int x= q.front().second;
        q.pop();
        if(mp.find(x)==mp.end()){
            mp[x]=cur->val;
        }
        if(cur->left){
            q.push({cur->left,x-1});
        }
         if(cur->right){
            q.push({cur->right,x+1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}
