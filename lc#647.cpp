// 思路同#5，dp方程 f[i][len]=f[i+1][len-2] && s[i]==s[i+len-1]
class Solution {
public:
    int countSubstrings(string s) {
        bool f[1020][1020];
        int n = s.length();
        int ans = n;
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            f[i][0]=true;
            f[i][1]=true;
        }
        for(int len=2;len<=n;len++)
            for(int i=0;i<=n-len;i++)
                if(i+1<n && f[i+1][len-2] && s[i]==s[i+len-1])
                {
                    ans++;
                    f[i][len] = true;
                }
        return ans;
    }
};