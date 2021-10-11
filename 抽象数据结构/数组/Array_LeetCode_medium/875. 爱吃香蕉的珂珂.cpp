/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-11 08:51:15
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-11 21:31:53
 */

// 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
// 珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。
// 每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
// 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
// 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

// 输入: piles = [3,6,7,11], H = 8
// 输出: 4
思路： 二分搜索，对于给定的吃香蕉速度范围，对于每个K，求出吃完香蕉所需的时间，利用二分搜索求出最小K

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 范围
        int left=1, right = 1000000000;
        // 二分搜索
        while(left<=right){
            int mid = left+(right-left)/2;
            if(f(piles,mid)==h)
                right=mid-1;
            else if(f(piles,mid)>h)
                left =mid+1;
            else if(f(piles,mid)<h)
                right=mid-1;
        }
        return left;
    }
    
    // 求以x速度吃香蕉所需时间
    int f(vector<int>& piles,int x){
        int hours=0;
        for(auto pile:piles){
            hours += pile/x;
            if(pile%x)
                ++hours;
        }
        return hours;
    }
};

