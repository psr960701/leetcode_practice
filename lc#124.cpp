/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
对于每一个节点来说，它有可能更新最终答案
ans=max(node->val+dfs(node->left)+dfs(node->right)) node为任一节点
dfs 的 return结果为 node->val+max(dfs(node->left),dfs(node->right)) 其中left和right最小值为0如果为负数直接舍弃。
*/
class Solution {
public:
    long long ans=-2200000000;
    long long dfs(TreeNode* node) {
        long long left=0,right=0;
        long long temp;
        long long ls;//short for lin shi bian liang
        temp=node->val;
        if(node->left) {
                ls=dfs(node->left);
                if (ls>0) left=ls;
            }
        if(node->right) {
                ls=dfs(node->right);
                if (ls>0) right=ls;
            }
        temp+=(left+right);
        if (temp>ans) ans=temp;
        return (node->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        long long left=0,right=0;
        long long temp=root->val;
        long long ls;
        if(root->left) {
            ls=dfs(root->left);
            if (ls>0) left=ls;
        }
        if(root->right) {
            ls=dfs(root->right);
            if (ls>0) right=ls;
        }
        temp+=(left+right);
        if (temp>ans) ans=temp;
        return ans;
    }
};