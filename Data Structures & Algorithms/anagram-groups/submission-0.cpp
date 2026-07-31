class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string,vector<string>> mp;
      for(auto s:strs){
        string a=s;
        sort(a.begin(),a.end());
        mp[a].push_back(s);
      }
      vector<vector<string>> result;
      for(auto s:mp){
        result.push_back(s.second);
      }
      return result;
    }
};
