class Solution {
public:
    bool dfs(int v,int parent,vector<int> &visited,vector<vector<int>> &adj){
        if(visited[v])return true;
        visited[v]=1;
        for(auto it:adj[v]){
            if(it==parent)continue;
             if (visited[it]) return true;
            if(dfs(it,v,visited,adj))return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>adj(edges.size()+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            vector<int> visited(edges.size()+1,0);
                if(dfs(it[0],-1,visited,adj)){
                    return {it[0],it[1]};}
            }
            return {};
        }
        


};
