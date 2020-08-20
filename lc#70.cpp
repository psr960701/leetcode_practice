class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        long long f1,f2;
        f1=1;
        f2=2;
        int temp;
        for(int i=3;i<=n;i++)
        {
            temp = f1+f2;
            f1=f2;
            f2=temp;
        }
        return temp;
    }
};
/*
这个题真没啥好说的
爬到N楼的方法有多少种
*/