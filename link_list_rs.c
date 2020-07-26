#include <stdio.h>
/*
该文件代码用于实现循环单链表
created time:2020.07.26
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *ptr,*head;
void main(){
    int choice=888;
//    init_link();//初始化链表
    while(choice!=0){
        printf("+-循环单链表操作系统-+\t\t\n");
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
void init_link(){
    ptr=(node *)malloc(sizeof(node));
    ptr->data=1;
    head=ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=2;
    head->next=ptr;
    ptr->next=head;
}
void insert_link(){
    int choice,data,loc,i;
    printf("请输入您要插入的位置(1:头节点2:指定位置-1:尾节点)\n");
    scanf("%d",&choice);
    ptr=(node *)malloc(sizeof(node));
    switch(choice){
    case 1://从头节点插入
        printf("请输入插入数据：");
        scanf("%d",&data);
        ptr->data=data;
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            ptr->next=head;
            temp->next=ptr;
            head=ptr;
            printf("节点插入成功！\n");
        }else{
            head=ptr;
            ptr->next=head;
            printf("节点插入成功！\n");
        }
        break;
    case 2://指定位置插入
        printf("请输入插入位置：");
        scanf("%d",&loc);
        node *temp=head;
        if(head){
            for(i=0;i<loc-1;i++){
                if(temp->next!=head){
                    temp=temp->next;
                }else{
                    printf("\n该位置不存在，可能是输入位置大于链表长度导致的！\n");
                    return;
                }
            }
            printf("请输入插入数据：");
            scanf("%d",&data);
            ptr->data=data;
            ptr->next=temp->next;
            temp->next=ptr;
            printf("节点插入成功！\n");
        }else{
            printf("链表为空，该位置不存在！\n");
        }
        break;
    case -1://尾节点插入
        printf("请输入插入数据：");
        scanf("%d",&data);
        ptr->data=data;
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
            printf("节点插入成功！\n");
        }else{
            head=ptr;
            ptr->next=head;
            printf("节点插入成功！\n");
        }
        break;
    default:
        printf("输入有误！");
        break;
    }
}
void delete_link(){
    int choice,loc,i;
    printf("请输入您要删除数据的位置(1:头节点2:指定位置-1:尾节点)\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://头节点删除
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            if(temp==head){
                ptr=head;
                head=NULL;
                free(ptr);
                printf("节点删除成功！\n");
            }else{
                ptr=head;
                temp->next=head->next;
                head=head->next;
                free(ptr);
                printf("节点删除成功！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case 2://指定位置删除
        printf("请输入要删除数据的位置：\n");
        scanf("%d",&loc);
        if(head){
            node *temp=head;
            for(i=0;i<loc;i++){
                if(temp->next!=head){
                    ptr=temp;
                    temp=temp->next;
                }else{
                    printf("该位置不存在，可能是由于输入位置大于链表长度导致的！\n");
                    return;
                }
            }
            if(temp==head){
                ptr=head;
                head=NULL;
                free(ptr);
                printf("节点删除成功！\n");
            }else{
                ptr->next=temp->next;
                free(temp);
                printf("节点删除成功！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case -1://尾节点删除
        if(head){
            node *temp;
            ptr=head;
            while(ptr->next!=head){
                temp=ptr;
                ptr=ptr->next;
            }
            if(ptr==head){
                head=NULL;
                free(ptr);
                printf("节点删除成功！\n");
            }else{
                temp->next=head;
                free(ptr);
                printf("节点删除成功！\n");
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
void print_link(node *head){
    int count=1;
    node *ptr=head;
    if(head){
       while(ptr->next!=head){
            printf("%d-th个节点的值：%d\n",count,ptr->data);
            ptr=ptr->next;
        }
        printf("%d-th个节点的值：%d\n",count,ptr->data);
    }else{
        printf("链表为空！\n");
    }
}
void search_link(){
    int data,count=1,flag=0;
    if(!head){
        printf("链表为空！\n");
    }else{
        ptr=head;
        printf("请输入您要查找的数据：");
        scanf("%d",&data);
        while(ptr->next!=head){
            if(ptr->data==data){
                printf("该数据在链表中的第%d个位置！\n",count);
                flag=1;
                return;
            }else{
            }
            ptr=ptr->next;
            count++;
        }
        if(ptr->data==data){
            printf("该数据在链表中的第%d个位置！\n",count);
            flag=1;
        }
        if(!flag){
            printf("该数据不在链表中！\n");
        }
    }
}
