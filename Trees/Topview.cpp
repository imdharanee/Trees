vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>>q;vector<int>ans;
        q.push({root,0});
        map<int,int>map;
        while(!q.empty())
        {
            auto it=q.front();int level=it.second;q.pop();
            if(map.find(level)==map.end())
              map[level]=it.first->data;
            if(it.first->left)
              q.push({it.first->left,level-1});
            if(it.first->right)
              q.push({it.first->right,level+1});
              
        }
        for(auto it:map)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }