#pragma once

#include<memory>
#include<vector>
#include<string>

typedef std::vector<std::string>::size_type size_type;
class strBlob
{
public:

	strBlob();
	strBlob(std::initializer_list<std::string> il);
	~strBlob();

	//获取数组数量
	size_type onGetSize() const;

	//判断是否为空
	bool onEmpty() const;

	//添加元素
	void onPush_back(const std::string& strObject);

	//删除元素
	void onPop_back();

	//元素访问
	const std::string& onFront() const;
	const std::string& onBack() const;

private:
	std::shared_ptr<std::vector<std::string>>  m_pData;//数组智能指针

	//判断m_pData[i]是否合法
	void onCheck(size_type i, const std::string& strMsg) const;
};