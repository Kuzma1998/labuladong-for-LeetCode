/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-13 21:52:07
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-25 19:46:13
 */
// 在一排树中，第 i 棵树产生 tree[i] 型的水果。
// 你可以从你选择的任何树开始，然后重复执行以下步骤：
// 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
// 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
// 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
// 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
// 用这个程序你能收集的水果树的最大总量是多少？

// 三指针法
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,temp=0,right =0;
        int n = fruits.size();
        int size =-1;
        while(right<n){
            while(temp<n&&fruits[left]==fruits[temp]) // 固定left移动temp，直到不相同
                ++temp;
            right =temp;// temp，left固定，移动right，直到与left，temp不同
            while(right<n&&(fruits[left]==fruits[right]||fruits[temp]==fruits[right]))
                ++right;
            size = max(size,right-left);// 更新size
            left =temp;
        }
        return size;
    }
};