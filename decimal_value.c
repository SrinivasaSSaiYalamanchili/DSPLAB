#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *q;
struct node *t;
struct node *start = NULL;

int decimalValue(struct node *head)
{
	// Initialized result
	int res = 0;

	// Traverse linked list
	while (head != NULL)
	{
		// Multiply result by 2 and add
		// head's data
		res = (res << 1) + head->data;

		// Move next
		head = head->next;
	}
	return res;
}

void insert_beg()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;

    if(start==NULL)        //If list is empty
    {
        t->next=NULL;
        start=t;
    }
    else
    {
        t->next=start;
        start=t;
    }
}

void insert_end()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;

    if(start==NULL)        //If list is empty
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}

void display()
{
    if(start==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}

int main()
{
    int res,ch;
    while(1)
    {
        printf("\n\nSingly Linked List(SLL) Menu");
        printf("\n1.Insert At Beginning\n2.Insert At End\n3.Display\n4.Compute\n5.Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert_beg();
                    break;
            case 2: insert_end();
                    break;
            case 3: display();
                    break;
            case 4: res= decimalValue(start);
                    printf("%d",res);
                    break;
            case 5: exit(0);
            default: printf("Wrong Choice\n");
        }
    }
    return 0;
}
