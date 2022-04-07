// 通解

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nSum(nums,4,0,target);
    }
    
    vector<vector<int>> nSum(vector<int>& nums,int n, int start, int target){
        int length = nums.size();
        if(n<2||length<n){
            return {};
        }
        vector<vector<int>> res;
        if(n==2){
            int l=start,r=length-1;
            while(l<r){
                int left=nums[l],right = nums[r];
                int sum = nums[l]+nums[r];
                if(sum<target){
                    while (l < r && nums[l] == left) l++;
                }else if(sum>target){
                    while (l < r && nums[r] == right) --r;
                }else{
                    res.push_back({nums[l],nums[r]});
                    while(l<r&&nums[l]==left)  ++l;
                    while(l<r&&nums[r]==right)  --right;
                }
            }
        }
        else{
            for(int i=start;i<length;++i){
                vector<vector<int>> subRes = nSum(nums,n-1,i+1,target-nums[i]);
                for(auto sub:subRes){
                sub.push_back(nums[i]);
                res.push_back(sub);
                }
                while(i<length-1&&nums[i]==nums[i+1])  ++i;
            }
        }
        return res;
    }
};