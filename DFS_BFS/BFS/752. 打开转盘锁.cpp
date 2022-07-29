/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-27 18:37:55
 */
// 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
// 每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
// 字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

// 思路：BFS 选择最短路径

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int times;  //次数
        string start = "0000"; // 初始状态
        queue<pair<string,int>> q;  //队列，存的是每一层的字符串以及当前层数的次数
        set<string> SET;//已经访问过的结点，防止死循环
        set<string> deads;// 把死区节点加入deads集合
        for(auto i:deadends)
            deads.insert(i);

        if(deads.count(start)) // start在死区里面直接return
            return -1;

        q.push({start,0});
        SET.insert(start);
        while(!q.empty()){
            string cur = q.front().first; // 列队取出元素
            times = q.front().second;
            q.pop();
            // cout<<cur<<endl;
            if(target==cur) // 当前等于target，返回次数
                return times;
            else if(target != cur){
                for(int i = 0; i < start.size(); i++){
                    string plus = Plus(cur,i);
                    string minus = Minus(cur,i);
                    if(!deads.count(plus)&&!SET.count(plus)){ //满足条件，不在死区，不是之前出现过的
                        q.push({plus,times+1}); // 加入
                        SET.insert(plus);
                    }
                    if(!deads.count(minus)&&!SET.count(minus)){
                        SET.insert(minus);
                        q.push({minus,times+1});
                    }
                }
            }
        }
        return -1;
    }
    string Plus(string s,int index){
        if(s[index]=='9')
            s[index] = '0';
        else 
            s[index] += 1;
        return s;
    }

    string Minus(string s,int index){
        if(s[index]=='0')
            s[index] ='9';
        else
            s[index] -= 1;
        return s;
    }
};



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> memo;
        for(auto deadend:deadends){
            memo.insert(deadend);
        }
        // 0000在deadends里面
        if(memo.find("0000")!=memo.end()){
            return -1;
        }
        // 0000就是target
        if("0000"==target)
            return 0;
        int ans = 0;
        queue<string> q;
        q.push("0000");
        unordered_set<string> travermemo;
        travermemo.insert("0000");

        while(!q.empty()){
            ++ans;
            // 遍历队列当前的个数的字符串
            int size = q.size();
            while(size--){
                string str = q.front();
                q.pop();
                // 遍历四位
                for(int i=0;i<4;++i){
                    vector<string> substrs = change(str, i);
                    // 每一位分别加减
                    for(int j=0;j<2;++j){
                        string tmp = substrs[j];
                        // 相等 退出
                        if(tmp==target){
                            return ans;
                        // 如果是死锁里面的  不加入
                        }else if(memo.find(tmp)!=memo.end()){
                            continue;
                        // 如果是加入过队列的 不加入
                        }else if(travermemo.find(tmp)==travermemo.end()){
                            travermemo.insert(tmp);
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        return -1;
    }

    vector<string> change(string str,int i){
        vector<string> substrs;
        string tmp = str;
        if(str[i]=='0'){
            tmp[i] ='9';
            substrs.push_back(tmp);
            tmp = str;
            tmp[i]=tmp[i]+1;
            substrs.push_back(tmp);
        }else if(str[i]=='9'){
            tmp[i] ='0';
            substrs.push_back(tmp);
            tmp = str;
            tmp[i]=tmp[i]-1;
            substrs.push_back(tmp);
        }else{
            tmp[i] += 1;
            substrs.push_back(tmp);
            tmp[i]-=2;
            substrs.push_back(tmp);
        }
        return substrs;   
    }

};

// 双向BFS