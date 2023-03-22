#include <iostream>


//
//class A
//{
//public:
//	int d;
//
//	~A()
//	{
//		std::cout << "1";
//	}
//};



int main()
{
	size_t std = sizeof(int);
	//std::cout << std;
	int* ptr = new int[100];

	delete[] ptr;


	// Work with class A
	/*A* ptr2 = new A[100];
	int* nCo = (int*)((char*)ptr2 - sizeof(void*));
	std::cout << *nCo;
	delete ptr2;*/

	int* stuff = new int();
	std::cout << stuff << std::endl;

	std::cout << *stuff << std::endl;
	delete stuff;

}