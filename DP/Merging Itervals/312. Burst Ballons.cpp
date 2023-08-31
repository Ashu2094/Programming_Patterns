class Solution {
public:
    // int dp[303][303];
    // int solve(int i,int j,vector<int>& nums)
    // {
    //     if(i>j)
    //     return 0;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int ans = INT_MIN;
    //     for(int k=i;k<=j;k++)
    //     {
    //        int  temp = nums[i-1] * nums[k] * nums[j+1] + solve(i,k-1,nums) + solve(k+1,j,nums);
    //         ans = max(ans,temp);
    //     }
    //     return dp[i][j] = ans;
    // }
    int maxCoins(vector<int>& nums) {
        // nums.push_back(1);
        // nums.insert(nums.begin(),1);
        // memset(dp,-1,sizeof(dp));
        // return solve(1,nums.size()-2,nums);
        //......................................
        // Tabulation
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=nums.size()-2;j++)
            {
                if(i>j)
                continue;
                int ans = INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int  temp = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans,temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
