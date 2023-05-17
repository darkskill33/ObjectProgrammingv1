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

    vectorclass<T>& operator=(const vectorclass& other) { ///copy assignment
        if(this != &other)
        {
            capacity = other.capacity;
            size = other.size;
            other.array = new T[other.capacity];
            array = other.array;
            delete [] array;
        }
        return *this;
    }

    std::allocator<T> get_allocator() const
    {
        return std::allocator<T>();
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

    T& front(size_t index)
    {
        return array[0];
    }

    T& back(size_t index)
    {
        return array[size-1];
    }


    bool empty() const 
    {
        return size == 0;
    }

    int size_()
    {
        return size;
    }

    int max_size()
    {
        return std::numeric_limits<int>::max();
    } 

    int capacity_()
    {
        return capacity;
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
        if(capacity == place)
        {
            push_back(x);
        } else
            {
                for(int i = size - 1; i >= place; --i)
                {
                    array[i + 1] = array[i];
                }
                array[place] = place;
                size+=1;
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
     void push_back(T x, int index)
    {
        if (index == capacity)
        {
            push_back(x);
        } else
            array[index] = x;
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
        cout << endl;
    }
};

#endif