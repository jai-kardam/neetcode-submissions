class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;

        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(!indegree[i])q.push(i);
        }
        int count =0;
        vector<int> visited(numCourses,0);
        while(!q.empty()){
            int n=q.front();
            count++;
            q.pop();
            for(auto ele:adj[n]){
                indegree[ele]--;
                if(indegree[ele]==0)q.push(ele);
            }
        }
        return count==numCourses;
    }
};
