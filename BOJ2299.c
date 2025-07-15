#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. 숫자면 스택에 저장
2. 연산자면 숫자 두개 pop 해서 왼 오 연결하기 
*/

int top=-1;

typedef struct node 
{
    char value;
    struct node *left;
    struct node *right;
}Node;

Node *makenode(char value)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->value=value;
    newnode->right=NULL;
    newnode->left=NULL;

    return newnode;
}

void push(Node *stack[],Node *newnode)
{
    top+=1;
    stack[top]=newnode;
}

Node *pop(Node *stack[])
{
    Node *result=stack[top];
    stack[top]=NULL;
    top-=1;

    return result;
}

void SetStack(Node *stack[],char exp[])
{
    int len=strlen(exp);
    Node *left=NULL;
    Node *right=NULL;
    Node *newnode=NULL;

    for(int i=len-1; i>=0; i--)
    {
        newnode=makenode(exp[i]);

        if (isdigit(exp[i])==0) //숫자가 아닐 때 
        {
            right=pop(stack);

            if (top!=-1)
                left=pop(stack);

            newnode->left=left;
            newnode->right=right;

        }

        push(stack,newnode);
    }

    while (top>0)
    {
        right=pop(stack);
        left=pop(stack);

        if (right->left==NULL)
        {
            right->left=left;
            push(stack,right);
        }
        else 
        {
           left->right=right;
           push(stack,left);
        }

        //push(stack,right);
    }

}

//전위 순회 = 루트, 왼, 오
void preorder(Node *tree)
{
    if (tree!=NULL)
    {
        printf("[%c] -> ",tree->value);
        preorder(tree->left);
        preorder(tree->right);

    }
}

//중위 순회
void inorder(Node *tree)
{
    if (tree!=NULL)
    {
        inorder(tree->left);
        printf("[%c] -> ",tree->value);
        inorder(tree->right);
    }
}

//후위 순회 
void postorder(Node *tree)
{
    if (tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("[%c] ", tree->value);
    }
}

int main(void)
{
    Node *stack[101];
    Node *tree=NULL;
    char exp[101]={'\0'};

    for(int i=0; i<101; i++)
    {
        stack[i]=NULL;
    }

    scanf("%s", exp);

    SetStack(stack,exp);
    tree=stack[0];

    printf("전위 순회\n");
    preorder(tree);

    printf("\n 중위 순회\n");
    inorder(tree);

    printf("\n 후위 순회\n");
    postorder(tree);

    return 0;
}