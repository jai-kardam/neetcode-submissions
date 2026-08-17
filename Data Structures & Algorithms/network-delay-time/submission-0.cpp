class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<vector<pair<int,int>>>adj(n+1);
     vector<int>distance(n+1,INT_MAX);
     for(auto edge:times){
        adj[edge[0]].push_back({edge[1],edge[2]});
     }
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
     q.push({0,k});
     distance[k]=0;
     while(!q.empty()){
        auto curr=q.top();
        q.pop();
        int node=curr.second;
        int dis=curr.first;
        for(auto neigh:adj[node]){
            if(distance[neigh.first]>dis+neigh.second){
                q.push({dis+neigh.second,neigh.first});
                distance[neigh.first]=dis+neigh.second;
            }
        }
     }
     int val=INT_MIN;
     for(int i=1;i<=n;i++){
        if(distance[i]==INT_MAX)return -1;
        val=max(val,distance[i]);
     }
     return val;
     

    }
};
