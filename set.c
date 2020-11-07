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

	//修改
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





//插入新的值
void setinsert(symset s, int elem)
{
	symset tmp = s;
	snode* newnode;     //设置新的结点
	newnode = (snode*)malloc(sizeof(snode));
	newnode->elem = elem;

	while (tmp->next && tmp->next->elem < elem)   //找到对应的位置（从小到大）
	{
		tmp = tmp->next;
	}
	
	newnode->next = tmp->next;  //单链表加入此节点
	tmp->next = newnode;
} // setinsert








//返回一个新生成的单链表
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

//删除单链表
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




//查找一个元素是否在symset中，若在返回1，不在则返回0
int inset(int elem, symset s)    
{
	symset tmp = s->next;
	while (tmp)    //在链表中查找
	{
		if (tmp->elem == elem)  //找到
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
