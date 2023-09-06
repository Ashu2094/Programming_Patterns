class Solution {
public:
    string rec(int a,int b){
        if(a==0)
        return string (b,'b');
        if(b==0)
        return string(a,'a');
        if(a==b)
        return "ab"+rec(a-1,b-1);
        else if(a>b) return "aab" + rec(a-2,b-1);
        return "bba" + rec(a-1,b-2);
    }
    string strWithout3a3b(int a, int b) {
        // string ans="";
        // while(a and b){
        //     if(a>b){
        //         ans+="aab";
        //         a-=2;
        //         b--;
        //     }else if(b>a){
        //         ans+="bba";
        //         a--;
        //         b-=2;
        //     }else{
        //         ans+="ab";
        //         a--,b--;
        //     }
        // }

        // while(a) ans+='a',a--;
        // while(b) ans+='b',b--;
        // return ans;
        return rec(a,b);
    }
};
    
