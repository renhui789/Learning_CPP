#pragma once
#include <vector>


//左值右值学习


//const左值引用是万能引用  能绑定左值 常量左值 右值
// 1. 绑 const 左值
const int cx = 5;
const int& ref1 = cx;  // ✅ 文章第一个例子

// 2. 绑普通左值
int x = 5;
const int& ref2 = x;   // ✅ 文章第二个例子

// 3. 绑右值（字面量、临时对象）
const int& ref3 = 5;   // ✅ 文章第三个例子



//当前返回都是右值 临时变量
//左值传递  参数传递一个拷贝构造
std::vector<int>  func1(std::vector<int> v)
{
	auto v1 = v; //拷贝构造
	auto v2 = std::move(v); //移动构造
	//直接用v 没有构造发生

	std::vector<int> temp{ 1,2,3,4,5 };
	return temp;
}

//左值引用传递
std::vector<int>  func2(std::vector<int>& v)
{
	auto& v1 = v; //引用
	auto v2 = v; //拷贝构造

	std::vector<int> temp{ 1,2,3,4,5 };
	return temp;
}

//左值常量引用传递
std::vector<int>  func3(const std::vector<int>& v)
{
	auto& v1 = v; //引用
	auto v2 = v; //拷贝构造

	std::vector<int> temp{ 1,2,3,4,5 };
	return temp;
}

//右值引用传递
std::vector<int>  func4(std::vector<int>&& v)
{
	auto v1 = v; //拷贝构造
	auto v2 = std::move(v); //移动构造
	std::vector<int> temp{ 1,2,3,4,5 };
	return temp;
}
