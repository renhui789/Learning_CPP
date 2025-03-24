#pragma once
#include<vector>
#include<string>

//内置指针，动态分配，释放
void on_New_Delete_Use()
{
	//new动态分配内存和初始化对象
	int* pi = new int(1024);
	std::string* strName = new std::string("lihua");
	delete pi;
	pi = nullptr;
	delete strName;
	strName = nullptr;

	//动态分配的const对象
	const int* pci = new const int(1024);
	const std::string* strNamme = new const std::string("lihua");
	delete pci;
	pci = nullptr;
	delete strNamme;
	strNamme = nullptr;

	//内存耗尽,分配失败，阻止抛出异常
	int* p1 = new int();
	//int* p2 = new (std::nothrow)int;
}

std::vector<int*> onproduce()
{
	return  std::vector<int*>();
}