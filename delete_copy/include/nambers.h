#ifndef _NAMBERS_
#define _NAMBERS_

struct nambers
{
	int chislo;
	nambers* next;
	nambers* prev;
};

nambers* delete_copy_in_struct(nambers* first);// удалить копии в структуре

#endif