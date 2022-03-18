/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-18 11:29:52
 */
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
// 说明：你不能倾斜容器。
// 双指针

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int ans = 0;
        while(right>left){
            if(height[left]>height[right]){   //左边界大 右移
                ans = max(ans,(right-left)*height[right]);
                right--;
            }else{     // 右边大  左移
                ans = max(ans,(right-left)*height[left]);
                ++left;
            }
        }
        return ans;
    }
};