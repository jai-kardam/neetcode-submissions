class Solution {
public:
    void dfs(unordered_map<string,vector<string>> &adj,string curr,vector<string> &path){
        while(!adj[curr].empty()){
            string dst=adj[curr].back();
            adj[curr].pop_back();
            dfs(adj,dst,path);
        }
        path.push_back(curr);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto edge :tickets){
            adj[edge[0]].push_back(edge[1]);
        }
        for(auto &ele:adj){
            sort(ele.second.rbegin(),ele.second.rend());
        }
        vector<string>path;
        dfs(adj,"JFK",path);
        reverse(path.begin(),path.end());
        return path;
       


        
    }
};
