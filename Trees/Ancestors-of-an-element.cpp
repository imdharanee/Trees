void dfs(Node* root,unordered_map<int,Node*>& parent,Node* prev)
    {
        if(!root) return;
        parent[root->data]=prev;
        dfs(root->left,parent,root);
        dfs(root->right,parent,root);
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
         unordered_map<int,Node*>parent;vector<int> ans;
         parent[root->data]=nullptr;
         dfs(root,parent,nullptr);
         while(parent[target])
         {
             ans.push_back(parent[target]->data);
             target=parent[target]->data;
             
         }
         return ans;
         
    }