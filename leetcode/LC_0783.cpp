// =====================================================
//   Author  :   eezyl
//   Synopsis:   leetcode template
//   Address :   https://leetcode.com/problems/minimum-distance-between-bst-nodes/
//   Date    :   2020/04/20
// =====================================================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = 2147483647;
        vector<int> order;
        dfs(root, order);
        //sort(order.begin(), order.end());
        for (int i = 0; i < order.size()-1; ++i)
            ans = min(ans, order[i+1]-order[i]);
        return ans;
    }
    void dfs (TreeNode* curNode, vector<int>& order) {
        if (curNode == NULL) {
            return;
        }
        dfs(curNode->left, order);
        order.push_back(curNode->val);
        dfs(curNode->right, order);
    }
};
