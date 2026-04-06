#include<stdio.h>
#include<stdlib.h>
#define Max 101         
int top=-1;              
int stack[Max];          

void push(int value)
{
    if(top==Max-1)      // check if stack is full
    {
        return;
    }
    else
    {
        top++;            // move top
        stack[top]=value; // insert value
    }
}

int pop()
{
    if(top==-1)          // check if stack is empty
    {
        return -2;       // return special value
    }
    else
    {
        int value=stack[top]; // get top element
        top--;                // remove it
        return value;         
    }
}

void nextGreater(int array[], int n)
{
    int result[Max];         // stores next greater elements
    int indexStack[Max];     // stack to store indices
    int top2=-1;             
    
    for (int i=0;i<n;i++)
    {
        // find next greater for previous elements
        while (top2!=-1 && array[indexStack[top2]]<array[i])
        {
            result[indexStack[top2]]=array[i];  
            top2--;                              
        }
        indexStack[++top2]=i;   // push current index
    }
    
    // remaining elements have no greater element
    while (top2!=-1)
    {
        result[indexStack[top2]]=-1;  
        top2--;
    }
    
    // print result
    for (int i=0;i<n;i++)
    {
        printf("%d->%d\n",array[i],result[i]);
    }
}

int main()
{
    int array[101];          
    int len;                 
    
    printf("Enter the no.of values in the array:");
    scanf("%d",&len);

    for(int i=0;i<len;i++)
    {
        printf("Enter the value for %d th value:",i);
        scanf("%d",&array[i]);
    }

    nextGreater(array,len); // call function
    return 0;
}