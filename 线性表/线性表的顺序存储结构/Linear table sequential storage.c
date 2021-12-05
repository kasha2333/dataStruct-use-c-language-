#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
	int num;
	char name[8];//姓名
	char sex[2];//性别
	int age; //年龄
	int score;//入学成绩
}DataType; 

typedef struct{
	DataType data[7];   //线性表最多存7个学生
	int length;			//线性表的长度
}SeqList;

SeqList student;
//插入
void insertSeqList(SeqList *L,DataType x,int i);
//打桩
void printSeqList(SeqList L);
//删除
void  deleteSeqList(SeqList *L,int i);
//查找
int locateSeqList(SeqList L, DataType dt);
int main() {
	//此处为各个方法的测试
	DataType dt1;
	dt1.num = 1;
	strcpy(dt1.name,"于小C");
	insertSeqList(&student,dt1,1);

	DataType dt2;
	dt2.num = 2;
	strcpy(dt2.name, "小超梦");
	insertSeqList(&student, dt2, 2);
	printSeqList(student);


	

	printf("位置在%d", locateSeqList(student, dt2));

}
//插入数据
void insertSeqList(SeqList* L, DataType x, int i) {
	//将DataType插入SqlList的第i个元素的位置
	if ((*L).length == 7) { //判定插入位置是否合法
		printf("插入位置不合法");
		return;
	}
	if (i<1||i>L->length+1) {//判断插入位置是否合法
		printf("插入位置不合法");
		return;
	}
	for (int j = L->length; j >= i;j--) {//从最后一个元素一次往后挪，挪到第i个元素
		L->data[j] = L->data[j-1];//依次往后移
	}
	
	L->data[i - 1] = x;
	L->length++;
}
//输出当前student结构体中的DataType都有什么
void printSeqList(SeqList L) {
	DataType dt;
	for (int j = 0; j < L.length;j++) {
		dt = L.data[j];
		printf("第%d个元素的学号为%d,姓名为%s...\n",j+1,dt.num,dt.name);
	}
}
//根据给定的位置删除
void deleteSeqList(SeqList *L,int i) {
	if (i<1 || i>L->length) {
		printf("非法位置");
		return;
	}
	for (int j=i;j<L->length;j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
}
//定位，找出DataType在SeqList中第一次出现的位置，没有返回0
int locateSeqList(SeqList L,DataType dt) {
	int i = 0; //L.data的下标。
	
	while ((i<L.length)&&(L.data[i].num!=dt.num)) {
		
		i++;
	}
	if (i<L.length) {
		int c = i + 1;
		return c ;
	}
	else {
		return 0;
	}
}

/*
* 顺序表实现算法的分析
* 插入算法时间复杂度O(n) 当n很大时效率很低
* 删除算法时间复杂度O(n)
* 定位算法时间复杂度O(n)
* 
*/
