class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,int n,int p){
        visited[n]=1;
        for(auto ele:adj[n]){
            if(visited[ele] && ele!=p)return false;
            else if(visited[ele])continue;
            dfs(adj,visited,ele,n);
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1))
                count++;
                else return false;
                
            }
        }
        return count==1;
    }
};
