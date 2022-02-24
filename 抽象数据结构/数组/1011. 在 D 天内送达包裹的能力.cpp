/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-11 08:50:08
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-11 21:20:44
 */

// 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
// 传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
// 返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

// 输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
// 输出：15
// 解释：
// 船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
// 第 1 天：1, 2, 3, 4, 5
// 第 2 天：6, 7
// 第 3 天：8
// 第 4 天：9
// 第 5 天：10

// 思路：二分查找，对于每个容量，求出运送所需的天数，二分查找的范围根据题目意思确定，用左边界还是右边界意思根据题目意思确定。

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 求出二分查找范围
        int left=0,right=0;
        for(auto weight:weights){
            left = max(left,weight);
            right += weight;
        }
        // 二分查找
        while(left<=right){
            int mid = left+(right-left)/2;
            if(f(weights,mid)<=days)
                right =mid-1;
            else
                left = mid+1;
        }
        return left;
    }

    // 给定运载量求所需天数
    int f(vector<int>& weights,int x){
        int days=0;
        for(int i=0;i<weights.size();){
            int cap=x;
            while(i<weights.size()){
                if(cap<weights[i])
                    break;
                else{
                    cap -= weights[i];
                    ++i;
                }   
            }
        ++days;
        }
        return days;
    }
};