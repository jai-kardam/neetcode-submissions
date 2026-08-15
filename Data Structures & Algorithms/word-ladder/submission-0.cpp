class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
    while(!q.empty()){
        auto ele=q.front();
        q.pop();
        string word=ele.first;
        if(word==endWord)return ele.second;
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,ele.second+1});
                }
        
            }
            word[i]=original;
            }
        }
        return 0;
    }
};
