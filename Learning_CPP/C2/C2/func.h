#pragma once
#include <vector>


/*
C++函数

性能点：函数返回值优化


现代C++17以后编译器
函数返回值优化（Return Value Optimization，RVO）是一种编译器优化技术，旨在消除不必要的对象复制，从而提高程序性能。当一个函数返回一个对象时，编译器通常会创建一个临时对象来存储返回值，然后将其复制到调用者的变量中。RVO通过直接在调用者的内存位置构造返回值对象，避免了这个临时对象的创建和复制过程。

如何没有有RVO，函数返回一个对象时会经历以下步骤：
	1.函数内部会创建临时对象来存储返回值。
	2.临时对象会被复制到调用者的变量中。
	产生一次拷贝构造和一次析构，增加了性能开销。


	如果从语法角度 用std::move()去移动构造返回值是优化，但工程实践中C++11标准编译器规定隐式移动  所以手动std::move的场景基本被排除

*/

//RVO典型场景 局部变量返回值优化
std::vector<int>  func()
{
	std::vector<int> v{ 1,2,3,4,5 };
	return v;
}


//类成员变量返回
class A
{
public:

	std::vector<int> m_v;

	//移动构造返回成员变量，但类成员变量被清空了，后续访问会有问题
	std::vector<int>  func2()
	{
		std::vector<int> v{ 1,2,3,4,5 };
		m_v = std::move(v);
		return std::move(m_v);
	}

	//返回const引用 外部只读访问
	const std::vector<int>& func3()
	{
		std::vector<int> v{ 1,2,3,4,5 };
		m_v = std::move(v);
		return m_v;
	}

	//返回非常量引用 外部可读写访问
	std::vector<int>& func4()
	{
		std::vector<int> v{ 1,2,3,4,5 };
		m_v = std::move(v);
		return m_v;
	}
};