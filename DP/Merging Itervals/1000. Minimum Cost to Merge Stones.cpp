class Solution {
public:
int dp[50][50][50];
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)!=0)
        return -1;

        vector<int>prefixSum(n,0);
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=stones[i];
            prefixSum[i]=sum;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,1,k,prefixSum);
    }
    int solve(int i,int j,int piles,int k,vector<int>&prefixSum){
        if(i==j and piles==1)
        return 0;

        if(i==j and piles!=1)
        return INT_MAX/4;

        if(dp[i][j][piles]!=-1)
            return dp[i][j][piles];

        if(piles==1){
            return dp[i][j][piles] = solve(i,j,k,k,prefixSum) + (i==0?prefixSum[j]:prefixSum[j]-prefixSum[i-1]);
        }else{
            int cost = INT_MAX/4;
            for(int partition=i;partition<j;partition++){
                cost = min(cost,solve(i,partition,1,k,prefixSum)+solve(partition+1,j,piles-1,k,prefixSum));
            }
            return dp[i][j][piles] = cost;
        }
        
    }
};

//notes to this question
 /* 
        Check whether we will be able to merge n piles into 1 pile . 
            
            In step-1 we merge k pile and then we are left with n-k+1 piles or n-(k-1);
            In Step-2 we again merge k pile and then we are left with ((n-k+1)-k)+1 or n-2*(k-1);
            In Step-3 we gain merge k pile and left with (((n-k+1)-k+1)-k)+1 or n-3*(k-1)
            .......
            .......
            .......
            After some m steps we should be left with 1 pile 
            Therefore , n-m*(k-1) == 1
                   (n-1)-m*(k-1)=0;
                   Since m needs to be an integer therefore , 
                   if (n-1)%(k-1) == 0 , 
                   then we can merge otherwise not possible.
        */



// 6,4,4,6
// 10,4,6  => 10
// 10,10   => 10
// 20      => 20
