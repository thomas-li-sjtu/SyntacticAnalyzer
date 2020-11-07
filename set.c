/************  SET.c  *************/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "set.h"


symset uniteset(symset s1, symset s2)
{
	symset s;
	snode* p;
	
	s = p = (snode*) malloc(sizeof(snode));
	
	s1 = s1->next;           
	s2 = s2->next;			 				

	//�޸�
	while (s1 && s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		if (s1->elem < s2->elem)
		{
			p->elem = s1->elem;
			s1 = s1->next;
		}
		else
		{
			p->elem = s2->elem;
			s2 = s2->next;
		}
	}

	while (s1)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s1->elem;
		s1 = s1->next;
		
	}

	while (s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s2->elem;
		s2 = s2->next;
	}

	p->next = NULL;

	return s;
} // uniteset





//�����µ�ֵ
void setinsert(symset s, int elem)
{
	symset tmp = s;
	snode* newnode;     //�����µĽ��
	newnode = (snode*)malloc(sizeof(snode));
	newnode->elem = elem;

	while (tmp->next && tmp->next->elem < elem)   //�ҵ���Ӧ��λ�ã���С����
	{
		tmp = tmp->next;
	}
	
	newnode->next = tmp->next;  //���������˽ڵ�
	tmp->next = newnode;
} // setinsert








//����һ�������ɵĵ�����
symset createset(int elem, .../* SYM_NULL */)
{
	va_list list;
	symset s;

	s = (snode*) malloc(sizeof(snode));
	s->next = NULL;

	va_start(list, elem);
	while (elem)
	{
		setinsert(s, elem);
		elem = va_arg(list, int);
	}
	va_end(list);
	return s;
} // createset

//ɾ��������
void destroyset(symset s)
{
	snode* p;

	while (s)
	{
		p = s;
		s = s->next;
		free(p);
	}
} // destroyset




//����һ��Ԫ���Ƿ���symset�У����ڷ���1�������򷵻�0
int inset(int elem, symset s)    
{
	symset tmp = s->next;
	while (tmp)    //�������в���
	{
		if (tmp->elem == elem)  //�ҵ�
		{
			return 1;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return 0;
} // inset

// EOF set.c
