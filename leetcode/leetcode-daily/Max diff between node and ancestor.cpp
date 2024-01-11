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

    int findmaxdiff(TreeNode*root,int minval,int maxval)
    {
        if(root==NULL)return abs(maxval-minval);//that means we have traveesed one complete path


         minval=min(minval,root->val);
         maxval=max(maxval,root->val);

        int l=findmaxdiff(root->left,minval,maxval);
        int r=findmaxdiff(root->right,minval,maxval);

        return max(l,r);

        
    }
    int maxAncestorDiff(TreeNode* root) {
        int minval=INT_MAX;
        int maxval=INT_MIN;
        return findmaxdiff(root,minval,maxval);
        
    }
};
