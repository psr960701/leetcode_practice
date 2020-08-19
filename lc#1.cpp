// 两数之和 练手题
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int minus;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            minus=target-nums[i];
            if (m.count(minus)){
                ans.push_back(i);
                ans.push_back(m[minus]);
                return ans;
            } else
            {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};