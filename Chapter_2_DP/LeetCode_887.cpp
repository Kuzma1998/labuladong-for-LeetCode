// 给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
// 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。
// 每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。
// 如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
// 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少
// 输入：k = 1, n = 2
// 输出：2
// 解释：
// 鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。 
// 否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。 
// 如果它没碎，那么肯定能得出 f = 2 。 
// 因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。 



class Solution {
private:
    map<pair<int,int>,int> map;
public:
    int superEggDrop(int k, int n) {
        int ans = dp(k,n);
        return ans;
    }
    int dp(int k,int n){
        if(k==1)
            return n;
        if(n==0)
            return 0;
        if(map.count({k,n})){
            return map[{k,n}];
        }
        int res = 1000000;
        for(int i=1;i<=n;i++){
            res = min(max(dp(k-1,i-1)+1,dp(k,n-i)+1),res);
        }
        map[{k,n}] = res;
        return res;
    }
};



class Solution {
private:
    map<pair<int,int>,int> map;
public:
    int superEggDrop(int k, int n) {
        int ans = dp(k,n);
        return ans;
    }
    int dp(int k,int n){
        if(k==1)
            return n;
        if(n==0)
            return 0;
        if(map.count({k,n})){
            return map[{k,n}];
        }
        int res = 1000000;
        // for(int i=1;i<=n;i++){
        //     res = min(max(dp(k-1,i-1)+1,dp(k,n-i)+1),res);
        // }
        int l =1;
        int r = n;
        while(l<=r){
            int mid = (r+l)/2;
            int broken = dp(k-1,mid-1);
            int notbroken = dp(k,n-mid);
            if(broken>notbroken){
                r = mid-1;
                res = min(res,broken+1);
            } else{
                l = mid+1;
                res = min(res,notbroken+1);
            } 

        }
        map[{k,n}] = res;
        return res;
    }
};