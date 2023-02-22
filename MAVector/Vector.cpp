#include "Vector.h"
using namespace std;
//===================================================================
// Constructors and Big 4
template<typename T>
MAVector<T>::MAVector(int n)
{
    Capacity=n;
    arr=new T[Capacity] ;
    for (int i=0;i<Capacity;i++)
    {
        arr[i]='\0';
    }
    Size =0;
}
//________________________________________________________________
template<typename T>
MAVector<T>::MAVector (const MAVector& AnotherVector)
{
    Size = AnotherVector.Size;
    Capacity = AnotherVector.Capacity;
    arr=new T [Capacity] ;
    for (int i =0 ; i<AnotherVector.Capacity;i++)
    {
        arr[i] = AnotherVector.arr[i];
    }
}
//________________________________________________________________
template<typename T>
MAVector<T>::MAVector (T* array, int  n )
{
    Capacity = n;
    Size = n;
    arr =new T [Capacity];
    for (int i=0;i<n;i++)
    {
        arr[i]= array [i];
    }
}
//________________________________________________________________
template<typename T>
MAVector<T> &MAVector<T>::operator=(const MAVector &anotherVector) {
    this->arr = anotherVector.arr;
    this->Size = anotherVector.Size;
    this -> Capacity = anotherVector.Capacity;
    return *this;
}
//________________________________________________________________
template<typename T>
MAVector<T> &MAVector<T>::operator=(const MAVector &&anotherVector){
    this->arr = anotherVector.arr;
    this->Size = anotherVector.Size;
    this -> Capacity = anotherVector.Capacity;
    return *this;
}
//________________________________________________________________
template <typename T>
MAVector<T>::~MAVector()
{
    delete []  arr;
};
//===================================================================
// Access operations
template<typename T>
T& MAVector<T>:: operator[](int index)
{
    try {
        if (index >= capacity() or index <0) {
            throw ("Index out of range ");
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
        exit(1);
    }
    return this->arr[index];
}
//===================================================================
// Modifying operations
template<typename T>
int MAVector<T> :: push_back(T item)
{
    if (Size < Capacity)
    {
        arr [Size++] = item;
    }
    else
    {
        Capacity *= 2;
        T* newArr = new T [capacity()];
        for (int i=0;i<Capacity;i++)
        {
            newArr[i]='\0';
        }
        for (int i = 0; i< Size ; i++)
        {
            newArr [i] = arr[i] ;
        }
        newArr [Size++] = item;
        delete[] arr;
        arr = newArr;
    }
    return this -> Size;
}
//________________________________________________________________
template<typename T>
T MAVector<T> :: pop_back()
{
    T value;
    try {
        if (Size == 0) {
            throw ("empty vector\n");
        } else {
            value = arr[Size - 1];
            arr[Size - 1] = '\0';
            Size--;
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
        exit(1);
    }
    return value;
}
//________________________________________________________________
template<typename T>
void MAVector<T>::clear()
{
    Size = 0;
    for (int i=0;i<Capacity;i++)
    {
        arr[i]='\0';
    }
}
//===================================================================
// Comparison operations
template<typename T>
bool MAVector<T> :: operator==(const MAVector<T>& AnotherVec)
{
    if (size() != AnotherVec.size())
    {
        return false;
    }
    for (int i =0 ;i < size(); i++)
    {
        if(arr[i] != AnotherVec.arr[i] )
        {
            return false;
        }
    }
    return true;
}
//________________________________________________________________
template<typename T>
bool MAVector<T> :: operator<(const MAVector<T>& AnotherVec)
{
    for (int i =0 ;i < size(); i++)
    {
        if(arr[i] < AnotherVec.arr[i] )
        {
            return true;
        }
    }
    return false;
}
//===================================================================
template<typename T>
int MAVector<T>::size()const
{
    return this -> Size;
}
//________________________________________________________________
template<typename T>
int MAVector<T> :: capacity() const
{
    return this -> Capacity;
}
//________________________________________________________________
template<typename T>
void MAVector<T>::resize(int newSize) {
    Size = newSize;
    for (int i =Size ; i<Capacity;i++)
    {
        arr[i]='\0';
    }
}
//________________________________________________________________
template<typename T>
bool MAVector<T> ::empty()
{
    return Size == 0 ;
}
//===================================================================
