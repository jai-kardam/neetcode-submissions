class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>adj;
        wordList.push_back(beginWord);
        
        for(int i=0;i<wordList.size();i++){
            string word1=wordList[i];
            for(int j=0;j<wordList.size();j++){
                string word2=wordList[j];
                int count=0;
                for(int k=0;k<word2.size();k++){
                    if(word2[k]!=word1[k]){
                    count++;
                    }
                
                }
                if(count==1){
                    adj[word1].push_back(word2);
                }
                
            }

        }
        unordered_map<string,int> visited;
        for(auto ele:wordList){
            visited[ele]=0;
        }
        queue<pair<string,int>> q;
        visited[beginWord]=1;
        q.push({beginWord,0});
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            if(ele.first==endWord)return ele.second+1;
            for(auto neigh:adj[ele.first]){
                if(visited[neigh])continue;
                visited[neigh]=1;
                q.push({neigh,ele.second+1});
            }
        }
        return 0;
        

        
    }
};
