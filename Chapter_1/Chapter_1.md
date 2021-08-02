<!--
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-07-29 09:23:36
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-08-02 10:09:07
-->

## 1.1 思维框架
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;底层存储方式无非是链表或者数组。
&nbsp;&nbsp;&nbsp;&nbsp;数组由于是紧凑连续存储,可以随机访问，通过索引快速找到对应元素，而且相对节约存储空间。但正因为连续存储，内存空间必须一次性分配够，所以说数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去，时间复杂度 O(N)；而且你如果想在数组中间进行插入和删除，每次必须搬移后面的所有数据以保持连续，时间复杂度 O(N)。
&nbsp;&nbsp;&nbsp;&nbsp;链表因为元素不连续，而是靠指针指向下一个元素的位置，所以不存在数组的扩容问题；如果知道某一元素的前驱和后驱，操作指针即可删除该元素或者插入新元素，时间复杂度 O(1)。但是正因为存储空间不连续，你无法根据一个索引算出对应元素的地址，所以不能随机访问；而且由于每个元素必须存储指向前后元素位置的指针，会消耗相对更多的储存空间。


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;基本操作无非就是**增删查改**。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;数组遍历框架如下:
```C++
void traverse(int arr[]){
    for(int i=0;i<arr.length;i++){
        cout<<arr[i];
    }
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;链表遍历框架如下:
```C++
class ListNode{
    int val;
    ListNode Next;
}

void traverse(ListNode head){
    for(ListNode p =head;p!=NULL;p=p.Next){
        //迭代遍历p.val
    }
}

void traverse(ListNode head){
    cout<<head.val;
    traverse(head.next);//前序遍历
}

void traverse(ListNode head){
   
    traverse(head.next);//后序遍历
    cout<<head.val;
}
```


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;二叉树遍历框架如下:
```C++
class TreeNode{
    int val;
    TreeNode left,right;
}
void preorder(TreeNode root){ //前序
    cout<<root.val;
    preorder(root.left);
    preorder(root.right);
}

void inorder(TreeNode root){//中序
    inorder(root.left);
    cout<<root.val;
    inorder(root.right);
}

void postorder(TreeNode root){//后序
    postorder(root.left);
    postorder(root.right);
    cout<<root.val;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;N叉树遍历框架如下:
```C++
class TreeNode {
    int val;
    TreeNode[] children;
}

void traverse(TreeNode root){
    for(TreeNode child:root.children){
        traverse(child);
    }
}


## 1.2  动态规划解题套路框架