class Solution {
public:
    int furthestBuilding(vector<int>& v, int bri, int lad) {
        priority_queue<int>bricksUsedEarlier;
        int i=0,jump;
        for(;i<v.size()-1;i++){
            jump = v[i+1] - v[i];
            if(jump<=0)
            continue;
            
            if(jump<=bri){
                bri-=jump;
                bricksUsedEarlier.push(jump);
            }
            else if(lad>0){
                if(bricksUsedEarlier.size() and bricksUsedEarlier.top()>jump){
                    bri+=bricksUsedEarlier.top();
                    bricksUsedEarlier.pop();
                    bri-=jump;
                    bricksUsedEarlier.push(jump);
                }
                lad--;
            }
            else break;
        }
        return i;
    }
};
