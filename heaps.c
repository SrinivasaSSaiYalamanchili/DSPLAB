#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void minheapify(int array[], int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&array[i], &array[smallest]);
      minheapify(array, size, smallest);
    }
}

void heapify(int array[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
}

void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      minheapify(array, size, i);
    }
  }
}

void insertmax(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}

void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
    {
        swap(&array[i], &array[size - 1]);
        size -= 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            minheapify(array, size, i);
        }

        return;
    }
  }
  printf("Elem Not Present\n");
}

void deleteRootmax(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
    {
        swap(&array[i], &array[size - 1]);
        size -= 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
        return;
    }
  }
  printf("Elem Not Present\n");
}

void heapSort(int arr[], int n) {
    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
      minheapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // minheapify root element to get lowest element at root again
      minheapify(arr, i, 0);
    }
}

void heapSortmax(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}

int main()
{
  int array[100],a[100],no,i,del,ch,elem,op;
  while(1)
  {
	printf("1.Minheap\t 2.Maxheap\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
        while(1)
        {
            printf("1.Build\t 2.Insert\t 3.Delete\t 4.Sort\t 5.Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {

                case 1: printf("Enter NO Of Elem ");
                        scanf("%d",&no);
                        printf("Enter Elems ");
                        for(i=0;i<no;i++)
                        {
                            scanf("%d",&a[i]);
                            insert(array, a[i]);
                        }
                        printf("Min-Heap : ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 2: printf("Enter Elem ");
                        scanf("%d",&elem);
                        insert(array, elem);
                        printf("Min-Heap : ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 3 : printf("Enter Elem to del\n ");
                         scanf("%d",&del);
                         deleteRoot(array, del);

                         printf("After deleting an element: ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 4: heapSort(array, size);
                        printf("Sorted array is \n");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 5: exit(0);
                default: printf("Invalid");
            }
        }
		case 2:
        while(1)
        {
            printf("1.Build\t 2.Insert\t 3.Delete\t 4.Sort\t 5.Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {

                case 1: printf("Enter NO Of Elem ");
                        scanf("%d",&no);
                        printf("Enter Elems ");
                        for(i=0;i<no;i++)
                        {
                            scanf("%d",&a[i]);
                            insertmax(array, a[i]);
                        }
                        printf("Max-Heap : ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 2: printf("Enter Elem ");
                        scanf("%d",&elem);
                        insertmax(array, elem);
                        printf("Max-Heap : ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 3: printf("Enter Elem to del\n ");
                        scanf("%d",&del);
                        deleteRootmax(array, del);
                        printf("After deleting an element: ");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 4: heapSortmax(array, size);
                        printf("Sorted array is \n");
                        for (int i = 0; i < size; ++i)
                            printf("%d ", array[i]);
                        printf("\n");
                        break;
                case 5: exit(0);
                default: printf("Invalid");
            }
        }
		default : printf("Invalid");
        }
    }
}
