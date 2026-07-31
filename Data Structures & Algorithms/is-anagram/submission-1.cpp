class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length()!=t.length())return false;
      unordered_map<char,int> m1;
      unordered_map<char,int>m2;
      for( char c:s){
        m1[c]+=1;
      }
      for(char c:t){
        m2[c]+=1;
      } 
      return m1==m2;
    }
};
