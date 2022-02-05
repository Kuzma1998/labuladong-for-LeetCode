# 动态规划
首先，动态规划问题的一般形式就是求最值，求解动态规划的核心问题是穷举。其穷举很有特点，一定会存在**重叠子问题**。其次，会具备**最优子结构**。最重要的是写出**状态转移方程**。

## 状态转移方程
1. 这个问题的**base**是啥？
2. 这个问题有啥**状态**。
3. 对于每个状态，有啥选择使得**状态**发生改变？
4. 如何定义dp数组或者函数来表现**状态和选择**。


## 代码模板
```C++
dp[0][0]...[] = base case;
#进行状态转移
for 状态1 in 状态1所有取值:
    for 状态2 in 状态2所有取值:
        for...
            for 状态n in 状态n所有取值:
                dp[状态1][状态2]...[] = 求最值(选择1，选择2...);
```


## 递归Debug技巧
```Java
// 递归三要素：递归函数功能，递归终止条件，如何递归？递归是一个自顶向下的过程，与DP相反
// 在递归函数的开头，调⽤ printIndent(count++) 并打印关键变量；然后在所有 return 语句之前调⽤
// printIndent(--count) 并打印返回值。
int count = 0;
void printIndent(int n) {
 for (int i = 0; i < n; i++) {
 printf(" ");
 }
}
int dp(string& ring, int i, string& key, int j) {
 // printIndent(count++);
 // printf("i = %d, j = %d\n", i, j);
 
 if (j == key.size()) {
 // printIndent(--count);
 // printf("return 0\n");
 return 0;
 }
 
 int res = INT_MAX;
 for (int k : charToIndex[key[j]]) {
 res = min(res, dp(ring, j, key, i + 1));
 }
 
 // printIndent(--count);
 // printf("return %d\n", res);
 return res;
}
// 就是在函数开头和所有 return 语句对应的地⽅加上⼀些打印代码。
// 仅仅给定数组字符串的递归是从0开始
// 而给定某个条件如开始递归则递归开始是从条件开始
```
