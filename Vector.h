#pragma once
#include <algorithm>
#include <iostream>
using namespace std;
template <class type>
class Vector
{
    public:
        Vector(){size_ = 0;capacity_ = 0; stlstart = NULL;}
        explicit Vector(unsigned int n){stlstart = new type[n]; size_ = n; capacity_ = n;}

        Vector(std::initializer_list<type> _list) : size_(_list.size()), capacity_(_list.size()), stlstart(new type[_list.size()]) { cout << "initializerlist";std::copy(_list.begin(), _list.end(), stlstart); }

        Vector(const Vector<type>& v) : stlstart{new type[v.size_]}, size_{v.size_}, capacity_{v.capacity_} {
        std::copy(v.begin(), v.back(), (*this).begin());}

        Vector(Vector&& v) noexcept : size_{v.size_}, capacity_{v.capacity_} , stlstart{v.stlstart} {v.stlstart = nullptr; v.size_=0; v.capacity_=0;}
        ~Vector(){if(capacity_!=0){delete[] stlstart;}}

    typedef typename allocator<type>::pointer iterator;
    typedef typename allocator<type>::pointer const_iterator;
    typedef typename allocator<type>::reference reference;
    typedef typename allocator<type>::const_reference const_reference;
    typedef typename allocator<type>::value_type value_type;
    reference operator [] (unsigned int n){return *(stlstart+n);}
    const_reference operator [](unsigned int n)const{return *(stlstart+n);}
    Vector<type>& operator=(const Vector<type>& v) {
        if (&v == this) return *this;
        type* newElem = new type[v.size_];
        std::copy(v.begin(), v.back(), &newElem[0]);
        if(capacity_!=0)
        {
        delete[] stlstart;
        }
        stlstart = v.stlstart;
        size_ = v.size_;
        capacity_ = v.capacity_;
        return *this;
    };
    Vector<type>& operator=(Vector<type>&& v) noexcept {
        cout << "move op"<<endl;

        if( &v == this)
            return *this;
        if(capacity_!=0)
        {
        delete[] stlstart;
        }
        stlstart = v.stlstart;
        size_ = v.size_;
        capacity_ = v.capacity_;
        v.stlstart = nullptr;
        v.size_ = 0;
        v.capacity_ = 0;
        return *this;
    };
    void push_back(const_reference sth)
    {
        if(capacity_ == size_)
        {
            capacity_ = 2*size_+2;
            type * temp = new type[capacity_];
            for(int x = 0; x < size_; ++x)
            {
                temp[x] = stlstart[x];
            }
            if(size_!=0)
            {
                delete[] stlstart;
            }
            stlstart= temp;
        }
        //cout << "size: " << size_;
        stlstart[size_] = sth;
        ++size_;
        //cout << "size2: " << size_<<endl;
    }
    unsigned int size() const
    {
        return size_;
    }
    unsigned int capacity() const
    {
        return capacity_;
    }
        iterator end()
        {
            return (stlstart+size_);
        }
        iterator end()const
        {
            return (stlstart+size_);
        }
        iterator begin()
        {
            return stlstart;
        }
        iterator begin()const
        {
            return stlstart;
        }
        iterator back()
        {
            return (stlstart+size_-1);
        }
        iterator back()const
        {
            return (stlstart+size_-1);
        }
        void swap(type& x, type& y)
        {
            type temp = x;
            x = y;
            y = temp;
        }
        void swap(iterator &x, iterator &y)
        {
            type * temp = x;
            x = y;
            y = temp;
        }
        void clear()
        {
            if(capacity_ != 0)
            {
                delete[] stlstart;
                capacity_ = 0;
            }
            size_ = 0;
        }
        void erase(iterator sth)
        {
            while(sth != stlstart+size_)
            {
                swap(*sth, *(sth+1));
                ++sth;
            }
            --size_;
        }
        void resize(unsigned int n)
        {
            if(n != capacity_)
            {
                type * temp = new type[n];
                if(n > size_)
                {
                    for(int x = 0; x < size_; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                }
                else
                {
                    for(int x = 0; x < n; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                }
                size_ = n;
                if(capacity_ != 0)
                {
                delete[] stlstart;
                }
                stlstart = temp;
                capacity_ = n;
            }

        }
        void reserve(unsigned int n)
        {
            if(n  > capacity_)
            {
                type * temp = new type[n];

                    for(int x = 0; x < size_; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                delete[] stlstart;
                stlstart = temp;
                capacity_ = n;
            }
        }
        void shrink_to_fit()
        {
            if(capacity_ > size_)
            {
                type * temp = new type[size_];
                    for(int x = 0; x < size_; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                delete[] stlstart;
                stlstart = temp;
                capacity_ = size_;
            }
        }
    private:
        iterator stlstart;
        unsigned int size_, capacity_;



};
