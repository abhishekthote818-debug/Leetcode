class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.empty() || postorder.empty())
            return NULL;

        // Last element of postorder = root
        TreeNode* root = new TreeNode(postorder.back());

        // Find root in inorder
        int pos = 0;
        while (inorder[pos] != postorder.back())
            pos++;

        // Left subtree
        vector<int> leftInorder(inorder.begin(), inorder.begin() + pos);
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + pos);

        // Right subtree
        vector<int> rightInorder(inorder.begin() + pos + 1,
                                  inorder.end());
        vector<int> rightPostorder(postorder.begin() + pos,
                                   postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};