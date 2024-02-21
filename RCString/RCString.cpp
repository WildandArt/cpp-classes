#include "RCString.hpp"
#include <cstring> // strlen, strcmp
#include <iostream> //cout, endl
/***********************************************************************************/
char* artozersky::InitStr(const char* original)
{
    size_t len = (std::strlen(original) + 1);
    char *new_copy = new char[len];
    memcpy(new_copy, original, len);
    return new_copy;
}
/***********************************************************************************/
artozersky::RCString::RCString(const char* str) : \
m_data(new StrCounter(str))
{
//empty
}
/******************************************************************************/
artozersky::RCString::RCString(const RCString& other)
{
    m_data = other.m_data;
    m_data->m_counter += 1;
}
/***********************************************************************************/
artozersky::RCString& artozersky::RCString::operator=(const RCString& other)
{
    if(0 == (--m_data->m_counter))
    {
        delete m_data;
    }
    m_data = other.m_data;
    m_data->m_counter += 1;

    return *this;
}
/***********************************************************************************/
const size_t& artozersky::RCString::GetCounter() const
{
    return this->m_data->m_counter;
}
/***********************************************************************************/

artozersky::RCString::~RCString()
{
    if(--(m_data->m_counter) == 0)
    {
        delete [] (m_data->m_str);
        m_data->m_str = nullptr;
        delete m_data;
    }
    
}
/***********************************************************************************/
const char& artozersky::RCString::operator[](size_t position) const
{
    return m_data->m_str[position];
}
// /***********************************************************************************/
char& artozersky::RCString::operator[](size_t position)
{
    if(1 < m_data->m_counter)
    {
        --(m_data->m_counter);
        m_data = new StrCounter(m_data->m_str);
    }
    return m_data->m_str[position];
}
/***********************************************************************************/
const char*  artozersky::RCString::GetStr() const
{
    return m_data->m_str;
}
/***********************************************************************************/
bool artozersky::operator==(const RCString& lhs, const RCString& rhs)
{
    return (strcmp(lhs.GetStr(), rhs.GetStr()) == 0);
}
bool artozersky::operator!=(const RCString& lhs, const RCString& rhs)
{
    return !(lhs == rhs);
}
bool artozersky::operator>(const RCString& lhs, const RCString& rhs)
{
    return (strcmp(lhs.GetStr(), rhs.GetStr()) > 0);
}
bool artozersky::operator<(const RCString& lhs, const RCString& rhs)
{
    return (strcmp(lhs.GetStr(), rhs.GetStr()) < 0);
}
/***********************************************************************************/




