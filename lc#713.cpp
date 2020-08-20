class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if (k<=1) return 0;
        int ans=0;
        int l=0;
        int r=0;
        long long mul=1;
        while(r<n){
            mul=mul*nums[r];
            while (mul>=k){
                mul=mul/nums[l];
                    l++;
            }
            ans = ans +r-l+1;
            r++;
        }
        return ans;
    }
};