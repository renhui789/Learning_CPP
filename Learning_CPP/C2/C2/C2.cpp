
#include <iostream>
#include "func.h"
#include "left_right_value.h"

int main()
{
    std::cout << "Hello World!\n";

	//x是左值 10是右值
    int x = 10;

    //v是左值
	std::vector<int> v{ 1,2,3,4,5 };


	//现代C++变量初始化 ：函数初始化适用函数返回值，不建议适用函数出参去构造
	auto temp1 = func();		//局部变量返回值优化
	std::vector<int> temp2; 
	func2(temp2);	//通过左值引用传递修改参数

    //左值传递
    func1(v);

	//左值引用传递
	func2(v);

	//左值常量引用传递
    func3(v);

	//右值引用传递
	func4(func1(v));		//函数返回值是右值 匿名变量
	func4(std::move(v));   //std::move(v)是右值  左值转换右值
}
