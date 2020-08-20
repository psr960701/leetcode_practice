class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> pre(n + 1);
        for(int i=0;i<=n;i++){
            pre[i]=i;
        }
        int l,r;
        for(int i=0;i<=n;i++){
            l=max(0,i-ranges[i]);
            r=min(n,i+ranges[i]);
            pre[r]=min(pre[r],l);
        }
        int board=n;
        int nextboard=INT_MAX;
        int ans=0;
        for(int i=n;i>0;i--)
        {
            nextboard=min(nextboard,pre[i]);
            if(board==i){
                if(nextboard>=i){
                    return -1;
                }
                ans++;
                board=nextboard;
            }
        }
        return ans;
    }
};

