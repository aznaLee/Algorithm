// LinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LinkedNode.h"
#include "Stack.h"
#include "Queue.h"

int _tmain(int argc, _TCHAR* argv[])
{

	// Linked List
	/*CLinkedNode<int>* pRootNode = new CLinkedNode<int>("RootNode", 0);
	CLinkedNode<int>* pNNode = pRootNode;

	for (int i = 1; i < 10; i++)
	{
		CLinkedNode<int>* pNode = new CLinkedNode<int>("", i, pNNode);
		pNNode = pNode;
	}

	pRootNode->AllPrint();

	system("pause");

	delete pRootNode;*/

	// Stack
	/*CLinkedNode<int>* pRootNode = new CLinkedNode<int>("RootNode", 0);

	CStack<int>* pStack = new CStack<int>(pRootNode);

	for (int i = 1; i < 10; i++)
	{
	CLinkedNode<int>* pNode = new CLinkedNode<int>("", i);
	pStack->Push(pNode);
	}

	pStack->Pop();
	pStack->Pop();

	system("pause");

	delete pStack;*/

	//Queue
	CLinkedNode<int>* pRootNode = new CLinkedNode<int>("RootNode", 0);

	CQueue<int>* pQueue = new CQueue<int>(pRootNode);

	for (int i = 1; i < 10; i++)
	{
		CLinkedNode<int>* pNode = new CLinkedNode<int>("", i);
		pQueue->Push(pNode);
	}

	pQueue->Pop();
	pQueue->Pop();

	system("pause");

	delete pQueue;

	return 0;
}

