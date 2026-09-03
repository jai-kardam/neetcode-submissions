class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> adj;
        unordered_map<char,int> indegree;
        for(auto s:words){
            for(char c:s){
                indegree[c]=0;
            }
        }
        int n=words.size() ;
        for(int i=1;i<n;i++){
            string word=words[i];
            string prev=words[i-1];
            int j=0;
            while(j<word.size() && j<prev.size() && word[j]==prev[j] )j++;
            if(j>=word.size() && j<prev.size())return "";
            if(j==word.size() || j==prev.size())continue;
            adj[prev[j]].push_back(word[j]);
            indegree[word[j]]++;


        }  
        queue<char>q;
        string ans="";
        for(auto &[c,v] :indegree){
            if(v==0){
                q.push(c);
            }
        }
        while(!q.empty()){
            auto c=q.front();
            ans+=c;
            q.pop();
            for(auto neigh:adj[c]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }

        }
        if(ans.size()!=indegree.size())return "";
        return ans;
        }
};
