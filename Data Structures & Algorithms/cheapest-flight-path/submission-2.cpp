class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for( auto & edge: flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<pair<int,pair<int ,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<int> distance(n,INT_MAX);
        distance[src]=0;
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int stops=ele.first;
            int node=ele.second.first;
            int dis=ele.second.second;
            if(stops>k)continue;
            for(auto &[n,w]:adj[node]){
                if(dis+w<distance[n]){
                    distance[n]=dis+w;
                pq.push({stops+1,{n,dis+w}});}
            }
            
        }
        return distance[dst]==INT_MAX? -1:distance[dst];
    }
};
