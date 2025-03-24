#include "ptr.h"

strBlob::strBlob()
{
	m_pData = std::make_shared<std::vector<std::string>>();
}

strBlob::strBlob(std::initializer_list<std::string> il)
{
	m_pData = std::make_shared<std::vector<std::string>>(il);
}

strBlob::~strBlob()
{
}

size_type strBlob::onGetSize() const
{
	return m_pData->size();
}

bool strBlob::onEmpty() const
{
	return m_pData->empty();
}

void strBlob::onPush_back(const std::string& strObject)
{
	m_pData->push_back(strObject);
}

void strBlob::onPop_back()
{
	onCheck(0, "pop_back on empty strBlob");
	m_pData->pop_back();
}

const std::string& strBlob::onFront() const
{
	onCheck(0, "front on empty strBlob");
	return m_pData->front();
}

const std::string& strBlob::onBack() const
{
	onCheck(0, "back on empty strBlob");
	return m_pData->back();
}

void strBlob::onCheck(size_type i, const std::string& strMsg) const
{
	if (i >= m_pData->size())
		throw _Deref_out_range_(strMsg);
}