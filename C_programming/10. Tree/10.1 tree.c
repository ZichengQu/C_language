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
    } else if(left(tree) == NULL && right(tree) == NULL) {
        return 1;
    } else {
        int leftLeaf = countLeaves(left(tree));
        int rightLeaf = countLeaves(right(tree));
        return leftLeaf + rightLeaf;
    }
}

/**
 * 判断两树是否相等(树中的所有的值是否相同)
 */
bool isSameTree(Tree t1, Tree t2) {
    if(t1 == NULL && t2 == NULL) {
        return true;
    } else if(t1 == NULL || t2 == NULL) {
        return false;
    } else if(data(t1) != data(t2)) {
        return false;
    }
    return isSameTree(left(t1), left(t2)) && isSameTree(right(t1), right(t2));
}

void getTreeKthByInOrder(Tree tree, int k, int* index, int* result) {
    if(tree) {  // tree != NULL
        getTreeKthByInOrder(left(tree), k, index, result);
        if((*index) == k) {
            *result = data(tree);
        }
        (*index)++;
        getTreeKthByInOrder(right(tree), k, index, result);
    }
}

/**
 * 从小到大，获取该Tree的第k个值 (中旬遍历是有序的)
 */
int getTreeKth(Tree tree, int k) {
    int result = -1;
    int index = 0;
    getTreeKthByInOrder(tree, k, &index, &result);  // &index 和 &result来代替全局变量.
    return result;
}

/**
 * 通过递归的形式获取该Tree的奇数和
 */
int sumOddTreeRecursion(Tree tree) {
    if(tree == NULL) {
        return 0;
    } else {
        int leftSum = sumOddTreeRecursion(left(tree));
        int rightSum = sumOddTreeRecursion(right(tree));
        return data(tree) % 2 == 1 ? leftSum + rightSum + data(tree) : leftSum + rightSum;
    }
}

/**
 * 用指针地址代替全局变量来获取该Tree的奇数和
 */
void sumOddTreeByPointer(Tree tree, int* sum) {
    if(tree != NULL) {
        sumOddTreeByPointer(left(tree), sum);
        if(data(tree) % 2 == 1) {
            *sum += data(tree);
        }
        sumOddTreeByPointer(right(tree), sum);
    }
}

/**
 * 获取该Tree中所有奇数的和
 */
int sumOddTree(Tree tree) {
    bool flag = true;  // flag为true时使用第一种方法
    if(flag) {
        return sumOddTreeRecursion(tree);  // 方法一：通过递归的形式获取该Tree的奇数和
    } else {
        int sum = 0;  // 方法二：用指针地址代替全局变量来获取该Tree的奇数和
        sumOddTreeByPointer(tree, &sum);
        return sum;
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

/* AVL TREE */

/**
 * Right rotation
 * 
 *            n1                               n2
 *      n2          t3   rotateRight -->  t1         n1
 *  t1      t2           <-- rotateLeft          t2      t3
 * 
 */
Tree rotateRight(Tree n1) {
    if(n1 == NULL || left(n1) == NULL) {
        return n1;
    }
    Tree n2 = left(n1);

    // 将需要变化的结点从原n1中取出来
    // Tree t1 = left(n2); // (1) 与原有结构一致，无需重新定义
    // Tree t2 = right(n2); // (3)
    // Tree t3 = right(n1); // (2) 与原有结构一致，无需重新定义

    // 将需要变化的结点插入到n2中
    // left(n2) = t1; // (1) 与原有结构一致，无需重新定义
    left(n1) = right(n2);  // 这两行可以代替
    right(n2) = n1;        // (3), (4), (5)
    // right(n2) = n1; // (4)
    // left(n1) = t2; // (5)
    // right(n1) = t3; // (2) 与原有结构一致，无需重新定义

    return n2;
}

Tree rotateLeft(Tree n2) {
    if(n2 == NULL || right(n2) == NULL) {
        return n2;
    }
    Tree n1 = right(n2);
    right(n2) = left(n1);
    left(n1) = n2;

    return n1;
}

/**
 * Splay tree insertion
 * 二叉查找树的一种改进数据结构–伸展树(Splay Tree)。它的主要特点是不会保证树一直是平衡的,但各种操作的平摊时间复杂度是O(log n)
 * 可视化流程详见 "img/tree/Splay Tree 1.png" 和 "img/tree/Splay Tree 2.png" 和 "img/tree/Splay Tree 3.png"
 */
Tree insertSplayTree(Tree tree, int data) {
    if(tree == NULL) {
        return makeTreeNode(data);
    } else if(data == data(tree)) {
        return tree;
    } else if(data < data(tree)) {
        if(left(tree) == NULL) {
            left(tree) = makeTreeNode(data);
        } else if(data < data(left(tree))) {
            // Case 1: left-child of left-child "zig-zig"
            left(left(tree)) = insertSplayTree(left(left(tree)), data);
            tree = rotateRight(tree);
        } else if(data > data(left(tree))) {
            // Case 2: right-child of left-child "zig-zag"
            right(left(tree)) = insertSplayTree(right(left(tree)), data);
            left(tree) = rotateLeft(left(tree));
        }
        return rotateRight(tree);
    } else {  // data > data(tree)
        if(right(tree) == NULL) {
            right(tree) = makeTreeNode(data);
        } else if(data < data(right(tree))) {
            // Case 3: left-child of right-child "zag-zig"
            left(right(tree)) = insertSplayTree(left(right(tree)), data);
            right(tree) = rotateRight(right(tree));
        } else if(data > data(right(tree))) {
            // Case 4: right-child of right-child "zag-zag"
            right(right(tree)) = insertSplayTree(right(right(tree)), data);
            tree = rotateLeft(tree);
        }
        return rotateLeft(tree);
    }
}

// AVL Tree 详见"img/tree/AVL Tree.png"的伪码描述
