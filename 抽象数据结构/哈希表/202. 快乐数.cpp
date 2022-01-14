// 编写一个算法来判断一个数 n 是不是快乐数。
// 「快乐数」定义为：
// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果 可以变为  1，那么这个数就是快乐数。
// 如果 n 是快乐数就返回 true ；不是，则返回 false 。
// 输入：n = 19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

//  思路：集合，若到0之前出现重复元素，就必然不可能到0
class Solution {
public:
    bool isHappy(int n) {
        set<int> m;
        while(n!=1){
            string str = to_string(n);
            int sum =0;
            for(auto i:str){
                sum += (i-'0')*(i-'0');
            }
            if(!m.count(sum)){
                m.insert(sum);
                n =sum;
            }else
                return false;
        }
        return true;
    }
};