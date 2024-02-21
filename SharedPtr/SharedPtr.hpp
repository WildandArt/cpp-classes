#ifndef ARTOZERSKY_SHAREDPTR_HPP
#define ARTOZERSKY_SHAREDPTR_HPP

#include <new>   //std::bad_alloc
#include <iosfwd>//ostream istream

namespace artozersky
{

/****************************************************************/
template <class T>
class SharedPtr
{
    public:
    struct Pimpl
    {
        explicit Pimpl(T* p, size_t c = 1):pointee(p), counter(c)
        {
            //empty
        }
        ~Pimpl()
        {
            delete pointee;
            pointee = nullptr;
        }
        T *pointee;
        size_t counter;

    };

    explicit SharedPtr(T* p = nullptr): p_impl(new Pimpl(p))
    {
        //empty
    }
    ~SharedPtr();
    SharedPtr(const SharedPtr<T>& other);
    size_t GetCounter() const;
    SharedPtr<T>& operator=(const SharedPtr<T>& other);
    T& operator*() const;
    T* operator->() const;



    Pimpl *GetPimpl() const
    {
        return p_impl;
    }

    template <typename U>
    SharedPtr(const SharedPtr<U> &other) noexcept
    {
        p_impl = other.GetPimpl();
        ++p_impl->counter;
    }

    template <typename U>
    SharedPtr<T> &operator=(const SharedPtr<U> &other) noexcept
    {
        if(this != (void*)(&other))
        {
            if(--p_impl->counter == 0)
            {
                delete p_impl;
                p_impl = nullptr;
            }
            p_impl = other.GetPimpl();
            ++p_impl->counter;
        }
        return *this;
    }

    private:
        Pimpl *p_impl;
        template <typename U>
        friend class SharedPtr;
    
};
/****************************************************************/
template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
    if(this != &other)
    {
        if(--p_impl->counter == 0)
        {
            delete p_impl;
            p_impl = nullptr;
        }
        p_impl = other.p_impl;
        ++p_impl->counter;
    }
    return *this;
}
/****************************************************************/
template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
    p_impl = other.p_impl;
    ++(p_impl->counter);
}

/****************************************************************/
template <class T>
SharedPtr<T>::~SharedPtr()
{
    if(--p_impl->counter == 0)
    {
        delete p_impl;
    }
}
/****************************************************************/
template <class T>
T& SharedPtr<T>::operator*() const
{
    return *(p_impl->pointee);
}
/****************************************************************/
template <class T>
T* SharedPtr<T>::operator->() const
{
    return (p_impl->pointee);
}   
/****************************************************************/

template <class T>
size_t SharedPtr<T>::GetCounter() const
{
    return p_impl->counter;
}
/****************************************************************/
} // artozersky

#endif /* ARTOZERSKY_SHAREDPTR_HPP*/