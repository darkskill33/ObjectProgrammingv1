#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include "Mylib.h"

template <typename T> class vectorclass
{
    private:
        size_t capacity;
        size_t size;
        T* array;

    public: 
    using iterator = T*;
    using value_type = T;
    
    /// Member functions
    vectorclass() ///constructor
    {
        capacity = 1;
        size = 0;
        array = new T[capacity];
    }

    ~vectorclass() ///destructor
    {
        delete [] array;
    }

    vectorclass<T>& operator=(const vectorclass<T>& other) ///copy assignment
    { 
        if (this != &other)
        {
            capacity = other.capacity;
            size = other.size;
            delete[] array;
            array = new T[capacity];
            std::copy(other.array, other.array + other.size, array);
        }
        return *this;
    }


    std::allocator<T> get_allocator() const
    {
        return std::allocator<T>();
    }

    ///Iterator
    iterator begin() const 
    {
        return array;
    }

    iterator cbegin() const 
    {
        return array;
    }

    iterator end() 
    {
        return array + size;
    }

    iterator cend() 
    {
        return array + size;
    }

    ///Element Access

    T& at(int index)
    {
        if(index >= size || index < 0)
        {
            throw std::exception("Indes out of range!");
        }
        return array[index];
    }

    T& operator[](size_t index)
    {
        return array[index];
    } 

    T& front()
    {
        return array[0];
    }

    T& back()
    {
        return array[size - 1];
    }

    bool empty() const 
    {
        return size == 0;
    }

    size_t size_()
    {
        return size;
    }

    size_t capacity_()
    {
        return capacity;
    }

    size_t max_size()
    {
        return std::numeric_limits<size_t>::max();
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* temp = new T[new_capacity];
            std::copy(array, array + size, temp);
            delete[] array;
            array = temp;
            capacity = new_capacity;
        }
    }

    ///Modifiers
    void clear()
    {
        delete [] array;
        array = nullptr;
        size = 0;
        capacity = 0;
    }

    void insert(T x, size_t place)
    {
    if (size == place)
    {
        push_back(x);
    }
    else
        {
            for (int i = size - 1; i >= place; --i)
            {
                array[i + 1] = array[i];
            }
            array[place] = x;
            size += 1;
        }
    }


    void erase(size_t index)
    {
        for(int i = index; i < size - 1; ++i)
        {
            array[i] = array[i+1];
        }
        size--;
    }

    iterator erase(iterator first, iterator last) {
        size_t count = last - first;
        std::copy(last, end(), first);
        size -= count;
        return first;
    }

    void push_back(T x)
    {
        if(size == capacity) 
        {
            T* tmp = new T[capacity*2];
        
            for(int i = 0; i < capacity; i++) 
            {
                tmp[i] = array[i];
            }

            delete [] array;
            capacity = capacity*2;
            array = tmp;
        }

        array[size] = x;
        size++;
    }

    void push_back(T x, size_t index)
    {
        if (index == capacity)
        {
            push_back(x);
        }
        else
        {
            array[index] = x;
        }
    }


    void pop_back()
    {
        --size;
    }

    void resize(size_t newsize, const T& x)
    {
        if(newsize < size)
        {
            size = newsize;
        } else if(newsize > size)
                {
                    if(newsize > capacity)
                    {
                        reserve(newsize);
                    }   
                    std::fill(array + size, array + capacity, x);
                    size = newsize;
                }
    }

    void resize(size_t newsize)
    {
        resize(newsize, T());
    }

    void print()
    {
        for (int i = 0; i < size; i++) 
        {
            cout << array[i] << " ";
        }
        cout << std::endl;
    }

};

#endif