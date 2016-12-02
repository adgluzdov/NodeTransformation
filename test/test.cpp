#include <gtest/gtest.h>
#include <cstdlib>
#include "add.h"
#include <string> 

using namespace std;


void push(CNode **head, int data) {
    CNode *tmp = new CNode;
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void Print(CNode *head)
{
   CNode *phead = head;
   cout << "Spisok:" << endl;
   while(phead)
   {
      cout << phead->data << endl;
      phead = phead->next;
   }
}

TEST(Transformation,	can_null_CNode)
{
	CNode *node = NULL;
	ASSERT_ANY_THROW(transform(node));
}
TEST(Transformation, test1)
{
	CNode *node = NULL;
	push(&node,2);
	push(&node,1);
	transform(node);
	EXPECT_EQ(node->data,2);
}

TEST(Transformation, test2)
{
	CNode *node = NULL;
	push(&node,3);
	push(&node,2);
	push(&node,1);
	transform(node);
	EXPECT_EQ(node->data,2);
}

TEST(Transformation, test3)
{
	CNode *node = NULL;
	push(&node,3);
	push(&node,2);
	push(&node,1);
	transform(node);
	EXPECT_EQ(node->next->next->data,3);
}

TEST(Transformation, test4)
{
	CNode *node = NULL;
	push(&node,4);
	push(&node,3);
	push(&node,2);
	push(&node,1);
	transform(node);
	EXPECT_EQ(node->next->next->data,4);
}


int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  int _return = RUN_ALL_TESTS();
  system("pause");
  return _return;
}