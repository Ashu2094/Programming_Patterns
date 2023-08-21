class Solution {
public:
int n;
    vector<vector<int>>dp;
    int getNextJobBs(int currJobEndingTime,int l,vector<vector<int>>&vec){

        int r=n-1;
        int result = n+1;

        while(l<=r){
            int mid = (l+(r-l)/2);
            if(vec[mid][0]>currJobEndingTime)
            {
                result = mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
        
    }
    int solve(int ind,int k,vector<vector<int>>&vec){
        if (ind >= n or k == 0) {
            return 0;
        }
        if(dp[ind][k]!=-1)
        return dp[ind][k];


        int notTake = solve(ind + 1, k, vec);

        int nextJobStartIndex = getNextJobBs(vec[ind][1], ind + 1, vec);
        int take = vec[ind][2] + solve(nextJobStartIndex, k - 1, vec);

        return dp[ind][k] = max(take, notTake);
    }


    int maxValue(vector<vector<int>>& vec, int k) {
        n= vec.size();
        
       
        auto comp = [&](auto & vec1,auto & vec2){
            return vec1[0]<vec2[0];
        };
        sort(vec.begin(), vec.end(),comp);
        // memset(dp,-1,sizeof(dp));
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(0,k,vec);
    }
};
