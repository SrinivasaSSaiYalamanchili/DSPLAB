#include <stdio.h>
#include <string.h>
struct student {
    char fName[50];
    float marks;
}stud;
struct student stu[10];
int p,n=0;

void insert()
{

        printf("Enter information of student:\n");
        // storing information
        printf("Enter first name: ");
        scanf("%s", stu[n].fName);
        printf("Enter marks: ");
        scanf("%f", &stu[n].marks);
        if(n== 0)
            p=stu[n].marks;
        else
        {
            if(stu[n].marks>p)
                p=stu[n].marks;
        }
        n++;
    display(n);
}

void display()
{
    int i;
    printf("Displaying Information:\n\n");
    // displaying information
    for (i = 0; i < n; ++i) {
        puts(stu[i].fName);
        printf("Marks: %.1f", stu[i].marks);
        printf("\n");
    }
    printf("Priority :%d\n",p);
}

void delete()
{
    int i,j,del,found;
    for(i=0; i<n; i++)
    {
        if(stu[i].marks==p)
        {
            for(j=i; j<(n-1); j++)
            {
                stu[j].marks = stu[j+1].marks;
                strcpy(stu[j].fName,stu[j+1].fName);
            }
            found=1;
            i--;
            n--;
        }
    }
    if(found==0)
        printf("\nElement does not found in the list!");
    else
        printf("\nElement Deleted Successfully!");
    for (i = 0; i < n; ++i) {
            if(i== 0)
            p=stu[i].marks;
        else
        {
            if(stu[i].marks>p)
                p=stu[i].marks;
        }
    }
    display(n);
}

int main() {
    int op;
    while(1)
    {
        printf("1.Insert\t2.Delete\t3.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1: insert();
                break;
        case 2: delete(n);
                break;
        case 3: exit(0);
        default: printf("wrong");
        }
    }
    return 0;
}
