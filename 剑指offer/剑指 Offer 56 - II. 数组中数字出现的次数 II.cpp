// 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
// 示例 1：
// 输入：nums = [3,4,3,3]
// 输出：4
// 示例 2：
// 输入：nums = [9,1,7,9,7,9,7]
// 输出：1

// 位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        // 遍历数组 把每个数表示位32位二进制数，求每一位为1的个数
        for(auto num:nums){
            for(int j=0;j<32;++j){
                bits[j] += num&1; // 求第i位是不是位0
                num = num>>1;
            }
        }
        int res = 0;
        // 每一位对3取余数
        for(int i=0;i<32;++i){// 求二进制数
            res += (1<<i)*(bits[i]%3);
        }
        return res;
    }
};