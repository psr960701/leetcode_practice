class Solution {
public:
    double find(vector<int>& nums1,vector<int>& nums2,int mid)
    {   
        int l1=0;
        int l2=0;
        int pn,pm;
        int k=mid;
        int n=nums1.size();
        int m=nums2.size();
        while(true){
            if(l1==n){
                return nums2[l2+k-1];
            }
            if(l2==m){
                return nums1[l1+k-1];
            }
            if(k==1){
                return min(nums1[l1],nums2[l2]);
            }
            pn=min(l1+k/2-1,n-1);
            pm=min(l2+k/2-1,m-1);
            if(nums1[pn]<=nums2[pm])
            {
                k-=pn-l1+1;
                l1=pn+1;
            } else
            {
                k-=pm-l2+1;
                l2=pm+1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num=nums1.size()+nums2.size();
        if(num&1)
        {
            return find(nums1,nums2,(num+1)/2);
        } else
        {
            return (find(nums1,nums2,num/2)+find(nums1,nums2,num/2+1))/2.0;
        }
        return 0;
    }
};