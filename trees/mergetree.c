struct TreeNode* nnode(int data) {
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    struct TreeNode *newnode = NULL;
    if(t1 != NULL && t2 != NULL){
    newnode = nnode(t1->val+t2->val);
    newnode->left = mergeTrees(t1->left, t2->left);
    newnode->right = mergeTrees(t1->right, t2->right);
    } else if (t2 != NULL) {
        newnode = nnode(t2->val);
        newnode->left = mergeTrees(NULL, t2->left);
        newnode->right = mergeTrees(NULL, t2->right);
    } else if (t1 != NULL) {
        newnode = nnode(t1->val);
        newnode->left = mergeTrees(t1->left, NULL);
        newnode->right = mergeTrees(t1->right, NULL);
    }
    return newnode;
}
