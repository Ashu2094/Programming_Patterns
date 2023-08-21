class Solution {
public:
    int n;
    int dp[50001];
    int getNextJobBs(int currJobEndingTime,int l,vector<vector<int>>&vec){

        int r=n-1;
        int result = n+1;

        while(l<=r){
            int mid = (l+(r-l)/2);
            if(vec[mid][0]>=currJobEndingTime)
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
    int solve(int ind,vector<vector<int>>&vec){
        if(ind>=n)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];

        int nextJobStartIndex = getNextJobBs(vec[ind][1],ind+1,vec);
        int take = vec[ind][2] + solve(nextJobStartIndex,vec);
        int notTake = solve(ind+1,vec);

        return dp[ind] = max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n= profit.size();
        vector<vector<int>>vec(n,(vector<int>(3,0)));
        
        for(int i=0;i<n;i++)
        {
            vec[i][0]=startTime[i];
            vec[i][1]=endTime[i];
            vec[i][2]=profit[i];
        }

        auto comp = [&](auto & vect1,auto & vect2){
            return vect1[0]<=vect2[0];
        };//lambda
        sort(vec.begin(),vec.end(),comp);
        memset(dp,-1,sizeof(dp));
        return solve(0,vec);
    }
};
