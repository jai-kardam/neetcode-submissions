class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<vector<int>,vector<string>> mp;
     for( auto s:strs){
      vector<int> key(26,0);
      for(char a:s){
        key[a-'a']+=1;
      }
      mp[key].push_back(s);
     } 
     vector<vector<string>> res;
     for(auto ele:mp){
      res.push_back(ele.second);
     }
     return res;  
    }
};
