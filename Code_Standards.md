<!--
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-07-28 19:02:19
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-07-28 20:43:32
-->
# 代码的默认规则
## Tree
TreeNode是二叉树结点类型，其结构如下：

```C++
public class TreeNode{
    int val;//结点存储的值
    TreeNode left;
    TreeNode Right;

//构造函数：类名(){code}
TreeNode(int val){
    this.val = val;
    this.left = NULL;
    this.right = NULL;
    }
}
```

一般的使用方法是:
```C++
TreeNode node1 = new TreeNode(2);
TreeNode node2 = new TreeNode(4);
TreeNode node3 = new TreeNode(6);

//修改结点的值
node1.val =10;
node1.left = node2
node1.right = node3
```
## List
ListNode是单链表结点类型，其结构如下
```C++
class ListNode{
    int val;//结点存的值
    ListNode Next;//指向下一个结点的指针

    ListNode(int val){
        //构造函数
        this.val = val;
        this.next = NULL;
    }
}
```

一般的使用方法

```C++
ListNode node1 = new ListNode(1);
ListNode node2 = new ListNode(2);
ListNode node3 = new ListNode(3);

node1.val = 9;
node2.next = node3;
node1.next = node2;
```
