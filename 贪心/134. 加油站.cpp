在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
输入: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。

// 思路：暴力
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();++i){
            int index = (i+1)%gas.size();
            int res = gas[i]-cost[i];
            while(index!=i&&res>0){
                res +=gas[index]-cost[index];
                index = (index+1)%gas.size();
            }
            if(index==i&&res>=0)
                return index;
        }
        return -1;
    }
};

// 贪心
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum=0;
        int cost_sum=0;
        int total_sum = 0;
        int index = 0;
        for(int i=0;i<gas.size();++i){
            total_sum += gas[i]-cost[i];
            gas_sum += gas[i];
            cost_sum += cost[i];
            if(gas_sum-cost_sum<0){ // 累积和小于0.从下一个索引开始，并把累计和值为0
                index =i+1;
                gas_sum=0;
                cost_sum=0;
            }
        }
        if(total_sum<0)
            return -1;
        return index;
    }
};