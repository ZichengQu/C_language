#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* Tree;  // 重新命名这个结构体类型

/**
 * 向tree的leaf中插入值
 * 传入的tree可以为空，若tree为空，会先自动创建一个空树[代替了Tree createTree()]，再向该tree中插入data
 */
Tree insertAtLeaf(Tree tree, int data);

/**
 * 在该tree中查找data是否存在
 */
bool searchTree(Tree tree, int data);

/**
 * 合并两个Tree
 * Pre-conditions:
 *      takes two BSTs; returns a single BST
 *      max(key(t1)) < min(key(t2))
 * Post-conditions:
 *      result is a BST (i.e. fully ordered)
 *      containing all items from t1 and t2
 * t1:      10          t2:      30
 *       5     14          24        32
 *                             29
 * result:           24
 *             10          30
 *           5    14    29    32
 */
Tree joinTree(Tree t1, Tree t2);

/**
 * 从Tree里删除值为data的结点
 */
Tree deleteTree(Tree tree, int data);

/**
 * 获取该Tree的高度
 */
int heightTree(Tree tree);

/**
 * 获取该Tree里的Nodes的个数
 */
int countNodes(Tree tree);

/**
 * 获取该Tree里的Leaf的个数
 */
int countLeaves(Tree tree);

/**
 * 判断两树是否相等(树中的所有的值是否相同)
 */
bool isSameTree(Tree t1, Tree t2);

/**
 * 从小到大，获取该Tree的第k个值 (中旬遍历是有序的)
 */
int getTreeKth(Tree tree, int k);

/**
 * 获取该Tree中所有奇数的和
 */
int sumOddTree(Tree tree);

/**
 * 前序打印该tree
 */
void printTreePreOrder(Tree tree);

/**
 * 中序打印该tree
 */
void printTreeInOrder(Tree tree);

/**
 * 后序打印该tree
 */
void printTreePostOrder(Tree tree);

/**
 * 释放掉内存
 */
void freeTree(Tree tree);

/**
 * Splay tree insertion
 * 二叉查找树的一种改进数据结构–伸展树(Splay Tree)。它的主要特点是不会保证树一直是平衡的,但各种操作的平摊时间复杂度是O(log n)
 * 可视化流程详见 "img/tree/Splay Tree 1.png" 和 "img/tree/Splay Tree 2.png" 和 "img/tree/Splay Tree 3.png"
 */
Tree insertSplayTree(Tree tree, int data);
