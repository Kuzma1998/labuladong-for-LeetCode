



class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(x==1.00000)
            return x;
        long temp =n;
        if(temp<0){
            temp = -temp;
            x = 1/x;
        }
        double ans = 1;
        while(temp){
            if(temp&1){
                ans *= x;
            }
            x *= x;
            temp = temp>>1;
        }
        return ans;
    }
    
};