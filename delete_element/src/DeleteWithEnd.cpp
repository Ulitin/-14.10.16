#ifndef _DEL_WITH_END_
#define _DEL_WITH_END_

#include "nambers.h"
nambers* delete_namber_with_end(nambers* first, int n) // по условию n положительна
{
	if((first==0)||(n==0))
		throw 1;
	else
	{
		nambers* box_prev, * box_next;
		int i=1;
		while(first->next!=0)
		{
			first=first->next;
			i++;
		}
		if((i-n)>=0)
		{
			for(int j=1; j!=n; j++)
			{
				first = first->prev;
			}
			if(n==1)
			{
				box_prev=first->prev;
				box_prev->next=0;
				delete first;
				first=box_prev;
			}
			else
			{
				if(n==i)
				{
					box_next=first->next;
					box_next->prev=0;
					delete first;
					first = box_next;
				}
				else
				{
					box_prev=first->prev;
					box_next=first->next;
					delete first;
					box_prev->next=box_next;
					box_next->prev=box_prev;
					first = box_prev;
				}
			}
		}
		else
		{
			throw 1;
		}
		while(first->prev!=0)
		{
			first=first->prev;
		}
		return first;
	}
}

#endif