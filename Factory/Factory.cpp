#include <iostream>

class Camera
{
};

class Plain
{
};

class Node
{
};

void * Make()

void* Create(const std::string& stype)
{
	if (stype == "Camera")
	{
		return new Camera();
	}
	if (i == type::Pla)
	{
		return new Plain();
	}
	if (i == 2)
	{
		return new Node();
	}
	return nullptr;
}

class Factory
{
public:

	using typeFunc = void* (*)();
	static void Add(const std::string& key, typeFunc value)
	{

	}

	void* Create(const std::string& key)
	{
		decltype(types)
	}
protected:
	
};



int main()
{
	using typeFunc = void* (*)();
	Plain pn = (Plain*)Create("Plane");


    std::cout << "Hello World!\n";
}
