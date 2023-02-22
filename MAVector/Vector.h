//
// Created by dell on 12/10/2022.
//
#include "bits/stdc++.h"
using namespace std;
#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

template <typename T>
class MAVector {
int Size;
int Capacity;
T* arr;
//===================================================================
public:
    typedef T* Iterator;
    // Constructors and Big 4
    explicit MAVector(int n);  // Initialize by specific capacity
    MAVector (T* array, int  n );   // Initialize by n items from array
    MAVector (const MAVector& AnotherVector);   // Initialize with it1 copy
    MAVector &operator=(const MAVector& anotherVector);   // Copy assignment
    MAVector &operator=(const MAVector&&anotherVector);  // Move assignment
    ~MAVector();      //destructor.
    //===================================================================
    // Access operations
    T& operator[](int index);   // Access item by reference
    //===================================================================
    // Modifying operations
    int push_back(T item);
    T pop_back();
    void erase(Iterator it) {
        try{
        if (it < begin() or it == end()) {
            throw ("Out of index\n");
        }
        else {
            T *New_array = new T[Capacity];
            int ind;
            for (int i = 0; i < Capacity; i++) {
                New_array[i] = '\0';
            }
            for (int j = 0; j < Size; j++) {
                if (arr[j] == *it) {
                    ind = j;
                    break;
                } else {
                    New_array[j] == arr[j];
                }
            }
            Size--;
            for (int j = ind; j < Size; j++) {
                New_array[j] = arr[j + 1];
            }
            delete[] arr;
            arr = New_array;
        }
    }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }     // Remove item at iterator
    void erase(Iterator it1,Iterator it2)
    {
        try {
            if ((((it1 < begin() or it1 >= end()) or (it2 >= end() or it2 < begin()))) or (it1 > it2)) {
                throw "out of range iterator";
            }
            else {
                T *New_array = new T[Capacity];
                for (int i = 0; i < Capacity; i++)
                {
                    New_array[i] = '\0';
                }
                for (auto i = begin(); i != it1; i++) {
                    New_array[i - begin()] = arr[i - begin()];
                }
                for (auto i = it2; i != end(); i++) {
                    New_array[i - begin() - (it2 - it1)] = arr[i - begin()];
                }
                delete[] arr;
                arr = New_array;
                Size -= (it2 - it1);
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }
    void insert(Iterator it , T item)
    {
        try {
            if (it < begin() or it == end()) {
                throw ("Out of index\n");
            } else {
                int ind;
                T *NewArr;
                if (Size == Capacity) {
                    NewArr = new T[Capacity * 2];
                    Capacity *= 2;
                }
                else
                {
                    NewArr = new T [Capacity];
                }
                for (int i = 0; i < Capacity; i++) {
                    NewArr[i] = '\0';
                }
                for (int i =0;i<Size;i++)
                    {
                        if (arr[i]==*it)
                        {
                            NewArr[i]=item;
                            NewArr[i+1] = arr[i];
                            ind=i+2;
                            break;
                        }
                        else
                        {
                            NewArr[i] = arr[i];
                        }
                    }
                Size++;
                for (int i=ind;i<Size;i++)
                {
                    NewArr[i]=arr[i-1];
                }
                delete[] arr;
                arr = NewArr;
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    void clear();
    //===================================================================
    // Iterators 		// Supports *, + and ++ operations at least
    Iterator begin(){
        return arr;
    };	// Return an iterator (T*)
    Iterator end(){
        return arr+Size;
    };	    // Return an iterator (T*)
    //===================================================================
    // Capacity operations
    int size() const ;   // Return current size of vec
    int capacity() const;   // Return current capacity of vec
    void resize(int newSize);       // Relocate to bigger space
    bool empty();       // Return true if size is 0
    //===================================================================
    // Comparison operations
    bool operator==(const MAVector<T>& AnotherVec);   // Return true if ==
    bool operator<(const MAVector<T>& AnotherVec);    // Compares item by item
    //===================================================================
    // Friends
      friend ostream &operator << (ostream &out, MAVector<T> anotherVector)
    {
        for (int i =0 ; i < anotherVector.size() ; i++)
        {
            out << anotherVector.arr[i]<<" ";
        }
        return out;
    }
};




#endif //VECTOR_VECTOR_H
