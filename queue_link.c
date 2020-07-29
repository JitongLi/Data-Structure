#include <stdio.h>
/*
该文件代码用于队列的链表实现
created time:2020.07.29
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
int data,count,flag;
node *ptr,*front,*rear;
void main(){
    int choice;
    choice=888;
    while(choice!=0){
        printf("+----队列操作系统----+\t\t\n");
        printf("|\t1.入队\t     |\n");
        printf("|\t2.出队\t     |\n");
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
    ptr=(node *)malloc(sizeof(node));
    printf("请输入要入队的数：");
    scanf("%d",&data);
    ptr->data=data;
    if(front==NULL&&rear==NULL){
        rear=ptr;
        ptr->next=NULL;
        front=rear;
        printf("队列为空，数据已入队！\n");
    }else{
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
        printf("数据已入队！\n");
    }
}
void pop(){
    if(front){
        if(front->next){
            ptr=front;
            front=front->next;
            free(ptr);
            printf("队头元素已出队！\n");
        }
        else{
            ptr=front;
            front=NULL;
            rear=NULL;
            free(ptr);
            printf("队头元素已出队，队列已空！\n");
        }
    }else{
        printf("队列为空！\n");
    }
}
void print(){
    count=1;
    if(front){
        ptr=front;
        while(ptr->next){
            printf("%d-th个结点的值：%d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
        printf("%d-th个结点的值：%d\n",count,ptr->data);
    }else{
        printf("队列为空！\n");
    }
}
void search(){
    count=1,flag=0;
    if(front){
        printf("请输入要查找的数：");
        scanf("%d",&data);
        ptr=front;
        while(ptr->next){
            if(ptr->data==data){
                printf("该数据距队头的距离为：%d\n",count);
                flag=1;
            }
            ptr=ptr->next;
            count++;
        }
        if(ptr->data==data){
            printf("该数据距队头的距离为：%d\n",count-1);
            flag=1;
        }
        if(!flag){
            printf("该数据不在队列中！\n");
        }
    }else{
        printf("队列为空！\n");
    }
}
