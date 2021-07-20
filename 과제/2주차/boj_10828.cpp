#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMD_SIZE 20
#define STACK_SIZE 200

int stack[STACK_SIZE];
int count = 0;

void push(int a);
int pop();
int size();
int empty();
int top();

int main()
{
    int cmdNum, input, p;
    char cmd_Read[CMD_SIZE];
    char* cmd;

    scanf("%d", &cmdNum);

    for(p=cmdNum;p>=0;p--){
        fgets(cmd_Read, CMD_SIZE, stdin);
        cmd = strtok(cmd_Read, " ");    //push 14
        //input = atoi(strtok(NULL, " "));

        if(strncmp(cmd, "push", 4) == 0){
            input = atoi(strtok(NULL, "\n"));
            push(input);
            }
        else if(strncmp(cmd, "pop", 3) == 0)
            printf("%d\n", pop());
        else if(strncmp(cmd, "top", 3) == 0)
            printf("%d\n", top());
        else if(strncmp(cmd, "size", 4) == 0)
            printf("%d\n", size());
        else if(strncmp(cmd, "empty", 5) == 0)
            printf("%d\n", empty());

    }

    return 0;
}

void push(int a){
    stack[count] = a;
    count++;
}
int pop(){
    if(count>0){
    count--;
    return stack[count];
    }
    else return -1;
}
int size(){
    return count;
}
int empty(){
    if(count == 0) return 1;
    else return 0;
}
int top(){
    if(count==0) return -1;
    else return stack[count-1];
}

