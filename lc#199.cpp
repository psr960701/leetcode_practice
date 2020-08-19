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
 需要额外处理一下空根节点的情况
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> treeq;
        queue<int> level;
        if(root) treeq.push(root);
        level.push(1);
        while(!treeq.empty()){
            TreeNode* temp;
            int nowlevel;
            temp = treeq.front();
            nowlevel = level.front();
            if(temp->left) {
                treeq.push(temp->left);
                level.push(nowlevel+1);
                }
            if(temp->right) {
                treeq.push(temp->right);
                level.push(nowlevel+1);
            }
            treeq.pop();
            level.pop();
            if (nowlevel!=level.front()) ans.push_back(temp->val);
        }
        return ans;
    }
};