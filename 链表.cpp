#include<stdio.h>
#include<stdlib.h> 

typedef int ElemType;
//���� 
typedef struct node{
	ElemType data;
	struct node *next;
}Node;
//��ʼ�� 
Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//��ʼ���ڵ㣨���ڵ����ݲ����� 
Node* initListWithElem(ElemType e)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->next = NULL;
	return node; 
}
//ͷ�巨 
int insertHead(Node* L,ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//���� 
void listNode(Node* L)
{
	Node *p = L->next;
	while(p != NULL)
	{
		printf("%d\n",p->data);//test1��3
//		printf("%c\n",p->data);//test2
		p = p->next;
	}
	printf("\n");
}
//��β�ڵ� 
Node* get_tail(Node *L)
{
	Node *p = L;
	while(p->next != NULL)
	{
		p = p->next;
	}
	return p;
}
//β�巨 
Node* insertTail(Node *tail,ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}
//β�巨�ڵ�
Node* insertTailWithNode(Node *tail,Node *node)
{
	tail->next = node;
	node->next = NULL;
	return node;
} 
//ָ��λ�ò���ڵ� 
int insertNode(Node *L,int pos,ElemType e)
{
	//�����������λ�õ�ǰ���ڵ� 
	Node *p = L;
	int i = 0;
	//���������ҵ�����λ�õ�ǰ���ڵ� 
	while(i < pos-1)
	{
		p = p->next;
		i++;
		if(p == NULL)
		{
			return 0;
		}
	}
	//�����µĽڵ� 
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//ɾ���ڵ�
int deleteNode(Node *L,int pos)
{
	//Ҫɾ���ڵ��ǰ�� 
	Node *p = L;
	int i = 0;
	while(i < pos-1)
	{
		p = p->next;
		i++;
		if(p == NULL)
		{
			return 0;
		}
	}
	if(p->next == NULL)
	{
		printf("Ҫɾ����λ�ô���\n");
		return 0;
	}
	//qָ��Ҫɾ���Ľڵ� 
	Node *q = p->next;
	//��Ҫɾ���ڵ��ǰ��ָ��Ҫɾ���ڵ�ĺ�� 
	p->next = q->next;
	//�ͷ� 
	free(q);
	return 1;
}
//��ȡ������ 
int listLength(Node *L)
{
	Node *p = L;
	int len = 0;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
//�ͷ����� 
void freeList(Node *L)
{
	Node *p = L->next;
	Node *q;
	
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p=q;
	}
	L->next = NULL;
 } 
//Ѱ�ҵ�����n��ֵ�������ÿ���˫ָ�룩
int findNodeFS(Node *L,int k)
{
	Node *fast = L->next;
	Node *slow = L->next;
	int i;
	for (i=0;i<k;i++)
	{
		fast = fast->next;
	}
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	printf("������%d���ڵ��ֵΪ��%d\n",k,slow->data);
} 

//���������ڵ㹲ͬ��׺����ʼλ�ã�ʹ��ǰ��Ҫ��ElemType�� 
Node* findIntersectionNode(Node *headA,Node *headB)
{
	if(headA == NULL || headB ==NULL)
	{
		return NULL;
	}
	
	Node *p = headA;
	int lenA = 0;
	int lenB = 0;
	
	//��������A����ȡ����A�ĳ���
	while(p != NULL)
	{
		p = p->next;
		lenA++;
	}
	p = headB;
	//��������B����ȡ����B�ĳ���
	while(p != NULL)
	{
		p = p->next;
		lenB++;
	}
	
	Node *fast;
	Node *slow;
	int step;
	if(lenA > lenB)
	{
		step = lenA - lenB;
		fast = headA;
		slow = headB;
	}
	else
	{
		step = lenB - lenA;
		fast = headB;
		slow = headA;
	}
	
	//�ÿ�ָ������step�� 
	int i;
	for(i=0;i < step;i++)
	{
		fast = fast->next;
	}
	//����ָ��ͬ���ߣ�ֱ��ָ��ͬһ���ڵ��Ƴ�ѭ�� 
	while(fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		
	}
	return fast;
} 

//ɾ������ֵ��ͬ�Ľڵ�
void removeNode(Node *L,int n)
{
	Node *p = L;
	int index;//��Ϊ�����±�ʹ��
	int *q = (int*)malloc(sizeof(int)*(n+1));
	
	//�������飬��ʼ��Ϊ0
	int i;
	for(i = 0;i < n+1;i++)
	{
		*(q + i) = 0;
	} 
	
	while(p->next != NULL)
	{
		//abs��ȡ����ֵ
		index = abs(p->next->data);
		if(*(q + index) == 0)
		{
			*(q + index) = 1;
			p = p->next;
		}
		else
		{
			Node *temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}
	free(q);
} 

//��ת����
Node* reverseList(Node* head)
{
	Node *first = NULL;
	Node *second = head->next;
	Node *third;
	
	while(second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node *hd = initList();
	hd->next = first;
	
	return hd;
} 

//ɾ���м�ڵ�
int delMiddleNode(Node *head)
{
	Node *fast = head->next;
	Node *slow = head;
	
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	Node *q = slow->next;
	slow->next = q->next;
	free(q);
	
	return 1;
}

//������������ 
void reOderList(Node *head)
{
	Node *fast = head->next;
	Node *slow = head;
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	Node *first = NULL;
	Node *second = slow->next;
	slow->next = NULL;
	Node *third =NULL;
	
	while(second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third; 
	}
	
	Node *p1 = head->next;
	Node *q1 = first;
	Node *p2,*q2;
	while(p1 != NULL && q1 != NULL)
	{
		p2 = p1->next;
		q2 = q1->next;
		
		p1->next = q1;
		q1->next = p2;
		
		p1 = p2;
		q1 = q2;
	}
}

//�ж������Ƿ��л�
int isCycle(Node *head)
{
	Node *fast = head;
	Node *slow = slow;
	
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast = slow)
		{
			return 1;
		}
	}
	
	return 0;
	
}
 
int main()
{
	//test1
//	Node *list = initList();
//	
//	Node *tail = get_tail(list);
//	tail = insertTail(tail,10);
//	tail = insertTail(tail,20);
//	tail = insertTail(tail,30);
//	
//	listNode(list);
//	
//	insertNode(list,2,15);
//	listNode(list);
//	
//	deleteNode(list ,2);
//	listNode(list);
//	
//	printf("%d",listLength(list));
//	
//	findNodeFS(list,2);
//	
//	freeList(list);
//	printf("%d",listLength(list));
//	
//	free(list); 


	//test2
//	Node *listA = initList();
//	Node *listB = initList();
//	Node *tailA = get_tail(listA);
//	Node *tailB = get_tail(listB);
//	tailA = insertTail(tailA,'l');
//	tailA = insertTail(tailA,'o');
//	tailA = insertTail(tailA,'a');
//	tailA = insertTail(tailA,'d');
//	tailB = insertTail(tailB,'b');
//	tailB = insertTail(tailB,'e');
//	
//	Node *nodeI = initListWithElem('i');
//	tailA = insertTailWithNode(tailA,nodeI);
//	tailB = insertTailWithNode(tailB,nodeI);
//	Node *nodeN = initListWithElem('n');
//	tailA = insertTailWithNode(tailA,nodeN);
//	tailB = insertTailWithNode(tailB,nodeN);
//	Node *nodeG = initListWithElem('g');
//	tailA = insertTailWithNode(tailA,nodeG);
//	tailB = insertTailWithNode(tailB,nodeG);
//	
//	listNode(listA);
//	listNode(listB);
//	
//	printf("%c\n",findIntersectionNode(listA,listB)->data);
	
	
	//test3
//	Node *list = initList();
//	
//	Node *tail = get_tail(list);
//	
//	tail = insertTail(tail,21);
//	tail = insertTail(tail,-15);
//	tail = insertTail(tail,-15);
//	tail = insertTail(tail,7);
//	tail = insertTail(tail,15);
//	listNode(list);
//	
//	removeNode(list,21);
//	listNode(list);


	//test3
//	Node *list = initList();
//	
//	Node *tail = get_tail(list);
//	
//	tail = insertTail(tail,1);
//	tail = insertTail(tail,2);
//	tail = insertTail(tail,3);
//	tail = insertTail(tail,4);
//	tail = insertTail(tail,5);
//	tail = insertTail(tail,6);
//	tail = insertTail(tail,7);
//	listNode(list);
//	
//	Node* reverse = reverseList(list);
//	listNode(reverse);
//	


	//test4
//	Node *list = initList();
//	
//	Node *tail = get_tail(list);
//	
//	tail = insertTail(tail,1);
//	tail = insertTail(tail,2);
//	tail = insertTail(tail,3);
//	tail = insertTail(tail,4);
//	tail = insertTail(tail,5);
//	tail = insertTail(tail,6);
//	tail = insertTail(tail,7);
//	listNode(list);
//	
//	delMiddleNode(list);
//	listNode(list);


	//test5
//	Node *list = initList();
//	
//	Node *tail = get_tail(list);
//	
//	tail = insertTail(tail,1);
//	tail = insertTail(tail,2);
//	tail = insertTail(tail,3);
//	tail = insertTail(tail,4);
//	tail = insertTail(tail,5);
//	tail = insertTail(tail,6);
//	listNode(list);
//	
//	reOderList(list);
//	listNode(list);


	//test6
	Node *list = initList();
	
	Node *tail = get_tail(list);
	
	tail = insertTail(tail,1);
	tail = insertTail(tail,2);
	tail = insertTail(tail,3);
	Node *three = tail;
	tail = insertTail(tail,4);
	tail = insertTail(tail,5);
	tail = insertTail(tail,6);
	tail = insertTail(tail,7);
	tail = insertTail(tail,8);
	tail->next = three;

	if(isCycle(list))
	{
		printf("�л�");
	}
	else
	{
		printf("�޻�");
	}

	return 1;
}
