class Solution {
public:
    vector<int> printNumbers(int n) {
      
        int sz = pow(10,n)-1;
        vector<int> ans(sz,0);
        for(int i=0;i<sz;++i){
            ans[i] = i+1;
        }
        return ans;
    }
};