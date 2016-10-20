#ifndef _NAMBERS_
#define _NAMBERS_

struct nambers
{
	int chislo;
	nambers* next;
	nambers* prev;
};

nambers* delete_namber_with_end(nambers* first, int n); // удалить n элемент с конца

#endif