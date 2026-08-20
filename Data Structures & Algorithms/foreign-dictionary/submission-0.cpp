class Solution {
public:
    string foreignDictionary(vector<string>& words) {
       unordered_map<char,vector<char>>adj;
       unordered_map<char,int> indegree;
       for (auto &w : words) {
            for (char c : w) {
                indegree[c] = indegree.count(c) ? indegree[c] : 0;
            }
        }
       for(int i=0;i<words.size()-1;i++){
        string curr=words[i];
        string next=words[i+1];
        int n=curr.size();
        int m=next.size();
        int j=0;
       while (j < n && j < m && curr[j] == next[j]) j++;
            if (j == m && n > m) return "";
            if (j < n && j < m) {
                adj[curr[j]].push_back(next[j]);
                indegree[next[j]]++;
            }
        }
       string res="";
       queue<char> q;
       for(auto & [c,v]:indegree){

        if(v==0){
            q.push(c);
        }
       }
       while(!q.empty()){
        char ele=q.front();
        res+=ele;
        q.pop();
        for(auto ele:adj[ele]){
            indegree[ele]--;
            if(indegree[ele]==0)
            q.push(ele);
        }
       }
       if(res.size()<indegree.size())return "";
       return res;
       
    }
};
