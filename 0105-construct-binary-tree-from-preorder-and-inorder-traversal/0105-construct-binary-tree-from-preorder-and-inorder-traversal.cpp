class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.empty() || inorder.empty())
            return NULL;

        // First element of preorder is root
        TreeNode* root = new TreeNode(preorder[0]);

        // Find root in inorder
        int pos = 0;
        while (inorder[pos] != preorder[0])
            pos++;

        // Left subtree
        vector<int> leftInorder(inorder.begin(), inorder.begin() + pos);
        vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + 1 + pos);

        // Right subtree
        vector<int> rightInorder(inorder.begin() + pos + 1,
                                  inorder.end());
        vector<int> rightPreorder(preorder.begin() + 1 + pos,
                                  preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};