int height(Node* root)
{
    if(!root)
      return 0;   
    int l=height(root->left);int r=height(root->right);
    return std::max(l,r)+1;
}
void solve(Node* root,int level,int mainlevel,map<int,int>& map)
{
    if(!root)
      return;
    if(level==1)
    {
        if(map.find(mainlevel)==map.end())
          map[mainlevel]=root->data;
    }
    solve(root->left,level-1,mainlevel,map);
    solve(root->right,level-1,mainlevel,map);
}
vector<int> leftView(Node *root)
{
   int h=height(root);map<int,int>map;vector<int>ans;
   
   for(int i=1;i<=h;i++)
   {
      
      solve(root,i,i,map);
   }
   for(auto &it:map)
   {
       ans.push_back(it.second);
   }
   return ans;
}