#pragma once
#include "LinkedNode.h"

template<typename T>
class CStack
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
	}

	void Pop()
	{
		CLinkedNode<T>* pPopNode = m_pLast;
		m_pLast = m_pLast->GetPrevNode();
		T tData = pPopNode->GetData();

		delete pPopNode;

		cout << tData << "   ";
	}


public:
	CStack()
	{
		m_pRoot = NULL;
		m_pLast = NULL;
	}

	CStack(CLinkedNode<T>* pRoot)
	{
		m_pRoot = pRoot;
		m_pLast = pRoot;
	}

	~CStack()
	{
		if (m_pRoot)
			SAFE_DELETE(m_pRoot);
	}
};

