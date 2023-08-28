class Solution {
public:
    // vector<int> extraSpace(vector<int>& nums){
    //     vector<int>prefix(nums.size(),1);
    //     vector<int>suffix(nums.size(),1);
    //     int prod=1;
    //     for(int i=1;i<nums.size();i++){
    //         prod*=nums[i-1];
    //         prefix[i]=prod;
    //     }
    //     prod=1;
    //     for(int i=nums.size()-2;i>=0;i--){
    //         prod*=nums[i+1];
    //         suffix[i]=prod;
            
    //     }
    //     vector<int>ans;
    //     for(int i=0;i<nums.size();i++){
            
    //         ans.push_back(prefix[i]*suffix[i]);
    //     }
    //     return ans;
    // }
    vector<int> constantSpace(vector<int>& nums){
        
        vector<int>ans(nums.size(),1);
        int prefix=1;
        for(int i=1;i<nums.size();i++){
            prefix*=nums[i-1];
            ans[i]=prefix;
        }
        int suffix=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;    
        }
        return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return constantSpace(nums);
    }
};


// 1   2   3   4
// 1   1   2   6


// 24  12  4   1
// 24  12  8   6   
