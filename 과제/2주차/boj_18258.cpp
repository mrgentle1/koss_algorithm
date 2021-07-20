#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node *Front;
    Node *Back;
    int Size;
}Queue;

void InitQueue(Queue* x);
void push(Queue* x, int y);
int pop(Queue* x);
int IsEmpty(Queue* x);
int Front(Queue* x);
int Back(Queue* x);
int QueueSize(Queue* x);

int main()
{
    char cmd_Read[30];
    int cmd_Num, p;
    char* cmd;
    int input;

    cin >> cmd_Num;

    Queue arr;
    InitQueue(&arr);

    for(p=cmd_Num;p>=0;p--){
        fgets(cmd_Read, 30, stdin);
        cmd = strtok(cmd_Read, " ");

        if(strncmp(cmd, "push", 4) == 0){
            input = atoi(strtok(NULL, "\n"));
            push(&arr, input);
            }
        else if(strncmp(cmd, "pop", 3) == 0)
            printf("%d\n", pop(&arr));
        else if(strncmp(cmd, "front", 3) == 0)
            printf("%d\n", Front(&arr));
        else if(strncmp(cmd, "back", 3) == 0)
            printf("%d\n", Back(&arr));
        else if(strncmp(cmd, "size", 4) == 0)
            printf("%d\n", QueueSize(&arr));
        else if(strncmp(cmd, "empty", 5) == 0)
            printf("%d\n", IsEmpty(&arr));
    }


    return 0;
}

void InitQueue(Queue* x){
    x->Front = x->Back;
    x->Size = 0;
}

void push(Queue* x, int y){
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = y;
    now->next = NULL;

    if (IsEmpty(x)) x->Front = now;
    else x->Back->next = now;

    x->Back = now;
    x->Size++;
}
int pop(Queue* x){
    int re=-1;
    Node *now;
    if (IsEmpty(x)) return re;
    now = x->Front;
    re = now->data;
    x->Front = now->next;
    free(now);
    x->Size--;
    return re;
}
int IsEmpty(Queue* x){
    return x->Size == 0;
}
int Front(Queue* x){
    if(IsEmpty(x)) return -1;
    else return x->Front->data;
}
int Back(Queue* x){
    if(IsEmpty(x)) return -1;
    else return x->Back->data;
}
int QueueSize(Queue* x){
    return x->Size;
}

