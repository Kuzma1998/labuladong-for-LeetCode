/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-25 20:38:34
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-25 20:38:35
 */
// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
// 输入：n = 3
// 输出：[[1,2,3],[8,9,4],[7,6,5]]



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));

        int loop =n/2;// 循环圈数
        int start_x =0,start_y=0;
        int count=1;//计数器
        int offset =1; // 偏移量

        while(loop--){
            int i = start_x;
            int j = start_y;
            for(;j<start_y+n-offset;++j)
                ans[i][j]=count++;
            for(;i<start_x+n-offset;++i)
                ans[i][j] = count++;
            for(;j>start_y;--j)
                ans[i][j] = count++;
            for(;i>start_x;--i)
                ans[i][j] =count++;  

            offset +=2;// 做完一次loop，偏移量+2，即内圈遍历的长度要减2
            start_x++;
            start_y++;
        }
        if(n%2){
            ans[n/2][n/2] = count;
        }
        return ans;
    }
};