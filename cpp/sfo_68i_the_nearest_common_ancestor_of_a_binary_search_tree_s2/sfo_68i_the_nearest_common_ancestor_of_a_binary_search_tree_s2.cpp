/*
* File: sfo_68i_the_nearest_common_ancestor_of_a_binary_search_tree_s2.cpp
* Created Time: 2021-12-09
* Author: Krahets (krahets@163.com)
*/

#include "../include/include.hpp"

// ===== Solution Code =====
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q);
        while(root != nullptr) {
            if(root->val < p->val) // p,q 都在 root 的右子树中
                root = root->right; // 遍历至右子节点
            else if(root->val > q->val) // p,q 都在 root 的左子树中
                root = root->left; // 遍历至左子节点
            else break;
        }
        return root;
    }
};

int main() {
    // ======= Test Case =======
    TreeNode* root = vectorToTree(vector<int> { 6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX });
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    // ====== Driver Code ======
    Solution* slt = new Solution();
    TreeNode* res = slt->lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
    
    return 0;
}
