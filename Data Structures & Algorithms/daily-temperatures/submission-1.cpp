class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> stk;
        for(int i=0;i<n;i++){
            
            while(!stk.empty() && stk.top().second<temperatures[i]){
                auto ele=stk.top();
                stk.pop();
                result[ele.first]=i-ele.first;
                
            }
            stk.push({i,temperatures[i]});
        }
        return result;
    }
};
