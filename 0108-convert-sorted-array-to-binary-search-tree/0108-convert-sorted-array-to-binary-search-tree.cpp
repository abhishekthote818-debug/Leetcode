class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;

        // Middle element becomes root
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Left half → left subtree
        root->left = build(nums, left, mid - 1);

        // Right half → right subtree
        root->right = build(nums, mid + 1, right);

        return root;
    }
};