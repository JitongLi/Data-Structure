#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *l;
    char *data;
    struct Node *r;
}node;
node *tree,*ptr;
int main(){
    int choice;
    choice=888;
    while(choice!=0){
        printf("+---二叉树遍历系统---+\t\t\n");
        printf("|      1.初始化\t     |\n");
        printf("|\t2.先序\t     |\n");
        printf("|\t3.中序\t     |\n");
        printf("|\t4.后序\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请出入您的选择：\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            init();
            break;
        case 2:
            printf("二叉树的先序遍历结果为：\n");
            print_pre_root(tree);
            printf("\n");
            break;
        case 3:
            printf("二叉树的中序遍历结果为：\n");
            print_mid_root(tree);
            printf("\n");
            break;
        case 4:
            printf("二叉树的后序遍历结果为：\n");
            print_pos_root(tree);
            printf("\n");
            break;
        case 0:
            exit(0);
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
    return 0;
}
void init(){
    ptr=(node *)malloc(sizeof(node));
    ptr->data="-";
    ptr->l=NULL;
    ptr->r=NULL;
    tree=ptr;
    node *lev2_1=(node *)malloc(sizeof(node));
    lev2_1->data="+";
    lev2_1->l=NULL;
    lev2_1->r=NULL;
    node *lev2_2=(node *)malloc(sizeof(node));
    lev2_2->data="/";
    lev2_2->l=NULL;
    lev2_2->r=NULL;
    tree->l=lev2_1;
    tree->r=lev2_2;
    node *lev3_1=(node *)malloc(sizeof(node));
    lev3_1->data="a";
    lev3_1->l=NULL;
    lev3_1->r=NULL;
    node *lev3_2=(node *)malloc(sizeof(node));
    lev3_2->data="*";
    lev3_2->l=NULL;
    lev3_2->r=NULL;
    node *lev3_3=(node *)malloc(sizeof(node));
    lev3_3->data="e";
    lev3_3->l=NULL;
    lev3_3->r=NULL;
    node *lev3_4=(node *)malloc(sizeof(node));
    lev3_4->data="f";
    lev3_4->l=NULL;
    lev3_4->r=NULL;
    lev2_1->l=lev3_1;
    lev2_1->r=lev3_2;
    lev2_2->l=lev3_3;
    lev2_2->r=lev3_4;;
    node *lev4_1=(node *)malloc(sizeof(node));
    lev4_1->data="b";
    lev4_1->l=NULL;
    lev4_1->r=NULL;
    node *lev4_2=(node *)malloc(sizeof(node));
    lev4_2->data="-";
    lev4_2->l=NULL;
    lev4_2->r=NULL;
    lev3_2->l=lev4_1;
    lev3_2->r=lev4_2;
    node *lev5_1=(node *)malloc(sizeof(node));
    lev5_1->data="c";
    lev5_1->l=NULL;
    lev5_1->r=NULL;
    node *lev5_2=(node *)malloc(sizeof(node));
    lev5_2->data="d";
    lev5_2->l=NULL;
    lev5_2->r=NULL;
    lev4_2->l=lev5_1;
    lev4_2->r=lev5_2;
}
void print_pre_root(node *ptr){
    if(ptr){
        printf("%s  ",ptr->data);
        print_pre_root(ptr->l);
        print_pre_root(ptr->r);
    }
}
void print_mid_root(node *ptr){
    if(ptr!=NULL){
        print_mid_root(ptr->l);
        printf("%s  ",ptr->data);
        print_mid_root(ptr->r);
    }
}
void print_pos_root(node *ptr){
    if(ptr!=NULL){
        print_pos_root(ptr->l);
        print_pos_root(ptr->r);
        printf("%s  ",ptr->data);
    }
}
