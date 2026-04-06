#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10001

char stack[Max]; // stack to store brackets
int top=-1; // points to current top of stack

void push(char no)
{
    if(top==Max-1) // check overflow
    {
        printf("Overflow");
    }
    else
    {
        top++; // move top
        stack[top]=no; // push element
    }
}

char pop()
{
    if(top==-1) // check underflow
    {
        printf("Underflow");
        return '\0';
    }
    else
    {
        char val = stack[top]; // get top element
        top--; // remove it
        return val;
    }
}


int ismatching(char no1, char no2)
{
    if(no1=='{' && no2=='}')
    {
        return 1;
    }
    else if(no1=='(' && no2==')')
    {
        return 1;
    }
    else if(no1=='[' && no2==']')
    {
        return 1;
    }
    else if(no1=='<' && no2=='>')
    {
        return 1;
    }
    else
    {
        return 0; // not matching
    }
}

int main()
{
    int flag=0; // tracks if expression becomes invalid
    char exp[1001]; // stores input expression
    printf("Enter the expression :");
    fgets(exp, sizeof(exp), stdin);

    for(int i=0;i<strlen(exp);i++) 
    {
        // push all opening brackets
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(' || exp[i]=='<')
        {
            push(exp[i]);
        }
        // for closing bracket, check match with stack top
        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')' || exp[i]=='>')
        {
            if(ismatching(pop(),exp[i]))
            {
                flag=0; // still valid so far
            }
            else
            {
                flag=1; // mismatch found
            }
        }
        else
        {
            flag=0; // ignore other characters
        }
    }

    if(flag==0)
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Invalid Expression");
    }
    return 0;
}