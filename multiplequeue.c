#include<stdio.h>
#include<stdlib.h>
#define MAX 60
int queue[MAX],ele,a=0,b=0,c=0,d=0;
int rear[10], front[10], f[10], r[10];
int maxi(int x, int y)
{
        return (x > y) ? x : y;
}
int min(int x, int y)
{
        return(x < y) ? x : y;
}
int insq( int qno, int rear[], int front[], int *ele)
{
      if( rear[qno] == front[qno] )
            return(-1);
      else
      {
            rear[qno]++;
            queue[ rear[qno] ] = *ele;
      }
      if(qno==0)
        a++;
      else if(qno==1)
        b++;
      else if(qno==2)
        c++;
      else
        d++;
}
int delq(int qno, int front[], int rear[], int *ele)
{
      if( front[qno] == rear[qno] )
            return(-1);
      else
      {
            front[qno]++;
            *ele = queue[ front[qno] ];
      }
      if(qno==0)
        a--;
      else if(qno==1)
        b--;
      else if(qno==2)
        c--;
      else
        d--;
}

void display(int qno, int front[MAX], int rear[MAX])
{
    int i;
    if( front[qno] == rear[qno] )
            printf("Queue is empty\n");
    for (i = (front[qno]+1); i <=rear[qno]; i++)
    {
        printf("%d\t ", queue[i]);
    }
    printf("%d\t ", a);
    printf("%d\t ", b);
    printf("%d\t ", c);
    printf("%d\t ", d);
    printf("\n");

}
int main()
{
      n=4;
      size = MAX / n;
      rear[0] = -1;
      for(i = 1; i < n; i++)
            rear[i] = rear[i-1] + size;
      for(i = 0; i < n; i++)
      {
            front[i] = rear[i] + size;
      }
      for(i = 0; i < n; i++)
            f[i] = r[i] = rear[i];
      printf("first enter 5 elem in q0:");
      for(i = 0; i < 5; i++)
      {
          printf(" Enter element to be entered in queue number 0 : ");
          scanf("%d", &ele);
          reply = insq(0, r, front, &ele);
      }
      printf("first enter 3 elem in q1:");
      for(i = 0; i < 3; i++)
      {
          printf(" Enter element to be entered in queue number 1 : ");
          scanf("%d", &ele);
          reply = insq(1, r, front, &ele);
      }
      printf("first enter 2 elem in q2:");
      for(i = 0; i < 2; i++)
      {
          printf(" Enter element to be entered in queue number 2 : ");
          scanf("%d", &ele);
          reply = insq(2, r, front, &ele);
      }
      printf("first enter 6 elem in q3:");
      for(i = 0; i < 6; i++)
      {
          printf(" Enter element to be entered in queue number 3 : ");
          scanf("%d", &ele);
          reply = insq(3, r, front, &ele);
      }

      printf("\tMenu");
      printf("\n 1. Insertion");
      printf("\n 2. Delete");
      printf("\n 3. Display");
      printf("\n 4. Exit \n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            switch(ch)
            {
                  case 1 : //Insert
                         p = min(a, min(b, min(c, d)));
                        //p=min(a,b);
                        if(p==a)
                            qno=0;
                        else if(p==b)
                            qno=1;
                        else if(p==c)
                             qno=2;
                        else
                             qno=3;
                        printf(" Enter element to be entered in queue number %d : ",qno);
                        scanf("%d", &ele);
                        reply = insq( qno, r, front, &ele);
                        if( reply == -1)
                              printf("Queue %d is full \n", qno);
                        else
                              printf("%d is inserted in queue number %d.\n\n", ele, qno);
                        break;
                  case 2 : //Delete
                        g=maxi(a, maxi(b, maxi(c, d)));
                        if(g==a)
                            qno=0;
                        else if(g==b)
                            qno=1;
                        else if(g==c)
                             qno=2;
                        else
                             qno=3;
                        reply = delq(qno, f, r, &ele);
                        if( reply == -1)
                              printf("\n Queue %d is empty. \n", qno);
                        else
                              printf("%d is deleted from queue number %d \n\n",ele, qno);
                        break;
                  case 3 :
                        printf("\nEnter Queue number (0 to %d) : ", n-1);
                        scanf("%d", &qno);
                        display(qno, f, r);
                        break;
                  case 4 :
                        exit(0);
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}
