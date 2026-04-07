// ALGORITHM
// - Read the input string.
// - Push all characters of the string into the stack.
// - Pop characters one by one from the stack.
// - Store popped characters in a new string (reverse).
// - Print the reversed string.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 101              // max size of stack

char stack[Max];            // stack to store characters
int top=-1;                 // stack starts empty

// push all characters of string into the stack
void push(char *ptr)
{
    if(top==Max-1)           // stack is full
    {
        return;
    }
    else
    {
        for(int i=0;*(ptr+i)!='\0';i++)
        {
            top++;            
            stack[top]=*(ptr+i);  // push each character
        }
    }
}

// pop one character from stack
char pop()
{
    if(top==-1)              // stack empty
    {
        return '\0';
    }
    else
    {
        char value=stack[top];  // get top character
        top--;                  
        return value;           
    }
}

int main()
{
    char string[101];        
    printf("Enter the string:");
    fgets(string, sizeof(string), stdin);  

    string[strcspn(string, "\n")] = '\0';  // remove newline

    char reverse[101];       

    char *ptr=string;
    push(ptr);               // push full string into stack
    
    for(int i=0;i<strlen(string);i++)

        
    {
        reverse[i]=pop();    // pop to get reversed order
    }

    reverse[strlen(string)]='\0';  // end of string

    printf("The reversered string of %s is %s",string,reverse);
    return 0;
}

// Input:
// Enter the string: hello

// Output:
// The reversered string of hello is olleh
