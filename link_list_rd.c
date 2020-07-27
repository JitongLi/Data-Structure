#include <stdio.h>
/*
该文件代码用于实现循环双链表
created time:2020.07.27
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    struct Node *pre;
    int data;
    struct Node *next;
}node;
node *head,*ptr;
void main(){
    int choice=888;
    while(choice!=0){
        printf("+-循环双链表操作系统-+\t\t\n");
        printf("|\t1.插入\t     |\n");
        printf("|\t2.删除\t     |\n");
        printf("|\t3.查找\t     |\n");
        printf("|\t4.展示\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请出入您的选择：\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insert_link();
            break;
        case 2:
            delete_link();
            break;
        case 3:
            search_link();
            break;
        case 4:
            print_link(head);
            break;
        case 0:
            break;
        default:
            printf("输入有误！\n");
            break;
        }
    }
}
void insert_link(){
    int choice,data,loc,i;
    printf("请输入您要插入的位置（1:头结点2:指定位置-1:尾结点）:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://头结点插入
        ptr=(node *)malloc(sizeof(node));
        printf("请输入您要插入的数据：");
        scanf("%d",&data);
        ptr->data=data;
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->pre=temp;
            head->pre=ptr;
            ptr->next=head;
            head=ptr;
            printf("结点已插入！\n");
        }else{
            head=ptr;
            ptr->pre=head;
            ptr->next=head;
            printf("链表为空，结点已插入！\n");
        }
        break;
    case 2://指定位置插入
        ptr=(node *)malloc(sizeof(node));
        node *temp=head;
        if(head){
            printf("请输入您要插入的位置：");
            scanf("%d",&loc);
            for(i=0;i<loc-1;i++){
                if(temp->next!=head){
                    temp=temp->next;
                }else{
                printf("位置不存在，可能是位置长度大于链表长度导致的！\n");
                return;
                }
            }
            printf("请输入您要插入的数据：");
            scanf("%d",&data);
            ptr->data=data;
            ptr->pre=temp;
            ptr->next=temp->next;
            temp->next->pre=ptr;
            temp->next=ptr;
            printf("结点已插入！\n");
        }else{
            printf("链表为空，暂时不能进行该项操作！\n");
        }
        break;
    case -1://尾结点插入
        ptr=(node *)malloc(sizeof(node));
        printf("请输入您要插入的数据：");
        scanf("%d",&data);
        ptr->data=data;
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            ptr->pre=temp;
            head->pre=ptr;
            temp->next=ptr;
            ptr->next=head;
            printf("结点已插入！\n");
        }else{
            head=ptr;
            ptr->pre=head;
            ptr->next=head;
            printf("链表为空，结点已插入！\n");
        }
        break;
    default:
        printf("输入有误！\n");
        break;
    }
}
void delete_link(){
    int choice,loc,i;
    printf("请输入您要删除数据的位置(1:头结点2:指定位置-1:尾结点):");
    scanf("%d",&choice);
    switch(choice){
    case 1://头结点删除
        if(head){
            if(head->next==head){
                head=NULL;
                free(head);
                printf("结点删除成功！\n");
            }else{
                node *temp=head;
                while(temp->next!=head){
                    temp=temp->next;
                }
                ptr=head;
                temp->next=head->next;
                head->next->pre=temp;
                head=head->next;
                free(ptr);
                printf("结点删除成功！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case 2://指定位置删除
        if(head){
            printf("请输入位置：");
            scanf("%d",&loc);
            ptr=head;
            for(i=0;i<loc-1;i++){
                if(ptr->next!=head){
                    ptr=ptr->next;
                }else{
                    printf("该位置不存在，可能是输入位置大于链表长度导致的！\n");
                    return;
                }
            }
            if(head->next==head){
                head=NULL;
                free(head);
                printf("只有一个结点，已经删除！\n");
            }else{
                ptr->pre->next=ptr->next;
                ptr->next->pre=ptr->pre;
                free(ptr);
                printf("结点删除成功！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case -1://尾结点删除
        if(head){
            if(head->next==head){
                head=NULL;
                free(head);
                printf("结点删除成功！\n");
            }else{
                ptr=head;
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->pre->next=head;
                head->pre=ptr->pre;
                free(ptr);
                printf("结点删除成功！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    default:
        printf("输入有误！\n");
        break;
    }
}
void search_link(){
    int data,count=1,flag=0;
    printf("请输入您要查找的数据：");
    scanf("%d",&data);
    ptr=head;
    while(ptr->next!=head){
        if(ptr->data==data){
            printf("该数据在链表的第%d个位置上！\n",count);
            flag=1;
        }
        ptr=ptr->next;
        count++;
    }
    if(ptr->data==data){
        printf("该数据在链表的第%d个位置上！\n",count);
        flag=1;
    }
    if(!flag){
        printf("该数据不在链表里！\n");
    }
}
void print_link(node *head){
    int count=1;
    ptr=head;
    if(head){
        while(ptr->next!=head){
            printf("%d-th个结点的值为：%d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
        printf("%d-th个结点的值为：%d\n",count,ptr->data);
    }else{
        printf("链表为空！\n");
    }
}
