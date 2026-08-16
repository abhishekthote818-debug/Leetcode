class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> left = generate(start, root - 1);
            vector<TreeNode*> right = generate(root + 1, end);

            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};