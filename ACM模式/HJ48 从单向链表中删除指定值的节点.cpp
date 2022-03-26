/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-26 20:26:14
 */
// 输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。
// 链表的值不能重复。
// 输入描述：
// 输入一行，有以下4个部分：
// 1 输入链表结点个数
// 2 输入头结点的值
// 3 按照格式插入各个结点
// 4 输入要删除的结点的值
// 输出描述：
// 输出一行
// 输出删除结点后的序列，每个数后都要加空格
// 示例1
// 输入：
// 5 2 3 2 4 3 5 2 1 4 3
// 复制
// 输出：
// 2 5 4 1
// 复制
// 说明：
// 形成的链表为2->5->3->4->1
// 删掉节点3，返回的就是2->5->4->1 


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){
        
    }
    Node(int v): val(v),next(nullptr){
    }
};

int main(){
    int n = 0;
    int hv = 0;
    while(cin>>n>>hv){
        Node* head= new Node(hv);
        int pre = 0,cur = 0;
        --n;
        // 构造链表
        while(n--){
            cin>>cur>>pre;
            Node* node =  head;
            while(node->val!=pre){
                node = node->next;
            }
            Node* next = node->next;
            node->next = new Node(cur);
            node->next->next = next;
        }
        int del = 0;
        cin>>del;
        //删除数据
        if(head->val==del){
            head = head->next;
            while(head){
                cout<<head->val<<" ";
                head = head->next;
            }
        }
        else{
            while(head){
            if(head->val!=del){
                cout<<head->val<<" ";
            }
            head = head->next;
        }
    }
    }
    cout<<endl;
    return 0;
}
