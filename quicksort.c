#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
	   printf("%d ",arr[i]);
	}
	printf("\n\t");

}

void rand_partition ( int *arr , int l , int h )
{
    //chooses position of pivot randomly by using rand() function .
     int random = l + rand( )%(h-l +1 ) ;

      swap ( &arr[random] ,&arr[l]) ;
}

void median_partition(int *arr,int *f,int *s,int *t,int l)
{
	if(*t>=*s && *s>=*f || *f>=*s && *s>=*t)
	{
		swap(&arr[l],s);
	}
		if(*s>=*f && *f>=*t || *t>=*f && *f>=*s)
	{
		swap(&arr[l],f);
	}
	else
	{
		swap(&arr[l],t);
	}
}

int fst_pivot(int *arr,int l,int h)
{
	int i = l + 1;
    int piv = arr[l],j ;
    for(j =l + 1; j <=h ; j++ )  {

          if ( arr[ j ] < piv) {
                 swap (&arr[ i ],&arr[ j ]);
            i += 1;
        }
   }
   swap ( &arr[ l ] ,&arr[ i-1] ) ;
   return i-1;
}

void quicksort(int *arr,int l,int h,int choise)
{

    if(choise==1)
	{

	   if(l<h)
	  {
		int q;
        q = fst_pivot(arr, l, h);
        quicksort(arr, l, q-1,1);
        quicksort(arr, q+1, h,1);


	  }
   }
   else if(choise==2)
   {
   	    rand_partition (  arr ,  l ,  h );
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort(arr, l, q-1,1);
        quicksort(arr, q+1, h,1);
   }
   else if(choise==3)
   {
   	    int m;
   	    if((h+1)%2==0)
   	    {
   	        m=h/2;
		}
		else
		{
			m=h/2+1;
		}
   	     median_partition(arr,&arr[l],&arr[m],&arr[h], l);
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort(arr, l, q-1,1);
        quicksort(arr, q+1, h,1);
   }
   else
   {
   	    int x,y;
   	    x=(h+1)/4;
   	    y=(3*(h+1))/4;
   	    int m;
   	    if((h+1)%2==0)
   	    {
   	        m=h/2;
		}
		else
		{
			m=h/2+1;
		}
   	     median_partition(arr,&arr[x],&arr[m],&arr[y], l);
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort(arr, l, q-1,1);
        quicksort(arr, q+1, h,1);
   }

}


void main()
{
	clock_t start,end;
	float t;
	start=clock();
	int choise=0,r;
	int *arr,i,size,k,l=0,h;
	printf("Enter the value of k\n");
    scanf("%d",&k);
    size=pow(10,k);
    h=size-1;
    arr=(int *)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
        arr[i]=rand()%size;
    }
    //printf("\nBefore sorting:\n");
    //display(arr,size);
    choise=0;
	while(choise<=4)
	{

        printf("\nENTER\n1.First element as pivot\n2.Random element as pivot\n3.Median of first,middle,last elements as pivot\n4.Median of n/4th,middle,3n/4element as pivot\n5.Exit\n");
	    scanf("%d",&choise);


	    if(choise==1)
	    {
	    	quicksort(arr,l,h,1);
	    	printf("\nAfter sorting:\n");
	    	display(arr,h+1);
	    	break;

     	}
     	else if(choise==2)
     	{

     		quicksort(arr,l,h,2);
	    	printf("\nAfter sorting:\n");
	    	display(arr,h+1);
	    	break;


		 }
		 else if(choise==3)
		 {
		 	quicksort(arr,l,h,3);
	    	printf("\nAfter sorting:\n");
	    	display(arr,h+1);
	    	break;


		 }
		 else if(choise==4)
		 {
		 	quicksort(arr,l,h,4);
	    	printf("\nAfter sorting:\n");
	    	display(arr,h+1);
	    	break;



		 }
		 else
		 {
		 	break;
		 }
	}
	end=clock();
	t=(end-start)/CLOCKS_PER_SEC;
	printf("\ntime required:%f\n",t);

}
