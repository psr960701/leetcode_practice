/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

manacher算法可以后期再考虑怎么写
*/
class Solution {
public:
    string longestPalindrome(string s) {
        bool f[1002][1002];
        int n = s.length();
        int ans=1;
        string ansstr ="";
        ansstr+=s[0];
        for(int i=0;i<n;i++)
            {
                f[i][0]=true;
                f[i][1]=true;
            }
        for(int len=2;len<=n;len++)
            for(int i=0;i<=n-len;i++)
            {
                if(i+1<n){
                    f[i][len] = f[i+1][len-2] && (s[i]==s[i+len-1]);
                    if(f[i][len] && len>ans) {
                        ans=len;
                        ansstr=s.substr(i,len);
                    }
                }
            }
        return ansstr;
    }
};