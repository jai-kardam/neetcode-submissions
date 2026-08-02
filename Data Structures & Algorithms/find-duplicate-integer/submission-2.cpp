class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res=0;
       for(int b=0;b<32;b++){
        int x=0 ;int y=0;
        int mask=1<<b;
        for(int n:nums){
            if(mask & n){
                x++;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(mask & i){
                y++;
            }
        }
         if(x>y) res|=mask;}
        return res;    
    }
};
