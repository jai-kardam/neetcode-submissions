class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<vector<int>,vector<string>> mp;
     vector<int> arr(26,0);
     for(string s:strs){
       fill(arr.begin(),arr.end(),0);
        for(char c:s){
            arr[c-'a']++;
        }
        mp[arr].push_back(s);
      }
     vector<vector<string>> res;
     for(auto it:mp){
        res.push_back(it.second);
     } 
     return res; 
    }
};
