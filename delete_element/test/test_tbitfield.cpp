#include <gtest/gtest.h>
#include "nambers.h"

TEST(nambers, proverca_na_0)
{
	nambers* first, *end;
	first = new nambers;
	end=first;
	first->prev=0;
	first->chislo=15;
	end->next=0;
	ASSERT_ANY_THROW(delete_namber_with_end(first, 0));
}

TEST(nambers, proverca_na_NULL_ukazat)
{
	nambers* first=0;
	ASSERT_ANY_THROW(delete_namber_with_end(first, 2));
}

TEST(nambers, out_list)
{
	nambers* first;
	first = new nambers;
	first->prev=0;
	first->chislo=15;
	first->next=0;

	ASSERT_ANY_THROW(delete_namber_with_end(first, 2));

}

TEST(nambers, delete_begin_for_two_el)
{
	nambers* first, *box;
	first = new nambers;
	box=first;
	first->prev=0;
	first->chislo=15;
	first->next= new nambers;
	first=first->next;
	first->chislo=10;
	first->prev=box;
	first->next=0;
	first=first->prev;

	first=delete_namber_with_end(first, 2);
	if((first->chislo==10)&&(first->prev==0)&&(first->next==0))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
}

TEST(nambers, delete_end_for_two_el)
{
	nambers* first, *box;
	first = new nambers;
	box=first;
	first->prev=0;
	first->chislo=15;
	first->next= new nambers;
	first=first->next;
	first->chislo=10;
	first->prev=box;
	first->next=0;
	first=box;

	first=delete_namber_with_end(first, 1);
	if((first->chislo==15)&&(first->prev==0)&&(first->next==0))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
}

TEST(nambers, delete_begin_for_three_el)
{
	nambers* first, *centre, *end;
	first = new nambers;
	first->prev=0;
	first->chislo=15;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=10;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_namber_with_end(first, 3);
	if((first->chislo==10)&&(first->prev==0)&&(first->next==end))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
	first=first->next;
	if((first->chislo==5)&&(first->prev==centre)&&(first->next==0))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
}

TEST(nambers, delete_centre_for_three_el)
{
	nambers* first, *centre, *end, *box;
	first = new nambers;
	first->prev=0;
	first->chislo=15;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=10;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_namber_with_end(first, 2);
	if((first->chislo==15)&&(first->prev==0)&&(first->next==end))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
	box=first;
	first=first->next;
	if((first->chislo==5)&&(first->prev==box)&&(first->next==0))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
}

TEST(nambers, delete_end_for_three_el)
{
	nambers* first, *centre, *end, *box;
	first = new nambers;
	first->prev=0;
	first->chislo=15;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=10;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_namber_with_end(first, 1);
	if((first->chislo==15)&&(first->prev==0)&&(first->next==centre))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
	box=first;
	first=first->next;
	if((first->chislo==10)&&(first->prev==box)&&(first->next==0))
		ASSERT_EQ(0,0);
	else
		ASSERT_EQ(1,0);
}