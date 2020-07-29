#include <stdio.h>
/*
该文件代码用于队列的数组实现
created time:2020.07.29
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
#define N 3
int queue[N],front=-1,rear=-1,data,count,i;
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
    if(rear<N-1){
        printf("请输入要入队的数：");
        scanf("%d",&data);
        queue[++rear]=data;
        printf("数据已入队！\n");
    }else{
        printf("队列已满！\n");
    }
}
void pop(){
    if(front==rear){
        printf("队列为空！\n");
        front=-1;
        rear=-1;
    }else{
        front++;
        printf("队头元素已出队！\n");
    }
}
void print(){
    i=front+1;
    count=1;
    if(front==rear){
        printf("队列为空！\n");
        front=-1;
        rear=-1;
    }else{
        while(i<=rear){
            printf("%d-th元素的值为：%d\n",count,queue[i]);
            i++;
            count++;
        }
    }
}
void search(){
    int flag=0;
    i=front+1;
    count=1;
    if(front==rear){
        printf("队列为空！\n");
        front=-1;
        rear=-1;
    }else{
        printf("请输入要查找的数：");
        scanf("%d",&data);
        while(i<=rear){
            if(queue[i]==data){
                printf("该数据在队列的第%d个位置！\n",count);
                flag=1;
            }
            i++;
            count++;
        }
        if(flag==0){
            printf("该数据不在队列中！\n");
        }
    }
}
