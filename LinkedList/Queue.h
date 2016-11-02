#pragma once
#include "LinkedNode.h"

template<typename T>
class CQueue
{
private:
	CLinkedNode<T>* m_pRoot;
	CLinkedNode<T>* m_pLast;

public:
	void Push(CLinkedNode<T>* pNode)
	{
		if (!m_pRoot)
			m_pRoot = pNode;

		if (m_pLast)
		{
			m_pLast->SetNextNode(pNode);
			pNode->SetPrevNode(m_pLast);
		}

		m_pLast = pNode;
		pNode->SetType(QUEUE);
	}

	void Pop()
	{
		CLinkedNode<T>* pPopNode = m_pRoot;
		m_pRoot = m_pRoot->GetNextNode();
		T tData = pPopNode->GetData();

		delete pPopNode;

		cout << tData << "   ";
	}

public:
	CQueue()
	{
		m_pRoot = NULL;
		m_pLast = NULL;
	}

	CQueue(CLinkedNode<T>* pRoot)
	{
		m_pRoot = pRoot;
		m_pLast = pRoot;
		pRoot->SetType(QUEUE);
	}

	~CQueue()
	{
		if (m_pRoot)
			SAFE_DELETE(m_pRoot);
	}
};

