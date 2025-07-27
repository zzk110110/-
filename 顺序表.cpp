#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef int ElemType;
// �����ṹ��
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;
//��ʼ��˳��� 
void initList(SeqList *L)
{
	L->length = 0;
}
//���Ԫ�� 
int appendElem(SeqList *L,ElemType e)
{
	if(L->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return 0;
	}
	
	L->data[L->length]=e;
	L->length++;
	return 1;
}
//����
void listElem(SeqList *L)
{
	int i;
	for(i=0;i < L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
//����Ԫ�� 
int insertElem(SeqList *L,int pos,ElemType e)
{
	if(L->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return 0;
	}
	
	if(pos < 1 || pos > L->length)
	{
		printf("����Ԫ������\n");
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
//ɾ��Ԫ��
int deleteElem(SeqList *L,int pos,ElemType *e)			//*e����������ɾ�������� 
{
	if(L->length == 0)
	{
		printf("�ձ�\n");
		return 0;
	}
	
	if(pos < 1 || pos > L->length)
	{
		printf("ɾ������λ������\n");
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
//����
int findElem(SeqList *L,ElemType e)
{
	if(L->length == 0)
	{
		printf("�ձ��\n");
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
	printf("˳������%d\n",list.length);
	printf("Ŀǰռ���ڴ�%zu\n",sizeof(list.data));
	
	appendElem(&list,88);
	appendElem(&list,34);
	appendElem(&list,67);
	listElem(&list);
	
	insertElem(&list,2,32);
	listElem(&list);
	
	ElemType delDate;
	deleteElem(&list,2,&delDate);
	printf("��ɾ����������%d\n",delDate); 
	listElem(&list);
	
	printf("%d\n",findElem(&list,67));
	return 0;
}
