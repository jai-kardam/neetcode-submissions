class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     if(h<piles.size())return -1;
    int maxspeed=*max_element(piles.begin(),piles.end());
    int l=1;
    int r=maxspeed;
    int minspeed=0;
    while(l<=r){
    long long hours=0;
    int i= l+(r-l)/2;
        for(int j=0;j<piles.size();j++){
            hours=hours+((long long)piles[j]+i-1)/i;
        }
        if(hours>h){
            l=i+1;
        }
        else if(hours<=h){
            minspeed=i;
            r=i-1;
        }
        
    } 
    return minspeed; 
    }
};
