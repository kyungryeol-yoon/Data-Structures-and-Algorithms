#pragma once
#include "DLL.h"
#include "SLL.h"
#include "GlobalHeader.h"

class CLinkedManager
{
private:
	int m_Menu;

	CSLL* Single;
	CDLL* Double;

	static CLinkedManager* m_pInstance;
private:
	CLinkedManager();
public:
	~CLinkedManager();
public:
	static CLinkedManager* GetInstance() {
		if (m_pInstance == NULL) {
			m_pInstance = new CLinkedManager;
		}
		return m_pInstance;
	}
public:
	void SingleRun();
	void DoubleRun();
};

