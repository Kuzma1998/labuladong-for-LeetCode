
// 位运算
class Solution {
public:
    int hammingDistance(int x, int y) {
        int max_num = max(x,y);
        int min_num = min(x,y);
        int ans = 0;
        while(max_num){
            if((max_num&1)!=(min_num&1)){
                ++ans;
            }
            max_num = max_num>>1;
            min_num = min_num>>1;
        }
        return ans;
    }
};