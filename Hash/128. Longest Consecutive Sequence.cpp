
class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        unordered_map<int,bool>start;
        for(auto x:nums){
            start[x]=true;
        }
        for(auto x:nums){
            if(start.find(x-1)!=start.end()){
                start[x]=false;
            }
        }
        int maxi=1;
        for(auto val:nums){
            int cnt=1;
            if(start[val]==true){
                
                int num=val+1;
                while(start.find(num)!=start.end()){
                 cnt++;
                 maxi=max(maxi,cnt);
                 num=num+1;
                }
            }
        }
        return maxi;
        
    }
};
