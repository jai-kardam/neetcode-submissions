class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses,0);
    vector<int> ans;
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(!indegree[i])q.push(i);
    }
    while(!q.empty()){
        int ele=q.front();
        ans.push_back(ele);
        q.pop();
        for( auto it:adj[ele]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    if(ans.size()<numCourses)return {};
    return ans;

        
    }
};
