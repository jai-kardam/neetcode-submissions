class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<points.size();i++){
            mp[i]={points[i][0],points[i][1]};
        }
       vector<vector<pair<int,int>>> adj(points.size()); 
       for(int i=0;i<points.size();i++){
        int x1=mp[i].first;
        int y1=mp[i].second;
       for(int j=0;j<points.size();j++){
        if(i==j)continue;
        int distance=abs(x1-points[j][0]) + abs(y1-points[j][1]);
        adj[i].push_back({j,distance});
        
       }}
       priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       vector<int>visited(points.size(),0);
       pq.push({0,0});
       int min=0;
       while(!pq.empty()){
         auto ele=pq.top();
        pq.pop();
        if(visited[ele.second])continue;
        visited[ele.second]=1;
        min+=ele.first;
        for(const auto &neigh:adj[ele.second]){
            if(!visited[neigh.first]){
                pq.push({neigh.second,neigh.first});
            }
        }
       }

     return min;  
    }
};
