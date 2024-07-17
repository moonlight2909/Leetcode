class Solution {
public:
    void f(TreeNode* root, vector<TreeNode*>& ans, unordered_set<int>& st, bool is_root) {
        if (root == nullptr) {
            return;
        }
        bool deleted = st.count(root->val) > 0;
        if (is_root && !deleted) {
            ans.push_back(root);
        }
        f(root->left, ans, st, deleted);
        f(root->right, ans, st, deleted);
        if (root->left && st.count(root->left->val)) {
            root->left = nullptr;
        }
        if (root->right && st.count(root->right->val)) {
            root->right = nullptr;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        f(root, ans, st, true);
        return ans;
    }
};
