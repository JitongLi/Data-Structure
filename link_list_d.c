#include <stdio.h>
/*
该文件代码用于实现双链表
created time:2020.07.25
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
typedef struct Node{
    struct Node *pre;
    int data;
    struct Node *next;
}node;
node *ptr,*head,*tail;
void main(){
    init();
    int choice;
    choice=9;
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
            insert_link();
            break;
        case 2:
            delete_link();
            break;
        case 3:
            search_link();
            break;
        case 4:
            print_link();
            break;
        case 0:
            exit(0);
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
    }
}
void init(){//初始化
    ptr=(node *)malloc(sizeof(node));
    if(head){
    }else{
        ptr=(node *)malloc(sizeof(node));
        ptr->data=3;
        ptr->next=NULL;
        ptr->pre=NULL;
        head=ptr;
        ptr=(node *)malloc(sizeof(node));
        ptr->data=2;
        ptr->next=head;
        head->pre=ptr;
        ptr->pre=NULL;
        head=ptr;
        ptr=(node *)malloc(sizeof(node));
        ptr->data=1;
        ptr->next=head;
        head->pre=ptr;
        ptr->pre=NULL;
        head=ptr;
    }
}
void print_link(){//遍历操作
    ptr=head;
    int count=1;
    while(ptr){
        printf("%d-th节点的值：%d\n",count,ptr->data);
        ptr=ptr->next;
        count++;
    }
}
void search_link(){//查找操作
    int data;
    printf("请输入您找查找的数：");
    scanf("%d",&data);
    ptr=head;
    while(ptr){
        ptr=ptr->next;
        if (ptr->data==data){
            printf("该数字在链表的第%d个位置上...\n");
        }else{
            printf("该数字不在链表中\n");
            return;
        }
    }
}
void insert_link(){//插入操作
    int choice,num,i,loc;
    printf("请输入您要插入的位置（1：头节点2：指定位置3：尾节点）\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://头节点插入
        printf("请输入要插入的数据:");
        scanf("%d",&num);
        ptr=(node *)malloc(sizeof(node));
        if(head){//头节点不为空
            ptr->data=num;
            ptr->next=head;
            head->pre=ptr;
            ptr->pre=NULL;
            head=ptr;
            printf("节点插入成功！\n");
        }else{//头节点为空的情况
            ptr->next=NULL;
            ptr->pre=NULL;
            ptr->data=num;
            head=ptr;
            printf("节点插入成功！\n");
        }
        break;
    case 2://指定位置插入
        printf("请输入要插入的数据:");
        scanf("%d",&num);
        printf("请输入要插入的位置:");
        scanf("%d",&loc);
        ptr=(node *)malloc(sizeof(node));
        node *temp=head;
        if(head){
            for(i=0;i<loc-1;i++){
                if(!temp->next){
                    printf("该插入位置不存在（可能是由于输入位置大于链表长度导致的）！\n");
                    return;
                }else{
                    temp=temp->next;
                }
            }
            ptr->data=num;
            ptr->next=temp->next;
            ptr->pre=temp;
            temp->next->pre=ptr;
            temp->next=ptr;
            printf("节点插入成功！\n");
        }else{
            printf("链表为空！\n");
        }
        break;
    case 3://尾节点插入
        printf("请输入要插入的数据:");
        scanf("%d",&num);
        ptr=(node *)malloc(sizeof(node));
        if(head){//头节点不为空
            node *temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->data=num;
            ptr->pre=temp;
            ptr->next=NULL;
            printf("节点插入成功！\n");
        }else{//头节点为空
            ptr->next=NULL;
            ptr->pre=NULL;
            ptr->data=num;
            head=ptr;
            printf("节点插入成功！\n");
        }
        break;
    default:
        printf("输入有误，请重新操作！\n");
        insert_link();
        break;
    }
}
void delete_link(){//删除操作
    int choice,i,loc;
    printf("请输入要删除的位置（1：头节点；2：指定节点；3：尾节点）\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        if(head){//链表不为空则进行操作
            ptr=head;
            head=head->next;
            head->pre=NULL;
            free(ptr);
            printf("节点删除成功！\n");
        }else{
            printf("链表为空！\n");
        }
        break;
    case 2:
        if(head){
            printf("请输入要删除节点的位置：");
            scanf("%d",&loc);
            node *temp=head;
            for(i=0;i<loc;i++){
                if(temp->next){
                    temp=temp->next;
                }else{
                    printf("该插入位置不存在（可能是由于输入位置大于链表长度导致的）！\n");
                    return;
                }
            }
            if(temp->next){
                ptr=temp;
                ptr->pre->next=ptr->next;
                ptr->next->pre=ptr->pre;
                free(ptr);
            }else{
                temp->pre->next=NULL;
                free(temp);
                printf("该节点为尾节点，已删除！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case 3:
        if(head){
            ptr=head;
            while(ptr->next){
                ptr=ptr->next;
            }
            ptr->pre->next=NULL;
            free(ptr);
            printf("节点删除成功！\n");
        }else{
            printf("链表为空！\n");
        break;
    default:
        printf("输入有误，请重新输入！\n");
        delete_link();
        break;
        }
    }
}
