#include "LinkedManager.h"

void main() {
	int menu = 0;

	std::cout << "자료구조를 선택하시겠습니까?" << std::endl << std::endl;
	std::cout << "1.싱글링크드리스트\n2.더블링크드리스트\n3.스택\n4.큐\n5.트리\n\n입력 : ";
	std::cin >> menu;

	switch (menu)
	{ 
	case CHOICELINDED::SLL:
		std::cout << "\nSingle Liked List" << std::endl;
		CLinkedManager::GetInstance()->SingleRun();
		break;
	case CHOICELINDED::DLL:
		std::cout << "\nDouble Liked List" << std::endl;
		CLinkedManager::GetInstance()->DoubleRun();
		break;
	default:
		break;
	}
}