class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int find(int n){
        if(parent[n]==n)return n;
        return parent[n]=find(parent[n]);
    }
    bool merge_size(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return false;
        if(size[pu]>size[pv]){
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
        DSU dsu(edges.size()+1);
        for(auto it:edges){
            if(!dsu.merge_size(it[0],it[1]))
            return it;
        }
        return {};
    }
};
