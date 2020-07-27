#include <stdio.h>
/*
该文件代码用于堆栈的链表实现
created time:2020.07.28
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *ptr,*head;
void main(){
    int choice;
    choice=888;
    while(choice!=0){
        printf("+----堆栈操作系统----+\t\t\n");
        printf("|\t1.入栈\t     |\n");
        printf("|\t2.出栈\t     |\n");
        printf("|\t3.查找\t     |\n");
        printf("|\t4.展示\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请出入您的选择：\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            search();
            break;
        case 4:
            print();
            break;
        case 0:
            exit(0);
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
}
void push(){
    int data;
    printf("请输入要入栈的数：");
    scanf("%d",&data);
    ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    if(head){
        ptr->next=head;
        head=ptr;
        printf("入栈成功！\n");
    }else{
        head=ptr;
        ptr->next=NULL;
        printf("栈为空，入栈成功！\n");
    }
}
void pop(){
    if(head){
        ptr=head;
        head=head->next;
        free(ptr);
        printf("出栈成功！\n");
    }else{
        printf("栈为空！\n");
    }
}
void print(){
    int count=1;
    if(head){
        ptr=head;
        while(ptr->next!=NULL){
            printf("%d-th个元素的值：%d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
        printf("%d-th个元素的值：%d\n",count,ptr->data);
    }else{
        printf("栈为空！\n");
    }
}
void search(){
    int data,count=1,flag=0;
    printf("请输入查找的数：");
    scanf("%d",&data);
    if(head){
        ptr=head;
        while(ptr->next){
            if(ptr->data==data){
                printf("该数据在距离栈顶的第%d个位置上！\n",count-1);
                flag=1;
            }
            ptr=ptr->next;
            count++;
        }
        if(ptr->data==data){
            printf("该数据在距离栈顶的第%d个位置上！\n",count-1);
            flag=1;
        }
        if(!flag){
            printf("该数据不在栈中！\n");
        }
    }else{
        printf("栈为空！\n");
    }
}
