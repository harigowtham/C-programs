int Sym(struct TreeNode *left, struct TreeNode *right) {
    if(left==NULL || right == NULL)
        return left == right;
    if (left->val != right->val)
        return 0;
    return Sym(left->left, right->right) && Sym(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    //struct TreeNode *l, *r = root;
    return root == NULL || Sym(root->left, root->right);
    //isSymmetric(->right);

}
