class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>diff;
        long ans=0;
        for(auto x:costs){
            ans+=x[0];
            diff.push_back(x[1]-x[0]);
        }

        sort(diff.begin(),diff.end());

        for(int i=0;i<costs.size()/2;i++){
            ans+=diff[i];
        }
        return ans;
    }
};


//    a   b
// 0  10  20       10   10   20
// 1  30  200     170   30   20
// 2  400 50     -350   30   200
// 3  30  20      -10   400  50



    
 
// 4=[184,139]     45
// 6=[577,469]    108 
// 3=[926,667]    259
// 2=[448, 54]    394
// 1=[259,770]    511 
// 5=[840,118]    732    


// a =>184 259     577| 
// b =>54  118     667| 


