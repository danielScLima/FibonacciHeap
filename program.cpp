// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "fibonacciheap.h"

TEST_CASE( "Testing the insert calls in the heap", "[single-file]" )
{
    SECTION( "Inserting" )
	{
		FibonacciHeapDS f;
		f.insertBeforeStart(50);
		
		FibonacciHeapNode *startNode = f.getStartNode();
		FibonacciHeapNode *minNode = f.getMinNode();
		REQUIRE (startNode->data == 50);
		REQUIRE (minNode->data == 50);
		REQUIRE (startNode->next->data == 50);
		
		f.insertBeforeStart(100);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (minNode->data == 50);
		
		REQUIRE (startNode->data == 50);
		REQUIRE (startNode->next->data == 100);
		REQUIRE (startNode->next->next->data == 50);
		
		f.insertBeforeStart(75);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode->data == 50);
		REQUIRE (minNode->data == 50);
		
		REQUIRE (startNode->data == 50);
		REQUIRE (startNode->next->data == 100);
		REQUIRE (startNode->next->next->data == 75);
		REQUIRE (startNode->next->next->next->data == 50);
		
		f.insertBeforeStart(200);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode->data == 50);
		REQUIRE (minNode->data == 50);
		
		REQUIRE (startNode->data == 50);
		REQUIRE (startNode->next->data == 100);
		REQUIRE (startNode->next->next->data == 75);
		REQUIRE (startNode->next->next->next->data == 200);
		REQUIRE (startNode->next->next->next->next->data == 50);
    }
	
}

TEST_CASE( "Testing the remove calls in the heap", "[single-file]" )
{	
	SECTION( "Removing the min" )
	{
		FibonacciHeapDS f;
		f.insertBeforeStart(50);	
		f.insertBeforeStart(100);
		f.insertBeforeStart(75);
		f.insertBeforeStart(200);
		
		FibonacciHeapNode *startNode = f.getStartNode();
		FibonacciHeapNode *minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 50);
		REQUIRE (minNode->data == 50);
		
		REQUIRE (startNode->data == 50);
		REQUIRE (startNode->next->data == 100);
		REQUIRE (startNode->next->next->data == 75);
		REQUIRE (startNode->next->next->next->data == 200);
		REQUIRE (startNode->next->next->next->next->data == 50);
		
		FibonacciHeapNode * min = f.deleteMinInterface(); //50
		REQUIRE (min->data == 50);
		delete min;
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode->data == 100);
		REQUIRE (minNode->data == 75);
		
		min = f.deleteMinInterface(); //75
		REQUIRE (min->data == 75);
		delete min;
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode->data == 100);
		REQUIRE (minNode->data == 100);
		
		min = f.deleteMinInterface(); //100
		REQUIRE (min->data == 100);
		delete min;
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 200);
		
		min = f.deleteMinInterface(); //200
		REQUIRE (min->data == 200);
		delete min;
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		REQUIRE (startNode == nullptr);
		REQUIRE (minNode == nullptr);
    }
}

TEST_CASE( "Testing the decrease calls in the heap", "[single-file]" )
{	
	SECTION( "Testing the decrease, case one" )
	{
		//200 45 100 2 remmin
		
		FibonacciHeapDS f;
		f.insertBeforeStart(200);	
		f.insertBeforeStart(45);
		f.insertBeforeStart(100);
		f.insertBeforeStart(2);
		FibonacciHeapNode * minNode = f.deleteMinInterface(); //2
		delete minNode;
		
		FibonacciHeapNode *startNode = f.getStartNode();
		minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 45);
		
		REQUIRE (startNode->data == 200);
		REQUIRE (startNode->next->data == 45);
		REQUIRE (startNode->next->next->data == 200);
		
		REQUIRE (startNode->next->children->data == 100);
		REQUIRE (startNode->next->children->next->data == 100);
		
		bool ret = f.decrementKey(100, 2);
		REQUIRE (ret);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 45);
		
		REQUIRE (startNode->data == 200);
		REQUIRE (startNode->next->data == 45);
		REQUIRE (startNode->next->next->data == 200);
		
		REQUIRE (startNode->next->children->data == 98);
		REQUIRE (startNode->next->children->next->data == 98);
	}
	
	SECTION( "Testing the decrease, case two" )
	{
		//200 45 100 2 remmin
		
		FibonacciHeapDS f;
		f.insertBeforeStart(200);	
		f.insertBeforeStart(45);
		f.insertBeforeStart(100);
		f.insertBeforeStart(2);
		FibonacciHeapNode * minNode = f.deleteMinInterface(); //2
		delete minNode;
		
		FibonacciHeapNode *startNode = f.getStartNode();
		minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 45);
		
		REQUIRE (startNode->data == 200);
		REQUIRE (startNode->next->data == 45);
		REQUIRE (startNode->next->next->data == 200);
		
		REQUIRE (startNode->next->children->data == 100);
		REQUIRE (startNode->next->children->next->data == 100);
		
		bool ret = f.decrementKey(100, 2);
		REQUIRE (ret);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 45);
		
		REQUIRE (startNode->data == 200);
		REQUIRE (startNode->next->data == 45);
		REQUIRE (startNode->next->next->data == 200);
		
		REQUIRE (startNode->next->children->data == 98);
		REQUIRE (startNode->next->children->next->data == 98);
		
		ret = f.decrementKey(98, 97);
		REQUIRE (ret);
		
		startNode = f.getStartNode();
		minNode = f.getMinNode();
		
		REQUIRE (startNode->data == 200);
		REQUIRE (minNode->data == 1);
		
		REQUIRE (startNode->data == 200);
		REQUIRE (startNode->next->data == 45);
		REQUIRE (startNode->next->next->data == 1);
		REQUIRE (startNode->next->next->next->data == 200);
	}
	
}

TEST_CASE( "Testing the search calls in the heap", "[single-file]" )
{	
	SECTION( "search calls" )
	{	
		FibonacciHeapDS f;
		f.insertBeforeStart(50);	
		f.insertBeforeStart(100);
		f.insertBeforeStart(75);
		f.insertBeforeStart(200);
		
		REQUIRE (f.search(50) != nullptr);
		REQUIRE (f.search(100) != nullptr);
		REQUIRE (f.search(75) != nullptr);
		REQUIRE (f.search(200) != nullptr);
		
		REQUIRE (f.search(10) == nullptr);
	}
}
