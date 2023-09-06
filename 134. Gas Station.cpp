class Solution {
public:
    // int bruteForce(vector<int>& gas, vector<int>& cost){
    //     int mod = gas.size();
    //     for(int i=0;i<mod;i++){
    //         // int fuel = gas[i];
    //         int fuel=0,cost_= 0;
    //         // int i_= i; //3
    //         int j=0;
    //         for(;j<mod;j++){
    //             fuel += gas[(i+j) % mod];  
    //             cost_ = cost[(i+j) % mod]; 
    //             // cout<<fuel<<" "<<cost_<<endl;
    //             if(fuel-cost_<0)
    //             break;
    //             fuel-=cost_;
    //             // i++;
    //         }
    //         // cout<<j<<" ";
    //         if(j==mod)
    //         return i;
    //     }
    //     return -1;
    // }

    // bool static comp(const pair<int,int>&a,const pair<int,int>&b){
    //     return a.first>b.first;
    // }
    int bruteForceOptimized(vector<int>& gas, vector<int>& cost){
        vector<pair<int,int>>vect;
        int gsum=0,csum=0;
        for(int i=0;i<gas.size();i++){
            vect.push_back({gas[i],i});
            gsum+=gas[i];
            csum+=cost[i];
        }
        
        if(csum>gsum)
        return -1;
        sort(vect.rbegin(), vect.rend());
        // for(auto x:vect)
        // cout<<x.first<<" ";
        
        
       
        
        int mod = gas.size();
        for(int i=0;i<mod;i++){
            // int fuel = gas[i];
            int fuel=0,cost_= 0;
            int i_= vect[i].second; //3
            int j=0;
            for(;j<mod;j++){
                fuel += gas[(i_+j) % mod];  
                cost_ = cost[(i_+j) % mod]; 
                // cout<<fuel<<" "<<cost_<<endl;
                if(fuel-cost_<0)
                break;
                fuel-=cost_;
                // i++;
            }
            // cout<<j<<" ";
            if(j==mod)
            return i_;
            // return -1;
        }
        return -1;
    }


    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // return bruteForceOptimized(gas,cost);


        //efficient
        int n = cost.size();
        int fuel_cost=0;
        int excessFuel=0;
        int start=0;
        for(int i=0;i<n;i++){
            fuel_cost+=gas[i]-cost[i];
            excessFuel+=gas[i]-cost[i];
            if(excessFuel<0){
                excessFuel=0;
                start=i+1;
            }
        }
        return  fuel_cost>=0 ? start : -1;
    }
};
