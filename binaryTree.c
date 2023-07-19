#include <stdio.h>
#include <stdlib.h>
struct tree {
  int data;
  struct tree *right;
  struct tree *left;
};

void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);

int main() {
  // initialization of root node
  struct tree *root = NULL;
  root = (struct tree *)malloc(sizeof(struct tree));
  root->data = 1;
  // initialization of left child
  root->left = (struct tree *)malloc(sizeof(struct tree));
  root->left->data = 2;
  root->left->left = NULL;
  root->left->right = (struct tree *)malloc(sizeof(struct tree));
  root->left->right->data = 3;
  root->left->right->left = NULL;
  root->left->right->right = NULL;
  // initialization of right child
  root->right = (struct tree *)malloc(sizeof(struct tree));
  root->right->data = 4;
  root->right->left = NULL;
  root->right->right = NULL;

  // inorder traversal of binary tree
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  // preorder traversal of binary tree
  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");
  // postorder traversal of binary tree
  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  return 0;
}

// inorder traversal
void inorder(struct tree *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}
// preorder traversal
void preorder(struct tree *root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  inorder(root->left);
  inorder(root->right);
}
// postorder traversal
void postorder(struct tree *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  inorder(root->right);
  printf("%d ", root->data);
}