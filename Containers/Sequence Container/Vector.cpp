/*
Vector :-
*********
-Vector STL Conatiner is Used to Stored Object or Data
-it is also called as dynamic Array because Is It Stored Element In cotineous Memory like Array
-sizeof() empty vector is zero
Method
******
1)push_back()
2)pop_back()
3)size()
4)capacity()//return actual capacity of vector
5)clear()//clear vector all elements
6)at()//

*/

#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    std::vector<int>vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    int iSize = vec.size();
    cout<<"size of vector is :- "<<iSize<<endl;
    int iCounter = 0;
    for(;iCounter<iSize;iCounter++)
    {
        cout<<"vec["<<iCounter<<"]"<<vec[iCounter]<<"\t";
    }
    cout<<"\ncapacity of vector before pop is "<<vec.capacity()<<"\n";
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    cout<<"capacity of vector after pop is "<<vec.capacity()<<"\n";
    cout<<"\n";
    for(iCounter=0;iCounter<vec.size();iCounter++)
    {
        cout<<"vec["<<iCounter<<"]"<<vec[iCounter]<<"\t";
    }   
    
    iSize = vec.max_size();
    cout<<"\n";
    for(iCounter=0;iCounter<vec.size();iCounter++)
    {
        cout<<vec.at(iCounter)<<"\t";
    }   

    return 0;
}