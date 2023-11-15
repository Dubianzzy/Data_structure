/******************************************************
 * Created by David Song in 2016-5-11
 *
 * Note:
 *   1. Link implementation of binary tree
 *   2. use a header node to simplifing implementation
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct treenode {
  DataType data;
  struct treenode * leftChild;
  struct treenode * rightChild;
}TreeNode;

void Initiate(TreeNode **root) {
  *root = (TreeNode *)malloc(sizeof(TreeNode));
  (*root)->leftChild = NULL;
  (*root)->rightChild = NULL;
}

/* curr指针所指结点的左孩子处插入新结点，以前的左孩子变成新节点的左孩子 */
TreeNode *InsertLeftNode(TreeNode *curr, DataType x) {
  TreeNode *s, *t;
  if (curr == NULL)  // 当前指针为空，没有指向有效结点
    return NULL;
  t = curr->leftChild;
  s = (TreeNode *)malloc(sizeof(TreeNode));
  s->data = x;
  s->leftChild = t;
  s->rightChild = NULL;
  curr->leftChild = s;
  return curr->leftChild;
}

/* curr指针所指结点的右孩子处插入新结点，以前的右孩子变成新节点的右孩子 */
TreeNode *InsertRightNode(TreeNode *curr, DataType x) {
  // 在此处添加函数代码
}

void PrintBiTree(TreeNode *bt, int n) {
  int i;
  if (bt == NULL) return;
  PrintBiTree(bt->rightChild, n+1);
  for (i = 0; i < n-1; i++) printf("   ");
  if (n > 0) {
    printf("---");
    printf("%c\n", bt->data);
  }
  PrintBiTree(bt->leftChild, n+1);
}

int main() {
  TreeNode *root, *p, *pp;

  Initiate(&root);
  p = InsertLeftNode(root, 'A');
  p = InsertLeftNode(p, 'B');
  p = InsertLeftNode(p, 'D');
  p = InsertRightNode(p, 'G');
  p = InsertRightNode(root->leftChild, 'C');
  pp = p;
  InsertLeftNode(p, 'E');
  InsertRightNode(pp, 'F');
  PrintBiTree(root->leftChild, 1);
  return 0;
}




