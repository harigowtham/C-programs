/* a map is written in c and used. its similar to dict as well
 * The map here is a map of a map
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 5

struct Node {
        int data;
        struct Node *right;
        struct Node *left;
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

struct Value {
        int hvalue[10];
        int vvalue[10];
};

struct Map {
        int key;
        struct Value value[10];
};

struct Map map[100];

struct Node * newNode (int data) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}

void hash(int key, int data, int v) {
        int i = 0;
        int j = 0;
        //the hashing done is 'key+50' as its an int.
        // if its a string it gets complicated
        //
        while (map[key+50].value[i].hvalue[0] != -1) {
                if ((map[key+50].value[i].vvalue[j] != -1)) {
                       if (map[key+50].value[i].vvalue[j] > v) {
                               return;
                       } else if (map[key+50].value[i].vvalue[j] < v) {
                                break;
                       }
                } else {
                        j++;
                }
                i++;
        }
        map[key+50].value[i].vvalue[j]= v;
        map[key+50].value[i].hvalue[j]= data;
        map[key+50].key = key;
}

void printmap() {
        for (int i= 0; i < 100; i++) {
                //printf("key:%d  ", map[i].key);
                for(int j = 0; j < 5; j++) {
                        if (map[i].value[j].hvalue[0] == -1)
                                break;
                for(int k = 0; k < 5; k++) {
                        /*
                         * DEBUG:
                        if (map[i].value[j].hvalue[k] != -1)
                        printf("hvalue:%d   vvalue:%d  ", map[i].value[j].hvalue[k], map[i].value[j].vvalue[k]);
                        */
                        if (map[i].value[j].hvalue[k] != -1)
                        printf("%d ", map[i].value[j].hvalue[k]);
                        else
                                break;
                }
                }
        }
        return;
}

void printView(struct Node *root, int h, int v,struct Map *map){
        if(root == NULL)
                return;
        //DEBUG
        //printf("%d height: %d\n", root->data, h);
        hash(h, root->data, v);
        printView(root->left, h-1, v+1, map);
        printView(root->right, h+1, v+1,map);
        return;
}

void printBottomView(struct Node *root) {
        memset(map, -1, 100*sizeof(map[0]));
//        memset(map->hvalue, -1, 10*sizeof(map[0].hvalue[0]));
        memset(map->value->hvalue, -1, 10*sizeof(map[0].value[0].hvalue[0]));
        memset(map->value->vvalue, -1, 10*sizeof(map[0].value[0].vvalue[0]));
        printView(root, 0, 0, map);
        return;
}

int main()
{
	struct Node *root = newNode(20);
	root -> left = newNode(8);
	root -> right = newNode(22);
	root -> left -> left = newNode(5);
	root -> left -> right = newNode(3);
	root -> right -> left = newNode(4);
	root -> right -> right = newNode(25);
	root -> left -> right -> left = newNode(10);
	root -> left -> right -> right = newNode(14);
        //cout << "Bottom view of the given binary tree :\n";
	printBottomView(root);
        //DEBUG
        //print2D(root);
        printmap();
	return 0;
}

/*
// C++ Program to print Bottom View of Binary Tree
#include < bits / stdc++.h >
#include < map >
using namespace std;

// Tree node class
struct Node
{
	// data of the node
	int data;

	// horizontal distance of the node
	int hd;

	//left and right references
	Node * left, * right;

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
	// Base case
	if (root == NULL)
		return;

	// If node for a particular
	// horizontal distance is not
	// present, add to the map.
	if (m.find(hd) == m.end())
	{
		m[hd] = make_pair(root -> data, curr);
	}
	// Compare height for already
	// present node at similar horizontal
	// distance
	else
	{
		pair < int, int > p = m[hd];
		if (p.second <= curr)
		{
			m[hd].second = curr;
			m[hd].first = root -> data;
		}
	}

	// Recur for left subtree
	printBottomViewUtil(root -> left, curr + 1, hd - 1, m);

	// Recur for right subtree
	printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(Node * root)
{

	// Map to store Horizontal Distance,
	// Height and Data.
	map < int, pair < int, int > > m;

	printBottomViewUtil(root, 0, 0, m);

	// Prints the values stored by printBottomViewUtil()
	map < int, pair < int, int > > ::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		pair < int, int > p = it -> second;
		cout << p.first << " ";
	}
}
*/

