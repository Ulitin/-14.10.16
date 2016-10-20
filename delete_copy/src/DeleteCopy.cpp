#ifndef _DEL_END_COPY_
#define _DEL_END_COPY_

#include "nambers.h"

void delete_n_el(nambers* first)
{
	nambers* box_prev, *box_next;
	box_next=first->next;
	box_prev=first->prev;
	delete first;
	if(box_prev!=0)
	{
		box_prev->next=box_next;
	}
	if(box_next!=0)
	{
		box_next->prev=box_prev;
	}
}

nambers* delete_copy_in_struct(nambers* first)
{
	if(first==0)
	{
		throw 1;
	}
	else
	{
		nambers* box = first;
		while(first->next!=0)
		{
			box=first->next;
			if(box->chislo==first->chislo)
			{
				delete_n_el(box);
			}
			else
			{
				first=first->next;
			}
		}
		while(first->prev)
		{
			first=first->prev;
		}
		return first;
	}

}

#endif