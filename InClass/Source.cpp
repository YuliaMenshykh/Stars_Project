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



//class Functor
//{
//public:
//	Functor(int& a) : a(a)
//	{
//
//	}
//	void operator()()
//	{
//		std::cout << a;
//	}
//
//	
//
//	int a;
//};



void bar(int a)
{
	std::cout << a;
}


struct Bit
{
	union
	{
		int a;

		struct 
		{
			int bit1 : 1;
			int bit2 : 1;

		};
	};
};


enum class Format : int
{
	Position = 1 << 0,
	Normal = 1<<1,
	Tangent = 1<<2,
	Texture = 1<<3

};
Format operator|=(Format a, Format b)
{
	return(Format)((int)a | (int)b);
}
int main()
{
	Format f = Format::Position;
	f |= Format::Tangent;



	Bit b;
	b.a = 0;

	b.bit1 = 1;

	b.bit2 = 1;
	if (b.bit1 == 1)
	{
		int dd = 23;
	}

	//size_t std = sizeof(int);
	////std::cout << std;
	//int* ptr = new int[100];

	//delete[] ptr;


	// Work with class A
	/*A* ptr2 = new A[100];
	int* nCo = (int*)((char*)ptr2 - sizeof(void*));
	std::cout << *nCo;
	delete ptr2;*/

	//int* stuff = new int();
	//std::cout << stuff << std::endl;

	//std::cout << *stuff << std::endl;
	//delete stuff;

	

	//second
	//int a = 776;
	//auto lambda = [a]() {std::cout << a;};

	//Functor f(a);
	
}