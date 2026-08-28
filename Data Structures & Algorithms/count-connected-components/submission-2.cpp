class Solution {
public:
    void dfs(vector<vector<int>> & adj,vector<int> &visited,int n){
        visited[n]=1;
        for(auto ele:adj[n]){
            if(visited[ele])continue;
            dfs(adj,visited,ele);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(auto  edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        return count;

    }
};
