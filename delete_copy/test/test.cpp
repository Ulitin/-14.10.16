#include <gtest/gtest.h>
#include "nambers.h"

TEST(nambers, proverca_na_0)
{
	nambers* first=0;
	ASSERT_ANY_THROW(delete_copy_in_struct(first));
}

TEST(nambers, inspect_on_smoke)
{
	nambers* first= new nambers;
	first->chislo=1;
	first->next=0;
	first->prev=0;
	first=delete_copy_in_struct(first);

	if((first->chislo==1)&&(first->next==0)&&(first->prev==0))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
}

TEST(nambers, easy_delete)
{
	nambers* first, *centre, *end;
	first = new nambers;
	first->prev=0;
	first->chislo=5;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=5;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_copy_in_struct(first);

	if((first->chislo==5)&&(first->next==0)&&(first->prev==0))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
}

TEST(nambers, normal1_delete)
{
	nambers* first, *centre, *end, *box;
	first = new nambers;
	first->prev=0;
	first->chislo=1;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=1;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_copy_in_struct(first);

	if((first->chislo==1)&&(first->next==end)&&(first->prev==0))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
	box=first;
	first=first->next;
	if((first->chislo==5)&&(first->next==0)&&(first->prev==box))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
}

TEST(nambers, normal2_delete)
{
	nambers* first, *centre, *end, *box;
	first = new nambers;
	first->prev=0;
	first->chislo=1;
	first->next= new nambers;
	centre=first->next;
	centre->chislo=5;
	centre->prev=first;
	centre->next= new nambers;
	end=centre->next;
	end->chislo=5;
	end->prev=centre;
	end->next=0;

	first=delete_copy_in_struct(first);

	if((first->chislo==1)&&(first->next==centre)&&(first->prev==0))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
	box=first;
	first=first->next;
	if((first->chislo==5)&&(first->next==0)&&(first->prev==box))
		ASSERT_EQ(1,1);
	else
		ASSERT_EQ(2,1);
}

