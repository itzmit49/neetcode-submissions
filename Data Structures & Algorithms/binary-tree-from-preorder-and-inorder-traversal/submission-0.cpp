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
unordered_map<int,int>mp;
int idx=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int st,int ed){
        if(st>ed)return NULL;
        int val=preorder[idx++];
        TreeNode* root=new TreeNode(val);
        int pos=mp[val];
        root->left=build(preorder,inorder,st,pos-1);
        root->right=build(preorder,inorder,pos+1,ed);

        return root;



    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)mp[inorder[i]]=i;

        return build(preorder,inorder,0,n-1);

        
    }
};
