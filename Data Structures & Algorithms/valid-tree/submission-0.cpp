class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<vector<int>> adj(n);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        vector<int> visited(n,0);
        q.push({0,-1});
        visited[0]=1;
        int counter=1;
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            for(auto it:adj[ele.first]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push({it,ele.first});
                    counter++;
                }
                else{
                    if(it!=ele.second)
                    return false;
                }
            }
        }
        if(counter!=n)return false;
        return true;
    }
};
