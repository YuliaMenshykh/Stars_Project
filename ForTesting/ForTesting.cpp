#include <iostream>
#include <fstream>

int main()
{
	//txt
	std::ofstream outFile;

	outFile.open("CustomFile.mcf");
	outFile << "Hello" << std::endl;
	outFile.close();

	//binary
	std::fstream fout;
	unsigned short x =8675;
	fout.open("file.dat", std::ios::out| std::ios::binary);
	if (fout)
	{
		fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));
		fout.close();
	}
	else
	{
		std::cout << "Something went wrong"<<'\n';
	}
	fout.open("file.dat", std::ios::in | std::ios::binary);
	if (fout)
	{
		unsigned short y = 0;
		fout.read(reinterpret_cast<char*>(&y), sizeof(unsigned short));
		fout.close();
		std::cout << y << std::endl;
	}
	else
	{
		std::cout << "Something went wrong" << '\n';
	}
}