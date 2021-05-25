#include <stdio.h>
#include <stdlib.h>

#include "10.1 tree.h"

int main(int argc, char** argv) {
    Tree tree1 = NULL;
    Tree tree2 = NULL;

    /*
     *   1
     *       2
     *           3
    */
    tree1 = insertAtLeaf(tree1, 10);
    tree1 = insertAtLeaf(tree1, 5);
    tree1 = insertAtLeaf(tree1, 14);
    printf("tree1的结点数为: %d\n", countNodes(tree1));
    printf("tree1的叶子数为: %d\n", countLeaves(tree1));
    printf("tree1的高度为: %d\n", heightTree(tree1));

    tree2 = insertAtLeaf(tree2, 30);
    tree2 = insertAtLeaf(tree2, 24);
    tree2 = insertAtLeaf(tree2, 29);
    tree2 = insertAtLeaf(tree2, 32);
    printf("\ntree2的结点数为: %d\n", countNodes(tree2));
    printf("tree2的叶子数为: %d\n", countLeaves(tree2));
    printf("tree2的高度为: %d\n", heightTree(tree2));

    Tree tree = joinTree(tree1, tree2);
    printf("\njoin之后的tree的结点数为: %d\n", countNodes(tree));
    printf("join之后的tree的叶子数为: %d\n", countLeaves(tree));
    printf("join之后的tree的高度为: %d\n", heightTree(tree));

    printf("\njoin之后的tree的遍历: ");
    printf("\nPre Order Traversal: ");
    printTreePreOrder(tree);
    printf("\n");

    printf("In Order Traversal: ");
    printTreeInOrder(tree);
    printf("\n");

    printf("Post Order Traversal: ");
    printTreePostOrder(tree);
    printf("\n");

    tree = deleteTree(tree, 10);

    printf("\n删除该tree中的结点10之后的遍历: ");
    printf("\nPre Order Traversal: ");
    printTreePreOrder(tree);
    printf("\n");

    printf("In Order Traversal: ");
    printTreeInOrder(tree);
    printf("\n");

    printf("Post Order Traversal: ");
    printTreePostOrder(tree);
    printf("\n");

    freeTree(tree);

    return 0;
}