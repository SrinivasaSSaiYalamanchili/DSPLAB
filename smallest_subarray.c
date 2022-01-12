#include <stdio.h>
#define sz 100

int givenarray[sz],p1=0, p2=0,sum=0,i=0,flag=0,len,minlen,minarrstart;
void smallsubarray(int arr[],int len,int num)
{
	minlen=len+1;
	while(p1<len)
	{
		while(p1<len && sum<=num)
			sum=sum+arr[p1++];
		while(p2<len && sum>num)
		{
			if((p1-p2)<minlen)
			{
				flag=1;
				minlen=p1-p2;
				minarrstart=p2;
			}
			sum=sum-arr[p2++];
		}
	}
	if(flag==0)
		{
			printf("No such subarray exists");
		}
	else
	{
		if(minlen==1)
			printf("{ %d }",arr[minarrstart]);
		else
		{
			printf("{%d",arr[minarrstart]);
			for(i=(minarrstart+1);i<(minarrstart+minlen);i++)
				printf(",%d",(arr[i]));
			printf("}\n");
			printf("The Output is:\n");
			printf("{");
			for(i=(minarrstart);i<(minarrstart+minlen);i++)
				printf("%d,",(arr[i]+minlen));
            printf("}");

		}
	}


}

void main()
{
	int size,n;
	printf("Enter the size of array \n");
	scanf("%d",&size);
	int inputarr[size];
	printf("Enter the array \n");
	for(i=0;i<size;i++)
		scanf("%d",&inputarr[i]);
	printf("Enter the value of n: \n");
	scanf("%d",&n);
	printf("The smallest subarray is: ");
	smallsubarray(inputarr,size,n);
}
