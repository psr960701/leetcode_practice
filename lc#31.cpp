class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n,temp;
        int l,r;
        n = nums.size();
        int i=n-2;
        while(i>=0&&nums[i+1]<=nums[i]){
            i--;
        }
        int j=n-1;
        if(i>=0){
            while(j>=0&&nums[j]<=nums[i])
            {
                j--;
            }
        temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        }
        
        l=i+1;r=n-1;
        while(l<r){
            temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
    }
};