class Solution {
public:
    void dfs(int v,vector<int> &visited,vector<vector<int>> &adj){
        visited[v]=1;
        for(auto it: adj[v]){
            if(!visited[it])
            dfs(it,visited,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int> visited(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
            dfs(i,visited,adj);}
            
        }
        return count;
    }
};
