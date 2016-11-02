#pragma once

#include "value.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class CLinkedNode
{
private:
	T m_tData;
	string m_strTag;
	CLinkedNode* m_pNextNode;
	CLinkedNode* m_pPrevNode;
	ALGORITHM m_eType;
	bool m_bAllDelete;

public:
	void SetType(ALGORITHM eType)
	{
		m_eType = eType;
	}

	void SetDeleteType(bool bDelete)
	{
		m_bAllDelete = bDelete;
	}

	void SetNextNode(CLinkedNode* pNode)
	{
		m_pNextNode = pNode;
	}

	void SetPrevNode(CLinkedNode* pNode)
	{
		m_pPrevNode = pNode;
	}

	void SetAllNode(CLinkedNode* pNext, CLinkedNode* pPrev)
	{
		m_pNextNode = pNode;
		m_pPrevNode = pNode;
	}

	void AllPrint()
	{
		cout << m_tData << endl;

		if (m_pNextNode)
			m_pNextNode->Print();
	}

	T GetData()
	{
		return m_tData;
	}

	CLinkedNode<T>* GetPrevNode()
	{
		return m_pPrevNode;
	}

	CLinkedNode<T>* GetNextNode()
	{
		return m_pNextNode;
	}

public:
	CLinkedNode()
	{
		m_pNextNode = NULL;
		m_pPrevNode = NULL;
	}

	CLinkedNode(const string& strTag, T tData, CLinkedNode* pPrev = NULL)
	{
		m_strTag = strTag;
		m_tData = tData;

		m_pNextNode = NULL;
		m_pPrevNode = pPrev;

		if (m_pPrevNode)
			m_pPrevNode->SetNextNode(this);
	}

	~CLinkedNode()
	{
		switch (m_eType)
		{
		case LINKECLIST:
		case STACK:
		{
			if (m_pNextNode)
				SAFE_DELETE(m_pNextNode);

			if (m_pPrevNode)
				m_pPrevNode->SetNextNode(NULL);
		}
			break;
		case QUEUE:
		{
			if (m_pNextNode)
				m_pNextNode->SetPrevNode(NULL);
		}
			break;

		}
	}
};

