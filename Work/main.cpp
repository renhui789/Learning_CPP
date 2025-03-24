#include <iostream>
#include "ptr.h"

int main()
{
	strBlob A({ "A","B","C" });
	strBlob B({ "D","E","F" });

	//智能指针交换
	std::shared_ptr<int> p = std::make_shared<int>(10);
	std::shared_ptr<int> q = std::make_shared<int>(20);
	p.swap(q);
	std::cout << *p << std::endl;

	//智能指针拷贝，计数，解引用
	std::shared_ptr<int> e = std::make_shared<int>(20);
	std::shared_ptr<int> f;
	f = e;
	std::cout << e.use_count() << std::endl;

	system("pause");
	return 0;
}