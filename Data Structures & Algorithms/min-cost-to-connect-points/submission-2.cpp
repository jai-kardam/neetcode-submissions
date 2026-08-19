class DSU{
    vector<int> size,parent;
    public:
    DSU(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent.push_back(i);
    }
    }
    int find(int v){
        if(parent[v]==v)return v;
        return parent[v]=find(parent[v]);
    }
    bool merge(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return false;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      vector<pair<int,pair<int,int>>> edges;
      for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            if(i==j)continue;
            int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            edges.push_back({distance,{i,j}});
        }
      }
      sort(edges.begin(),edges.end());  
      DSU dsu(points.size());
      int res=0;
      for(auto &edge:edges){
        if(dsu.merge(edge.second.first,edge.second.second))res+=edge.first;
      }
      return res;
    }
};
