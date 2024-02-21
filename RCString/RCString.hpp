#ifndef ARTOZERSKY_RCSTRING_HPP
#define ARTOZERSKY_RCSTRING_HPP

#include <new>   //std::bad_alloc
#include <iosfwd>//ostream istream
#include <cstring> // strlen, strcmp

namespace artozersky
{


char* InitStr(const char* original);

class RCString
{
    public:

        RCString(const char *str = "default");
        RCString(const RCString& other);
        ~RCString();
        RCString& operator=(const RCString& other);

        const char* GetStr() const;
        const size_t& GetCounter() const;

        const char& operator[](size_t position) const;
        char& operator[](size_t position);
 
    private:

    struct StrCounter
    {
        char *m_str;
        size_t m_counter;
        StrCounter(const char *str = "default", size_t counter = 1) \
        : m_str(InitStr(str)), m_counter(counter)
        {
        //empty
        }
        ~StrCounter()
        {
            delete [] m_str;
            m_str = nullptr;
        }

    };
        StrCounter *m_data;

};


bool operator==(const RCString& lhs, const RCString& rhs);
bool operator!=(const RCString& lhs, const RCString& rhs);
bool operator>(const RCString& lhs, const RCString& rhs);
bool operator<(const RCString& lhs, const RCString& rhs);

    
} // artozersky

#endif /* ARTOZERSKY_RCSTRING_HPP*/