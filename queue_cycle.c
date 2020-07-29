#include <stdio.h>
/*
@Description：该文件代码用于循环队列的实现
@Created date：2020.07.29
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
#define N 5
int queue[N],front=-1,rear=-1,data,count;
void main(){
    int choice;
    choice=888;
    while(choice!=0){
        printf("+--循环队列操作系统--+\t\t\n");
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
    if((rear+1)%N==front){
        printf("队列已满！\n");
    }else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        printf("请输入要入队的数：");
        scanf("%d",&data);
        queue[rear]=data;
        printf("数据已入队！\n");
    }else if(rear==N-1&&front!=0){
        rear=0;
        printf("请输入要入队的数：");
        scanf("%d",&data);
        queue[rear]=data;
        printf("数据已入队！\n");
    }else{
        rear++;
        printf("请输入要入队的数：");
        scanf("%d",&data);
        queue[rear]=data;
        printf("数据已入队！\n");
    }
}
void pop(){
    if(front==-1){
        printf("队列为空！\n");
    }else{
        if(front==rear){
            front=-1;
            rear=-1;
            printf("队头元素已出队！\n");
        }else if(front==N-1){
            front=0;
            printf("队头元素已出队！\n");
        }else{
            front++;
            printf("队头元素已出队！\n");
        }
    }
}
void print(){
    int i;
    if(front==-1){
        printf("队列为空！\n");
    }else{
        if(front<=rear){
            count=1;
            i=front;
            while(i<=rear){
                printf("%d-th个元素的值：%d\n",count,queue[i++]);
                count++;
            }
        }else{
            count=1;
            i=front+1;
            while(i<=N-1){
                printf("%d-th个元素的值：%d\n",count,queue[i++]);
                count++;
            }
            i=0;
            while(i<=rear){
                printf("%d-th个元素的值：%d\n",count,queue[i++]);
                count++;
            }
        }
    }
}
void search(){
    int i,flag=0;
    if(front==-1){
        printf("队列为空！\n");
    }else{
        printf("请输入要查找的数：");
        scanf("%d",&data);
        if(front<=rear){
            count=1;
            i=front;
            while(i<=rear){
                if(queue[i++]==data){
                    printf("该数据距队头的位置为：%d\n",count-1);
                    flag=1;
                }
                count++;
            }
        }else{
            count=1;
            i=front+1;
            while(i<=N-1){
                if(queue[i++]==data){
                    printf("该数据距队头的位置为：%d\n",count-1);
                    flag=1;
                }
                count++;
            }
            i=0;
            while(i<=rear){
                if(queue[i++]==data){
                    printf("该数据距队头的位置为：%d\n",count-1);
                    flag=1;
                }
                count++;
            }
        }
    }
    if(!flag){
        printf("该数据不在队列中！\n");
    }
}
