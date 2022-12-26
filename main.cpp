#include <bits\stdc++.h>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;
int main(){
    MAVector<int> first(5);   //Basic Constructor of Capacity 5.
    //===================================================================
    for (int i = 0 ;i<6;i++)
    {
        first.push_back(i+1); // pushing back 6 elements in a vector with capacity 5.
    }
    //===================================================================
    MAVector<int> second (first);     //copy constructor.
    //===================================================================
    int array[5] ={6,7,8,9,10} ;  //array of 5 elements.
   MAVector<int> third (array, 5);     //filing vector with the array.
    //===================================================================
    cout<<"First MAVector:\n";
    for (int i =0;i<first.capacity();i++)
        cout<<first[i]<<" ";    //Print elements in first constructor using access operator.
    cout<<endl;
    cout<<"With Capacity:\t"<<first.capacity()<<endl;     // Return current capacity of vec
    cout<<"With Size:\t"<<first.size()<<endl;     // Return current size of vec
    //===================================================================
    cout<<"Second MAVector:\n";
    for (int i =0;i<second.capacity();i++)
        cout<<second[i]<<" ";   //Print elements in second constructor using access operator.
    cout<<endl;
    cout<<"With Capacity:\t"<<second.capacity()<<endl;     // Return current capacity of vec
    cout<<"With Size:\t"<<second.size()<<endl;     // Return current size of vec
    //===================================================================
    cout<<"Third MAVector:\n";
    for (int i =0;i<third.capacity();i++)
        cout<<third[i]<<" ";   //Print elements in second constructor using access operator.
    cout<<endl;
    cout<<"With Capacity:\t"<<third.capacity()<<endl;     // Return current capacity of vec
    cout<<"With Size:\t"<<third.size()<<endl;     // Return current size of vec
    //===================================================================
    // Comparing Vectors:
    // Comparing between first and second vector.
    if(first==second)
    {
        cout<<"First vector == Second vector\n";
    }
    else if (!(first==second))
    {
        cout<<"First vector != Second vector\n";
        if (first<second)
        {
            cout<<"First vector < Second vector\n";
        }
        else
        {
            cout<<"First vector > Second vector\n";
        }
    }
    // Comparing between first and third vector.
    if(first == third)
    {
        cout<<"First vector == third vector\n";
    }
    else if (!(first==third))
    {
        cout<<"First vector != Third vector\n";
        if (first<third)
        {
            cout<<"First vector < Third vector\n";
        }
        else
        {
            cout<<"First vector > Third vector\n";
        }
    }
    //===================================================================
    third.resize(4);    //resizing vector to be with size of 4  //we will use friend ostream when it's done.
    cout<<"MAVector after resizing it:\n";
    cout<<third;
    cout<<endl;
    //===================================================================
    MAVector<char>test(5);
    for (int i =0 ; i<5 ;i++)
    {
        test.push_back('A'+i);  //Filling MAVector.
    }
    cout<<"MAVector of type char :\n";
    cout<<test;
    cout << endl;
    test.clear();       //empty vector.
    // Using function empty to check whether the function is empty or not.
    (test.empty())?cout<<"This vector is empty\n":cout<<"This vector is not empty\n";    //empty
    cout<<test;
    cout<<endl;
    test.push_back('A');
    (test.empty())?cout<<"This vector is empty\n":cout<<"This vector is not empty\n";    //not empty.
    cout<<test;
    cout<<endl;
    //===================================================================
    cout << "elements before pop_back:\n";
    cout<<first;
    cout<<endl;
    cout<<"The last element in vector which removed:\n";
    cout<<first.pop_back()<<endl;      //Remove and return last element in vec
    cout << "elements after pop_back:\n";
    cout<<first;
    cout<<endl;
    first.push_back(6);     //returning the element to the vector.
    cout << "elements after push_back:\n";
    cout<<first;
    cout<<endl;
    //===================================================================
    cout << "Using Iterators to display first vector:\n";
    for (int & it : first)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    MAVector<int> :: Iterator it3 = first.begin();
    first.erase(it3);   //erasing first element
    cout<<"First vector after erasing first element :\n";
    cout<<first<<endl;
    MAVector<int> :: Iterator it1 = first.begin();
    MAVector<int> :: Iterator it2 = first.begin()+2;
    first.erase(it1,it2);   //erasing first two elements
    cout<<"First vector after erasing first three elements :\n";
    cout<<first<<endl;
    MAVector<int> :: Iterator it4 = first.begin();
    first.insert(it4,10);   //inserting 10 in the beginning
    cout<<"First vector after inserting 10 in the beginning of it:\n";
    cout<<first<<endl;
    cout<<first[-1];
}
