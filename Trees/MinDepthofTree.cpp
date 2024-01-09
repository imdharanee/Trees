int mindepth(TreeNode* root,int dist)
{
    if(!root) return INT_MAX;
        if(!root->left and !root->right)
           return dist;
        return min(mindepth(root->left,dist+1),mindepth(root->right,dist+1));
}