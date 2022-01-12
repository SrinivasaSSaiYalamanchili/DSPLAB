#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '@')
        return 0;
    if(x == ')')
        return 1;
    if(x == '(')
        return 2;
    if(x == '+' || x == '-')
        return 3;
    if(x == '*' || x == '/')
        return 4;
    return 0;
}

int precedence(char elem)
{
    switch(elem)
    {
        case'@':return 0;
        case')':return 1;
        case'+':
        case'-':return 2;
        case'*':
        case'/':return 3;
    }
}

void strrev(char *w)
{
	int i=0;
	while(w[i]!='\0')
	{
		push(w[i]);
		i++;
	}
	int j=0;
	while(w[j]!='\0')
	{
		w[j]=pop();
		j++;
	}
}

int main()
{
    char exp[100],prefix[100],ch,elem;
    char *e, x;
    int i=0,l=0;
	int k=0,arr;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    arr=strlen(exp);
    //printf("%d\n",arr);
    for(i=0;i<arr;i=i+2)
    {
        if(exp[i]<97&&exp[i]>122)
        {
            printf("Invalid Expression\n");
            exit(0);
        }

    }
    for(i=1;i<arr;i=i+2)
    {
        if(exp[i]!='+'&&exp[i]!='-'&&exp[i]!='*'&&exp[i]!='/')
        {
            printf("Invalid Expression\n");
            exit(0);
        }
    }
    printf("Valid Expression\n");
    e = exp;
    push('@');
	strrev(exp);
    while ((ch=exp[l])!='\0')
    {
        if (ch==')')
        {
            push(ch);
        }
        else if (ch=='(')
        {
            while(stack[top]!=')')
                prefix[k++]=pop();
            elem=pop();
        }
        else
        {
            if(precedence(stack[top])<=precedence(ch))
            {
                push(ch);
            }
            else
            {
                while(precedence(stack[top])>precedence(ch))
                prefix[k++]=pop();
                push(ch);
            }
        }
        l++;
    }
    while(stack[top]!='@')
        prefix[k++]=pop();
    prefix[k]='\0';
    strrev(prefix);
    strrev(exp);
    printf("Given Infix expression:\t%s\nConverted Prefix expression:\t%s\n",exp,prefix);
	pop();

    printf("Converted Postfix expression Is :\t");
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c ",pop());
    }

    return 0;
}
