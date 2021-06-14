#include<stdio.h>
#include<stdlib.h>
//#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define max(a,b) a>b?a:b
#define MAX_Q_SIZE 500
#define COUNT 5
//stack's max
#define MAX 100
struct node {
  int key;
  struct node *left;
  struct node *right;
};
typedef struct node Node;

Node *create(int key) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->key = key;
  node->left = node->right = NULL;
  return node;
}

Node *insert(Node *root, int key) {
  if(root == NULL){
    //Node *node = create(key);
    return create(key);
  }else if(root->key > key){
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }
  return root;
}

void inorder(Node *root){
  if(root == NULL)
    return;
  inorder(root->left);
  printf("%d", root->key);
  inorder(root->right);
}

void leaf(Node *root) {
  if (root == NULL)
    return;
  leaf(root->left);
  if (root->left == NULL && root->right == NULL)
    printf("%d  ", root->key);
  leaf(root->right);
}

Node *getmin(Node *root) {
  if (root == NULL) {
    printf("empty");
    return root;
  }
  while(root->left) {
    root = root->left;
  }
  return root;
}

Node *delete(Node *root, int key){
  if (root == NULL)
    return root;
  if (root->key == key){
    if (root->left == NULL){
      Node *tmp = root;
      //tmp = root;
      root = root->right;
      free(tmp);
      return root;
    } else if (root->right == NULL) {
      Node *tmp = root;
      //tmp = root;
      root = root->right;
      free(tmp);
      return root;
    }
    Node *tmp = getmin(root->right);
    root->key = tmp->key;
    root->right = delete(root->right, tmp->key);
  }
  if (root->key > key)
    root->left = delete(root->left, key);
  else if (root->key < key)
    root->right = delete(root->right, key);
  return root;
}

int depth(Node *root, int d) {
  if (root == NULL)
    return d;
  int l = depth(root->left, d+1);
  int r = depth(root->right, d+1);
  return max(l,r);
}

Node *lca(Node *root, int k1, int k2) {
  if (root == NULL)
    return NULL;
  if(root->key > k1 && root->key > k2){
    return lca(root->left, k1, k2);
  }
  if(root->key < k1 && root->key < k2){
    return lca(root->right, k1, k2);
  }
  return root;
}

Node *lca_bt(Node *root, int k1, int k2){
  if (root == NULL) return NULL;
  if (root->key == k1) return root;
  else if (root->key == k2) return root;
  Node *left = lca_bt(root->left, k1, k2);
  Node *right = lca_bt(root->right, k1, k2);
  if (left != NULL && right != NULL)
    return root;
  if (left == NULL)
    return right;
  return left;
}
/*UTILITY FUNCTIONS*/
//level order traversal or breadth first traversal
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void level(struct node *root) {
  int front, rear;
  struct node **q = createQueue(&front, &rear);
  struct node *cur = root;
  while(cur!=NULL) {
    printf("%d\t", cur->key);
    if (cur->left != NULL) enQueue(q, &rear, cur->left);
    if (cur->right != NULL) enQueue(q, &rear, cur->right);
    cur = deQueue(q, &front);
  }
}

//path of a bt
Node** creates(int *top) {
	Node **s = (Node **) malloc(sizeof(Node *)*MAX );
	*top = -1;
	return s;
}

void push (Node **s, Node *data, int *top) {
	(*top)++;
	s[(*top)] = data;
}
Node* pop (Node **s, int *top) {
	Node *tmp = s[(*top)];
	(*top)--;
	return tmp;
}

void printstack(Node **s, int *top) {
  printf("printing the path:\n");
  int tmp = *top;
  while(tmp > -1) {
    printf("%d\t", s[tmp]->key);
    tmp--;
  }
}

void path(Node *root, Node **s, int *top, int key) {
  Node *cur = root;
  Node *tmp = NULL;
  if (cur == NULL) {
    return;
  }
  if (cur != NULL) {
    if (cur->key == key) {
      printstack(s, top);
      return;
    }
    push(s, cur, top);
    path(cur->left, s, top, key);
    tmp = pop(s, top);
    push(s, cur, top);
    path(cur->right, s, top, key);
    tmp = pop(s, top);
  }
  return;
}

int main() {
  Node *root = NULL;
  root = insert(root, 5);
  root = insert(root, 8);
  root = insert(root, 6);
  root = insert(root, 4);
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 7);
  //printf("%d", root->key);
  inorder(root);
  printf("\n");
  leaf(root);
  printf("\n");
  printf("depth %d", depth(root, 0));
  root = delete(root, 3);
  printf("\n");
  leaf(root);
  printf("\n");
  inorder(root);
  printf("\n");
  printf("depth %d", depth(root, 0));
  printf("\n");
  printf("about to do lca \n");
  //Node *t = lca(root, 6,7);
  //Node *t = lca(root, 4,8);
  Node *t = lca_bt(root, 1,3);
  printf("lca %d", t->key);
  printf("level order:\n");
  level(root);
  printf("\n");
  printf("path of bt:\n");
  int top;
  Node **s = creates(&top);
  path(root, s, &top, 1);
  return 1;
}
