class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(u==parent[u])
        return u;
        return parent[u]=find(parent[u]);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
       DSU dsu(n);
       for(auto ele:edges){
        if(!dsu.merge(ele[0],ele[1])){
            return ele;
        }
       } 
    return edges[0];}
};
