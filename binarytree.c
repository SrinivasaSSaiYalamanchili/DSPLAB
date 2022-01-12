#include<stdio.h>
#include<conio.h>

struct Node{
   int data;
   struct Node *left;
   struct Node *right;
};

struct Node *root = NULL;
int count = 0;

struct Node* insert(struct Node *root,int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(root == NULL){
      newNode->left = newNode->right = NULL;
      root = newNode;
      count++;
   }
   else{
      if(count%2 != 0)
            root->left = insert(root->left,value);
      else
            root->right = insert(root->right,value);
   }
   return root;
}

void display(struct Node *ptr,int level)
{
        int i;
        if ( ptr!=NULL )
        {
                display(ptr->right, level+1);
                printf("\n");
                for (i = 0; i < level; i++)
                        printf("    ");
                printf("%d", ptr->data);
                display(ptr->left, level+1);
        }
}

void inorderTraversal(struct Node *root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->data);
  inorderTraversal(root->right);
}


void preorderTraversal(struct Node *root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void postorderTraversal(struct Node *root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}

int findHeight(struct Node *temp){
    if(root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    else {
        int leftHeight = 0, rightHeight = 0;

        if(temp->left != NULL)
            leftHeight = findHeight(temp->left);

        if(temp->right != NULL)
            rightHeight = findHeight(temp->right);

        int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;
        return (max + 1);
    }
}


void main(){
  int choice, value;
  printf("\nBinary Tree\n");
  int n,no,i,a[100];
  printf("Enter No of Nodes:\n");
  scanf("%d",&n);
  printf("Enter Nodes:\n");
  for(i=1;i<=n;i++)
  {
      scanf("%d",&a[i]);
      root = insert(root,a[i]);
  }
  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
  printf("\nMaximum height of given binary tree: %d", findHeight(root));
  display(root,0);
  printf("\n");
}
