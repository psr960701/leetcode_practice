class Solution {
public:
    int quickselect(vector<int>& nums,int i,int j,int k){
        int l=i,r=j;
        int p1=l,p2=l;
        // if (l==r) return nums[l];
        int now=(l+r)/2;
        swap(nums[now],nums[r]);
        while(p2<r){
            if(nums[p2]<=nums[r]){
                swap(nums[p1],nums[p2]);
                p1++;
            }
            p2++;
        }
        swap(nums[p1],nums[r]);
        if(r==p1+k-1) return nums[p1];
        if(r>p1+k-1) return quickselect(nums,p1+1,r,k);
        return quickselect(nums,l,p1-1,k-(r-p1+1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickselect(nums,0,nums.size()-1,k);
    }
};