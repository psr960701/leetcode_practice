// 无重复字符的最长子串，用滑动窗口+哈希表处理
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n==0) return 0;
        if (n==1) return 1;
        unordered_set<char> a_set;
        int rp=0;
        int ans=1;
        a_set.insert(s[0]);
        for(int i=1;i<n;i++)
            if (!a_set.count(s[i])) 
                {
                    a_set.insert(s[i]);
                    rp=i;
                    ans=i+1;
                }
            else 
                break;
        for(int i=1;i<n;i++){
            a_set.erase(s[i-1]);
            while(rp+1<n&&!a_set.count(s[rp+1]))
            {
                rp++;
                a_set.insert(s[rp]);
            }
            ans = max(ans,rp-i+1);
        }
        return ans;
    }
};