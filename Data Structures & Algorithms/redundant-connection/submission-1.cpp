class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> indegree(edges.size()+1);
        vector<vector<int>> adj(edges.size()+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<edges.size()+1;i++){
            if(indegree[i]==1)q.push(i);
        }
        vector<int> order(edges.size()+1);
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            order.push_back(ele);
            for(int it:adj[ele]){
                indegree[it]--;
                if(indegree[it]==1)q.push(it);
            }
        }
        for(int i=edges.size()-1;i>=0;i--){
            if(indegree[edges[i][0]]==2 && indegree[edges[i][1]]==2)
            return edges[i];
        }
        return {};
    }
};
