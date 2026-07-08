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
    void solve(TreeNode* root,TreeNode* tar,vector<int>&v){
        if(root==NULL)return;
       
        v.push_back(root->val);
         if(root==tar){
            
            return;
        }
        if(root->val>tar->val)solve(root->left,tar,v);
        else solve(root->right,tar,v);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<int>a1,a2;
        solve(root,p,a1);
        solve(root,q,a2);
        //5 3 
        // 5 3 4
      int i=0;
      while(i<a1.size()&&i<a2.size()&&a1[i]==a2[i]){
        i++;
      }
      int ans=a1[i-1];
      while(root->val!=ans){
        if (ans < root->val)
            root = root->left;
        else
            root = root->right;
      }
      return root;
       
        

        
      
        
    }
};
