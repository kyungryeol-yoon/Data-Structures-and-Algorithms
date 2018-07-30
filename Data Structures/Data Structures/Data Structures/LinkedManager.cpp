#include "LinkedManager.h"

CLinkedManager* CLinkedManager::m_pInstance = NULL;

CLinkedManager::CLinkedManager() : m_Menu(0)
{
	Single = new CSLL;
	Double = new CDLL;
}


CLinkedManager::~CLinkedManager()
{
	delete Single;
	delete Double;
}

void CLinkedManager::SingleRun()
{
	while (true)
	{
		std::cout << "1.추가 2.삭제 3.출력 4.전체삭제 5.노드 총 갯수 6.찾기\n입력 : ";
		std::cin >> m_Menu;

		switch (m_Menu)
		{
		case INSERT:
			break;
		case DEL:
			break;
		case PRINT:
			break;
		case ALL_DEL:
			break;
		default:
			break;
		}
	}
}

void CLinkedManager::DoubleRun()
{
	while (true)
	{
		std::cout << "1.추가 2.삭제 3.출력 4.전체삭제 5.노드 총 갯수\n6.찾기 7.버블정렬 8.삽입정렬 9.퀵정렬 10.링크드 뒤집기\n입력 : ";
		std::cin >> m_Menu;

		switch (m_Menu)
		{
		case INSERT:
			break;
		case DEL:
			break;
		case PRINT:
			break;
		case ALL_DEL:
			break;
		default:
			break;
		}
	}
}
