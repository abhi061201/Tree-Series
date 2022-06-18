/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*, pair<int,int>>>q;        // node-> verticle->level
        map<int , map<int,multiset<int>>> nodes;   // verticle->level-> all nodes
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* cur= p.first;
            int x= p.second.first;   // verticle
            int y= p.second.second;     // level
            nodes[x][y].insert(cur->val);
            
            if(cur->left)q.push({cur->left,{x-1,y+1}});
            if(cur->right)q.push({cur->right,{x+1,y+1}});
            
            
        }
        for(auto it : nodes){
            vector<int>temp;
            for(auto p : it.second){
                // insert into vector from any set or any map between a range
                // v.insert(position,begining iterator, ending iterator);
                
                temp.insert(temp.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
