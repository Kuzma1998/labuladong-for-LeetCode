// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 示例 1:
// 输入: [10,2]
// 输出: "102"
// 示例 2:
// 输入: [3,30,34,5,9]
// 输出: "3033459"

// 思路:排序  手写快排

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto num:nums){
            vec.push_back(to_string(num));
        }
        string ans;
        quicksort(vec,0,vec.size()-1);
        for(auto str:vec){
            ans += str;
        }
        return ans;
    }
private:
    void quicksort(vector<string>& vec,int L,int R){
        if(L<R){
            string pivot = vec[L];
            int i = L+1;
            int j = R;
            while(i<=j){
                while(i<=j&&vec[j]+pivot>=pivot+vec[j]) 
                    --j;
                while(i<=j&&vec[i]+pivot<pivot+vec[j])
                    ++i;
                if(i<=j) 
                    swap(vec[i],vec[j]);
                else 
                    break;
            }
            swap(vec[L],vec[j]);
            quicksort(vec,L,j-1);
            quicksort(vec,j+1,R);
        }
    }
};