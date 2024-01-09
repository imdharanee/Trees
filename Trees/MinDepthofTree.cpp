int solve(TreeNode* root,int dist)
{
    if(!root) return INT_MAX;
        if(!root->left and !root->right)
           return dist;
        return min(height(root->left,dist+1),height(root->right,dist+1));
}