<!--
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 16:53:28
-->
<!--
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 15:57:06
-->

# DFS
其实**DFS**算法就是回溯算法。

## DFS解决岛屿问题
**岛屿系列题⽬的核⼼考点就是⽤ DFS/BFS 算法遍历⼆维数组**
- 本⽂主要来讲解如何⽤ DFS 算法来秒杀岛屿系列题⽬，不过⽤ BFS 算法的核⼼思路是完全⼀样的，⽆⾮就是把 DFS 改写成 BFS ⽽已。
- 那么如何在⼆维矩阵中使⽤ DFS 搜索呢？如果你把⼆维矩阵中的每⼀个位置看做⼀个节点，这个节点的上下左右四个位置就是相邻节点，那么整个矩阵就可以抽象成⼀幅⽹状的「图」结构。

```java
void traverse(TreeNode root) {
 traverse(root.left);
 traverse(root.right);
}

void dfs(int[][] grid, int i, int j, boolean[] visited) {
    int m = grid.length, n = grid[0].length;
    if (i < 0 || j < 0 || i >= m || j >= n) {
// 超出索引边界
    return;
    }
    if (visited[i][j]) {
 // 已遍历过 (i, j)
    return;
    }
 // 进⼊节点 (i, j)
    visited[i][j] = true;
    dfs(grid, i - 1, j); // 上
    dfs(grid, i + 1, j); // 下
    dfs(grid, i, j - 1); // 左
    dfs(grid, i, j + 1); // 右
}
```