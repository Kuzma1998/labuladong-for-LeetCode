/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-13 09:03:01
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-13 09:03:02
 */
// 实现RandomizedSet 类：
// RandomizedSet() 初始化 RandomizedSet 对象
// bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
// bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
// int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
// 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 


class RandomizedSet {
private:
    unordered_map<int,int> map;
    vector<int> nums;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.count(val))
            return false;
        else{
            map[val] = nums.size() ;
            nums.push_back(val);
            return true;
        }
    }


    bool remove(int val) {
        if(!map.count(val)){
            return false;
        }
        int index = map[val];
        map[nums.back()] = index; 
        swap(nums.back(),nums[map[val]]);
        nums.pop_back();
        map.erase(val); 
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
