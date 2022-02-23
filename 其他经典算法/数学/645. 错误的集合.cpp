// 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，
// 致集合丢失了一个数字 并且 有一个数字重复 。
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。
// 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

// 思路：哈希即可，遍历一次，若某个数字的哈希值等于2 则是重复，若某个数字的哈希值为0，则为缺少

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n,0);
        for(int i=0;i<nums.size();++i){
            hash[nums[i]-1]++;
        }
        int err,rep;
        for(int i=0;i<n;++i){
            if(hash[i]==0)
                err = i;
            if(hash[i]==2)
                rep =i;
        }
        return {rep+1,err+1};
    }
};