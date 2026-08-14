class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> order;
    vector<vector<int>> adj(numCourses);
    vector<int>indegree(numCourses,0);
    for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }    
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int ele=q.front();
        order.push_back(ele);
        q.pop();
        for(auto it:adj[ele]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    return order.size()==numCourses;
    }
};
