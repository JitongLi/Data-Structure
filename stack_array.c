#include <stdio.h>
/*
该文件代码用于堆栈的数组实现
created time:2020.07.27
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
#define N 100 //堆栈的大小
int stack[N],top=-1;
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
    if(top==N){
        printf("栈已满！\n");
    }else{
        printf("请输入要入栈的数：");
        scanf("%d",&data);
        stack[++top]=data;
        printf("数据已入栈！\n");
    }
}
void pop(){
    if(top==-1){
        printf("栈为空！\n");
    }else{
        top--;
        printf("顶端元素已出栈！\n");
    }
}
void search(){
    int data,temp=top,count=1,flag=0;
    if(top==-1){
        printf("栈为空！\n");
    }else{
        printf("请输入您要查找的数据：");
        scanf("%d",&data);
        while(temp>-1){
            if(stack[temp]==data){
                printf("该数据距栈顶的位置为：%d\n",count);
                flag=1;
            }
            count++;
            temp--;
        }
        if(stack[temp]==data){
            printf("该数据距栈顶的位置为%d\n",count);
            flag=1;
        }
        if(flag==0){
            printf("该数据不在堆栈中！\n");
        }
    }
}
void print(){
    int count=1,temp=top;
    if(top==-1){
        printf("栈为空！\n");
    }else{
        while(temp>-1){
            printf("%d-th个元素：%d\n",count,stack[temp]);
            temp--;
            count++;
        }
    }

}
