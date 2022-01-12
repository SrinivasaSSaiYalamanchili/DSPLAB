#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 20

int h[TABLE_SIZE]={NULL};

void insert()
{

 int key,index,i,flag=0,hkey,hash2;
 printf("\nenter a value to insert into hash table\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 hash2 = 7-(key %7); //prime number is used here preferably for 2nd hash key
 for(i=0;i<TABLE_SIZE;i++)
 {
    index=(hkey+i*hash2)%TABLE_SIZE;
    if(h[index] == NULL)
    {
        h[index]=key;
        break;
    }
 }
 if(i == TABLE_SIZE)
     printf("\nelement cannot be inserted\n");
}
void search()
{

 int key,index,i,flag=0,hash2,hkey;
 printf("\nenter search element\n");
 scanf("%d",&key);
  hkey=key%TABLE_SIZE;
 hash2 = 7-(key %7);
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i*hash2)%TABLE_SIZE;
    if(h[index]==key)
    {
      printf("value is found at index %d",index);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}
void display()
{

  int i;
  float l=0;
  printf("\nelements in the hash table are \n");
  for(i=0;i< TABLE_SIZE; i++)
  {
      printf("\nat index %d \t value =  %d",i,h[i]);
      if(h[i]!= 0)
        l++;
  }
  printf("\nLoad Factor=  %f\n",(l/TABLE_SIZE));

}

void del()
{
    int key,index,i,flag=0,hkey,hash2;
    printf("\nenter a value to delete\n");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    hash2 = 7-(key %7);
    for(i=0;i<TABLE_SIZE; i++)
    {
        index=(hkey+i*hash2)%TABLE_SIZE;
        if(h[index]==key)
        {
            h[index] = 0;
            break;
        }
    }
   if(i == TABLE_SIZE)
     printf("\n value is not found\n");
}
void main()
{
    int opt,i;
    while(1)
    {
        printf("\n1. Insert\t 2. Display \t3. Search \t4. Delete \t5. Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                 del();
                 break;
            case 5:exit(0);
        }
    }
}
