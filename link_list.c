#include <stdio.h>
/*
created time:2020.07.24
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head, *ptr;
void main(){
    init();
    int choice=8,num;
    while(choice!=0){
        printf("+----链表操作系统----+\t\t\n");
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
            insert_link();//插入操作
            break;
        case 2:
            delete_link(head);//删除操作
            break;
        case 3:
            printf("请出入您要查找的数：\n");
            scanf("%d",&num);
            query_link(head,num);//查找操作
            break;
        case 4:
            print_link(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
}
void init(){//初始化
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=1;
    ptr->next=NULL;
    head=ptr;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=2;
    head->next=ptr;
    ptr->next=NULL;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=3;
    head->next->next=ptr;
    ptr->next=NULL;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=4;
    head->next->next->next=ptr;
    ptr->next=NULL;
}
void print_link(node *ptr){
    int count=1;
    if (ptr==NULL){
        printf("链表为空!\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d-th节点的值：%d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
    }
}
void insert_link(){//插入操作
    int data=0;
    int choice;
    printf("请输入插入位置(1:开头,2:中间,3:结尾)：\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://从开始插入
        printf("请输入要插入的数据：");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        if (ptr){
            ptr->data=data;//为插入节点赋值
            ptr->next=head;//将新节点链接到原始节点的头上
            head=ptr;//更换链表的头
            printf("节点已插入！\n");
        }else{
            printf("申请内存失败！");
        }
        break;
    case 2://从中间插入
        printf("请输入要插入的数据：");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        ptr->data=data;
        if(ptr){
            int loc,i;
            node *temp=head;
            printf("请输入要插入的位置（插入该位置之后）：");
            scanf("%d",&loc);
            for(i=0;i<loc-1;i++){
                if(temp){
                    temp=temp->next;
                }else{
                    printf("该位置不存在（可能是由于位置长度大于链表长度导致的！\n");
                    return;
                }
            }
            ptr->next=temp->next;
            temp->next=ptr;
            printf("节点已插入！\n");
        }else{
            printf("申请内存失败！");
        }
        break;
    case 3://从结尾插入
        printf("请输入要插入的数据：");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        ptr->data=data;
        if (ptr){
            if(head){//链表不为空
                node *temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->next=NULL;
                printf("节点已插入！\n");
            }else{//链表为空
                ptr->next=NULL;
                head=ptr;
            }
        }else{
            printf("申请内存失败！");
        }
        printf("节点已插入！\n");
        break;
    default:
        printf("输入有误，请重新输入！");
        insert_link();
        break;
    }
}
void delete_link(){//删除操作
    int loc;
    int i;
    node *p;
    printf("请输入您要删除节点的位置（1:第一个，-1：最后一个，其他：中间位置）：\n");
    scanf("%d",&loc);
    switch(loc){
    case 1:
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("第一个节点删除成功！\n");
        break;
    case -1:
        if(head->next==NULL){
            ptr=head;
            head=NULL;
            free(ptr);
        }else{
            ptr=head;
            while(ptr->next!=NULL){
                p=ptr;
                ptr=ptr->next;
            }
            p->next=NULL;
            free(ptr);
        }
        printf("最后一个节点删除成功！\n");
        break;
    default:
        ptr=head;
        for(i=0;i<loc-1;i++){
            p=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                printf("该位置不存在（可能是由于位置长度大于链表长度导致的！\n");
                return;
            }
        }
        p->next=ptr->next;
        free(ptr);
        printf("%d-th个节点删除成功！\n",loc);
        break;
    }
}
void query_link(node *ptr,int data){//查找操作
    int count=1;
    int flag=0;
    if (ptr==NULL){
        printf("链表为空!\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->data==data){
                flag=1;
                printf("该数字在链表中的第%d个位置...\n",count);
            }
            ptr=ptr->next;
            count++;
        }
        if (!flag){
            printf("该数字不在链表中！\n");
        }
    }
}
