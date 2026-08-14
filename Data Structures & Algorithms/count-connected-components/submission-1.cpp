class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int n){
        if(parent[n]==n)return n;
        return parent[n]=findparent(parent[n]);
    }
    bool unionset(int n,int m){
        if(findparent(n)==findparent(m))return true;
        return false;
    }
    void merge_size(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(unionset(pu,pv))return;
        if(size[pu]>size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
};
class Solution {
public:
    
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto it:edges){
            if(!dsu.unionset(it[0],it[1]))n--;
            dsu.merge_size(it[0],it[1]);
        }
        return n;
    }
};
