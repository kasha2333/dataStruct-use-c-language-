/*
* 内容：线性表的链接存储实践
* 作者：马懿辉
* 创建日期：2021 12 8
* 最后修改日期： 2021 12 8
*/
#include <stdio.h>
#include <stdlib.h>
//定义结构体-学生
typedef struct 
{
    int num;
    char name[8];
    char sex[2];
    int age;
    int score;
}DataType;

//定义结构体-线性表
typedef struct  node 
{
    DataType data;
    struct node *next; //链接下一个node用
}Node,*LinkList;

LinkList head;

LinkList initiateLinkList();
int lengthLinkList(LinkList head); //求长度
Node *getLinkList(LinkList head, int i); //找位置节点
int locateLinkList(LinkList head, DataType x); //找数据位置
void insertLinkList(LinkList head, DataType x, int i); ////插入数据
void deleteLinkList(LinkList head, int i);//删除

//此处代码全为测试
int main(){
    printf("初始化之前的指针的值为%p\n",head);
    //初始化head
    head = initiateLinkList();
    printf("初始化之后的指针的值为%p\n",head);
    //求表长
    printf("什么都没有时表长为%d\n",lengthLinkList(head));
    //加数据
    DataType dt;
    dt.age = 18;
    insertLinkList(head, dt, 1);
    //求表长
    printf("有一个数据表长为%d\n",lengthLinkList(head));
    //删除一个元素
    deleteLinkList(head, 1);
    //求表长
     printf("把那个数据删除后的长度%d\n",lengthLinkList(head));
}
//初始化
LinkList initiateLinkList(){
    LinkList head; //创建一个头指针
    head = malloc(sizeof(Node));//动态构建一个节点
    head->next = NULL;
    return head;
}

//求表长
int lengthLinkList(LinkList head){
    //求单链表的head长度
    Node *p = head;
    int count = 0;
    while (p->next!=NULL){
        p = p->next;
        count++;
    }
    return count;
}

//读取表元素---从head中读取
Node * getLinkList(LinkList head,int i){
    //在单链表head中查找第i个元素节点，若找到,则返回指向该节点的指针，否则返回NULL;
    Node *p;
    p = head->next;
    int c = 1;
    while ((c<i)&&(p!=NULL)){
        p = p->next;
        c++;
    }
    if(i==c){
        return p;
    }else{
        return NULL;
    }
}

//定位-从head中找给定元素的位置
int locateLinkList(LinkList head,DataType x){
    Node *p = head;
    p = p->next;
    int i = 0;
    while (p!=NULL&&p->data.num!=x.num){
        i++;
        p = p->next;
    }
    if(p!=NULL){
        return i + 1;
    }else{
        return 0;
    }
}

//插入数据
void insertLinkList(LinkList head,DataType x,int i){
    //在表head的第i个元素节点之前插入一个以x为值的新节点
    Node *p, *q;
    if(i==1) {
        q = head;
    }else{
        //找到i-1元素
        q = getLinkList(head,i-1);
    }
    if(q==NULL){
        printf("找不到位置");
        return;
    }else{
        p = malloc(sizeof(Node));//生成新节点
        p->data = x;
        p->next = q->next;
        q->next = p;
    }
}

//删除 将给定元素i删除
void deleteLinkList(LinkList head,int i){
    Node *q,*p;
    if(i==1){
        q = head;
    }else{
        q = getLinkList(head,i-1);
    }
    if(q!=NULL&&q->next!=NULL){ //如果直前驱存在而且待删除节点存在
        p = q->next;
        q->next = p->next;
        free(p);
    }else{
        printf("找不大要删除的节点");
        return;
    }
}
