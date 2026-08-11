class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    map<int,int,greater<int>> mp;
    for(int i=0;i<position.size();i++){
        mp[position[i]]=speed[i];
    }
    stack<double> stk;
    for(auto x:mp){
        if(stk.empty())stk.push((double)(target-x.first)/x.second);
        else if((double)(target-x.first)/x.second>stk.top()){
            stk.push((double)(target-x.first)/x.second);
            
        }
        
    }
    int i=0;
    while(!stk.empty())
    {i++;
    stk.pop();}
    return i;   
    }
};
