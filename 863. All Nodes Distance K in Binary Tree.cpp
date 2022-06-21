/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        unordered_map<TreeNode*, TreeNode*> mp;
        findparent(root, mp );
        vector<int>ans;
        bfs(target, k, mp, ans);
        return ans;
        
    }
    void findparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> & mp){
        if(!root)return ;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur= q.front();
            q.pop();
            if(cur->left){
                mp[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                mp[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    void bfs(TreeNode* tar, int k,unordered_map<TreeNode*, TreeNode*> mp, vector<int>&ans ){
        
        unordered_map<TreeNode*, bool>vis;
        
        queue<TreeNode* >q;
        int dist=0;
        q.push(tar);
        vis[tar]=1;
        while(!q.empty() || dist<k){
            int n= q.size();
            if(dist++==k)break;
            for(int i=0 ; i<n ; i++){
                TreeNode* cur= q.front();
                q.pop();
                
                if(cur->left && !vis[cur->left] ){
                    q.push(cur->left);
                    vis[cur->left]=true;}
                if(cur->right&&!vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=true;}
                if(mp[cur] && !vis[mp[cur]] ){
                    q.push(mp[cur]);
                    vis[mp[cur]]=true;
                }
                
            }
           
           
            }
        while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
            
        }
    
        
        
    
};
