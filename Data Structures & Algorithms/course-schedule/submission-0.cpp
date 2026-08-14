class Solution {
public:
    bool dfs(int v,vector<int> &visited,vector<int> &path,vector<vector<int>> &adj){
      visited[v]=1;
      path[v]=1;
      for(auto it: adj[v]){
        if(!visited[it]){
            if(dfs(it,visited,path,adj))return true;
        }
        if(path[it])return true;
      }
      path[v]=0;
      return false;  
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses);
        vector<int>path(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
            if(dfs(i,visited,path,adj))return false;
        }
    return true;}
};
