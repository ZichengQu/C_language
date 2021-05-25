#include "10.1 tree.h"

// 微函数，可通过attr(tree)表达tree->attr
#define data(tree) ((tree)->data)
#define left(tree) ((tree)->left)
#define right(tree) ((tree)->right)

/**
 * 定义结构体
 */
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * 创建一个TreeNode
 */
Tree makeTreeNode(int data) {
    Tree treeNode = malloc(sizeof(struct TreeNode));
    if(treeNode == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    treeNode->data = data;
    treeNode->left = treeNode->right = NULL;
    return treeNode;
}

/**
 * 向tree的leaf中插入值, 若该值已存在，则不做操作.
 * 传入的tree可以为空，若tree为空，会先自动创建一个空树[代替了Tree createTree()]，再向该tree中插入data
 */
Tree insertAtLeaf(Tree tree, int data) {
    if(tree == NULL) {
        return makeTreeNode(data);
    } else if(data < data(tree)) {
        left(tree) = insertAtLeaf(left(tree), data);
    } else if(data > data(tree)) {
        right(tree) = insertAtLeaf(right(tree), data);
    }
    return tree;
}

/**
 * 在该tree中查找data是否存在
 */
bool searchTree(Tree tree, int data) {
    if(tree == NULL) {
        return false;
    } else if(data < data(tree)) {
        return searchTree(left(tree), data);
    } else if(data > data(tree)) {
        return searchTree(right(tree), data);
    } else {
        return true;
    }
}

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
Tree joinTree(Tree t1, Tree t2) {
    if(t1 == NULL) {
        return t2;
    } else if(t2 == NULL) {
        return t1;
    } else {
        Tree curr = t2;
        Tree parent = NULL;
        while(left(curr) != NULL) {
            parent = curr;
            curr = left(curr);
        }
        if(parent != NULL) {
            left(parent) = right(curr);
            right(curr) = t2;
        }
        left(curr) = t1;
        return curr;
    }
}

/**
 * 从Tree里删除值为data的结点
 */
Tree deleteTree(Tree tree, int data) {
    if(tree != NULL) {
        if(data < data(tree)) {
            left(tree) = deleteTree(left(tree), data);
        } else if(data < data(tree)) {
            right(tree) = deleteTree(right(tree), data);
        } else {
            Tree new = NULL;
            if(left(tree) == NULL && right(tree) == NULL) {
                free(tree);
                new = NULL;
            } else if(left(tree) == NULL) {
                new = right(tree);
            } else if(right(tree) == NULL) {
                new = left(tree);
            } else {
                new = joinTree(left(tree), right(tree));
            }
            free(tree);
            tree = new;
        }
    }
    return tree;
}

/**
 * 获取该Tree的高度
 */
int heightTree(Tree tree) {
    if(tree == NULL) {
        return 0;
    } else {
        int leftHeight = heightTree(left(tree));
        int rightHeight = heightTree(right(tree));
        return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
}

/**
 * 获取该Tree里的Nodes的个数
 */
int countNodes(Tree tree) {
    if(tree == NULL) {
        return 0;
    } else {
        int leftNodes = countNodes(left(tree));
        int rightNodes = countNodes(right(tree));
        return leftNodes + rightNodes + 1;
    }
}

/**
 * 获取该Tree里的Leaf的个数
 */
int countLeaves(Tree tree) {
    if(tree == NULL) {
        return 0;
    } else if(left(tree) == NULL && right(tree) == NULL){
        return 1;
    }else {
        int leftLeaf = countLeaves(left(tree));
        int rightLeaf = countLeaves(right(tree));
        return leftLeaf + rightLeaf;
    }
}

/**
 * 前序打印该tree
 */
void printTreePreOrder(Tree tree) {
    if(tree) {  // tree != NULL
        printf("%d ", data(tree));
        printTreePreOrder(left(tree));
        printTreePreOrder(right(tree));
    }
}

/**
 * 中序打印该tree
 */
void printTreeInOrder(Tree tree) {
    if(tree) {  // tree != NULL
        printTreeInOrder(left(tree));
        printf("%d ", data(tree));
        printTreeInOrder(right(tree));
    }
}

/**
 * 后序打印该tree
 */
void printTreePostOrder(Tree tree) {
    if(tree) {  // tree != NULL
        printTreePostOrder(left(tree));
        printTreePostOrder(right(tree));
        printf("%d ", data(tree));
    }
}

/**
 * 释放掉内存
 * 先从底层开始free，若先释放掉上层，则无法找到底层.
 */
void freeTree(Tree tree) {
    if(tree) {  // tree != NULL
        freeTree(left(tree));
        freeTree(right(tree));

        free(tree);  // 这里才真正的free了tree里的一个一个的node.
    }
}