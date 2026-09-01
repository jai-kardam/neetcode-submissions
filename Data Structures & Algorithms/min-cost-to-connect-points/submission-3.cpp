class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,pair<int,int>> point;
        int n=points.size();
        for(int i=0;i<n;i++){
            point[i]={points[i][0],points[i][1]};
        }
        vector<vector<pair<int,int>>> adj(points.size());
        for(int i=0;i<n;i++){
            int x1=point[i].first;
            int y1=point[i].second;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                int x2=point[j].first;
                int y2=point[j].second;
                int dis=abs(x1-x2)+ abs(y1-y2);
                adj[i].push_back({j,dis});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int cost=0;
        vector<int>visited(n,0);
        
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int w=ele.first;
            int node=ele.second;
            if(visited[node])continue;
            visited[node]=1;
            cost+=w;
            for(auto neigh:adj[node]){
               if(visited[neigh.first])continue;
               pq.push({neigh.second,neigh.first});
            }
        }

       
        return cost;
    }
};
