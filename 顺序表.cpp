#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef int ElemType;
// 创建结构体
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;
//初始化顺序表 
void initList(SeqList *L)
{
	L->length = 0;
}
//添加元素 
int appendElem(SeqList *L,ElemType e)
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}
	
	L->data[L->length]=e;
	L->length++;
	return 1;
}
//遍历
void listElem(SeqList *L)
{
	int i;
	for(i=0;i < L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
//插入元素 
int insertElem(SeqList *L,int pos,ElemType e)
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}
	
	if(pos < 1 || pos > L->length)
	{
		printf("插入元素有误\n");
		return 0;
	}
	
	if(pos <= L->length)
	{
		int i; 
		for(i = L->length-1;i >= pos-1;i--)
		{
			L->data[i+1] = L->data[i];
		}	
		L->data[pos-1] = e;
		L->length++;
	}
	
	return 0;
}
//删除元素
int deleteElem(SeqList *L,int pos,ElemType *e)			//*e是用来储存删除的数据 
{
	if(L->length == 0)
	{
		printf("空表\n");
		return 0;
	}
	
	if(pos < 1 || pos > L->length)
	{
		printf("删除数据位置有误\n");
		return 0;
	}
	
	*e = L->data[pos-1];
	if(pos < L->length)
	{
		int i;
		for(i=pos;i<L->length;i++)
		{
			L->data[i-1]=L->data[i];
		}
	}
	L->length--;
	return 1;
}
//查找
int findElem(SeqList *L,ElemType e)
{
	if(L->length == 0)
	{
		printf("空表格\n");
		return 0;
	}
	
	int i; 
	for(i = 0;i < L->length;i++)
	{
		if(L->data[i]  == e)
		{
			return i+1;
		}
	}
}
 
int main()
{
	SeqList list;
	initList(&list);
	printf("顺序表个数%d\n",list.length);
	printf("目前占用内存%zu\n",sizeof(list.data));
	
	appendElem(&list,88);
	appendElem(&list,34);
	appendElem(&list,67);
	listElem(&list);
	
	insertElem(&list,2,32);
	listElem(&list);
	
	ElemType delDate;
	deleteElem(&list,2,&delDate);
	printf("被删除的数据是%d\n",delDate); 
	listElem(&list);
	
	printf("%d\n",findElem(&list,67));
	return 0;
}
