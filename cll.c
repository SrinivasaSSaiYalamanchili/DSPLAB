#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
	char arr[3][40];
	struct node *link;
};
struct node *head;
int count=0;

void check()
{
	struct node *ptr;
	int flag=0;
	ptr=head;
	if(head==NULL)
	{
		printf("\nNO ELEMENT IS PRESENT\n");
		exit(1);
	}
	do
	{
		if(strcmp(ptr->arr[2],ptr->link->arr[0]) != 0)
		{
			printf("\nThe element %s does not match with %s in the node",ptr->arr[2],ptr->link->arr[0]);
			flag=1;
		}
		ptr=ptr->link;
	}while(ptr!=head);
	if(flag==0)
		printf("\nSTRING MATCHING SUCCESSFULLY\n");
	else
		printf("\nMISMATCH\n");
}

void display()
{
	struct node *ptr;
	ptr=head;
	printf("\nELEMENTS ARE\n");
	do
	{
		printf("%s ",ptr->arr[0]);
		printf("%s ",ptr->arr[1]);
		printf("%s",ptr->arr[2]);
		ptr=ptr->link;
		printf("\n");
	}while(ptr!=head);
}

void display2()
{
	struct node *ptr;
	char ch;
	ptr=head;
	printf("\nThe list has the following second elements:\n");
	do
	{
		printf("\n%s\n",ptr->arr[1]);
		ptr=ptr->link;
	}while(ptr!=head);
}


void replace()
{
	int i,number,a;
	struct node *ptr;
	printf("\nEnter the number of node you want to replace\n");
	scanf("%d",&number);
	if((number>count) || (number<1))
	{
		printf("\nNode does not exist\n");
		return;
	}
	else
	{
		ptr=head;
		for(i=1;i<number;i++)
		{
			ptr=ptr->link;
		}
		replace:
		printf("\nChoose which string you want to change:\n1 for first\n 2 for second\n 3 for third\n 4 to go to previous\n");
		scanf("%d",&a);
		if(a==4)
			return;
		else if(a>=1 && a<=3)
		{
			printf("\nEnter the string:\n");
			scanf("%s",ptr->arr[a-1]);
		}
		else
		{
			printf("\nInvalid Choice\n");
			goto replace;
		}
	}
	printf("\nString has been replaced to 'color' in the node %d and column %d.\n",number,a);
}

void add()
{
	int i;
	struct node *new=(struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	if(new==NULL)
	{
		printf("\nunable to create memory\n");
		exit(1);
	}
	printf("\nEnter 3 strings for the node\n");
	count++;
	for(i=0;i<3;i++)
	{
		scanf("%s",new->arr[i]);
	}
	ptr=head;
	if(head==NULL)
	{
		head=new;
		head->link=head;
	}
	else
	{
		while(ptr->link!=head)
		ptr=ptr->link;
		ptr->link=new;
		ptr=new;
		ptr->link=head;
		check();
	}
}


void main()
{
	int c=0,i;
	int n;
	printf("ENTER NUMBER OF NODE\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		add();
	}
	menu:
	while(c!=6)
	{
        printf("\n1.Display nodes\n2.Display  second element in all nodes\n3.Replace string Values\n4.String match\n5.exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&c);

		 if (c==1)
		{

			display();
			goto menu;
		}
		else if (c==2)
		{
			display2();
			goto menu;
		}
		else if (c==3)
		{
			replace();
			goto menu;
		}
		else if (c==4)
		{
			check();
			goto menu;
		}
		else if (c==5)
		{
			printf("\nExit\n");
			exit(1);
		}
		else
		{
			printf("\nInvalid\n");
			goto menu;
		}
}}
