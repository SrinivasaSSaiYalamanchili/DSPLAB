#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void display(int *arr,int size)
{
	int i;
	printf("\nrequired list:\n");
	for(i=0;i<size;i++)
	{
	   printf("%d ",arr[i]);
	}
	printf("\n\t");

}

void merge(int *arr,int l,int m,int e)
{
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=e-m;
	int Left[n1],right[n2];
	k = 0;
	for(i=l;i<=m;i++)
	{
		Left[k++]=arr[i];
	}
	k=0;
	for(j=m+1;j<=e;j++)
	{

		right[k++]=arr[j];
	}
	i=0,j=0;
    for(k=l;k<=e;k++)
	{
		if(Left[i]<=right[j])
		{
			arr[k]=Left[i];
			i++;

			if(i == n1) {
				while (j < n2) {
        			arr[++k] = right[j];
        			j++;

    			}
				break;
			}

		}
		else
		{
		    arr[k]=right[j];
			j++;

			if(j == n2) {
				while (i < n1) {
        			arr[++k] = Left[i];
        			i++;

    			}
				break;
			}

		}


}
}

void mergesort(int *arr,int l,int e)
{
	int m;
	if(l>=e) return;
		m=(l+e)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,e);
        merge(arr,l,m,e);
}

void main()
{
            clock_t start,end;
            float t;
            int *arr,i,size,k,a=0,b;
            start=clock();
            printf("Enter the limt value k\n");
	    	scanf("%d",&k);
	    	size=pow(10,k);
	    	b=size-1;
	    	arr=(int *)malloc(size*sizeof(int));
	    	for(i=0;i<size;i++)
	    	{
	    		arr[i]=rand()%size;
			}
			//printf("\nBefore sorting\n");
			//display(arr,size);
			mergesort(arr,a,b);
			printf("\nAfter sorting\n");
			display(arr,size);
			 free(arr);
			 end=clock();
            t=(end-start)/CLOCKS_PER_SEC;
            printf("\nTime Required:%f\n",t);
}
