#ifndef ARTOZERSKY_LOCK_HPP
#define ARTOZERSKY_LOCK_HPP

#include <new>   //std::bad_alloc
#include <iosfwd>//ostream istream
#include <mutex>//mutex
#include <boost/noncopyable.hpp>//noncopyable
/*
The Scoped Locking C++ idiom ensures that a lock is acquired when
control enters a scope and the lock is released automatically when
control leaves the scope.
*/

namespace artozersky
{

class Lock : private boost::noncopyable 
{
    public:
        Lock(std::mutex& m) : m_mutex(m)
        {
           m_mutex.lock();
        }
        ~Lock() noexcept
        {
            m_mutex.unlock();
        }
    private:
        std::mutex &m_mutex;

};
    
} // artozersky

#endif /* ARTOZERSKY_LOCK_HPP*/