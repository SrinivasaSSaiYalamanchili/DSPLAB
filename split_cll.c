#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void splitList(struct Node *head, struct Node **head1_ref,struct Node **head2_ref)
{
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;

  if(head == NULL)
    return;

  while(fast_ptr->next != head &&
         fast_ptr->next->next != head)
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  }

  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;

  *head1_ref = head;

  if(head->next != head)
    *head2_ref = slow_ptr->next;

  fast_ptr->next = slow_ptr->next;
  slow_ptr->next = head;
}

void push(struct Node **head_ref, int data)
{
  struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;
    temp->next = ptr1;
  }
  else
     ptr1->next = ptr1;
  *head_ref = ptr1;
}

void printList(struct Node *head)
{
  struct Node *temp = head;
  if(head != NULL)
  {
    printf("");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}

int main()
{
  int list_size, i;
  int list[100];
  struct Node *head = NULL;
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;
  printf("enter list size\n");
  scanf("%d",&list_size);
  printf("enter list\n");
  for(i=0;i<list_size;i++)
  {
      scanf("%d",&list[i]);
  }
  for(i=(list_size-1);i>=0;i--)
  {
      push(&head, list[i]);
  }

  printf("Original Circular Linked List\n");
  printList(head);
  splitList(head, &head1, &head2);
  printf("\n");
  printf("First Circular Linked List\n");
  printList(head1);
  printf("\n");
  printf("Second Circular Linked List\n");
  printList(head2);
  return 0;
}
