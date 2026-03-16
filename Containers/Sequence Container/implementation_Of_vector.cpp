/*
*/
#include<iostream>
using namespace std;

template<typename T>
class MyVector
{

private:
    T *iCapacityPtr;     //Acturla capacity
    T *iEndElementPtr;   //end Element
    T *iStartElementPtr; //first Element
public:
    MyVector()
    {
        iCapacityPtr     = nullptr;
        iEndElementPtr   = nullptr;
        iStartElementPtr = nullptr;
    }
    ~MyVector()//destructor
    {
        if(iStartElementPtr)
        {
          delete []iStartElementPtr ;
          iStartElementPtr = nullptr;
        }
    }

    MyVector(const MyVector &vecObj)//copy constructor
    {
		
		int icapacity = vecObj.iCapacityPtr - vecObj.iStartElementPtr;
		if(icapacity!=0)
		{
			int isize = vecObj.iEndElementPtr - vecObj.iStartElementPtr;
			int icounter = 0;

			iStartElementPtr = new T[icapacity];

			for(;icounter<isize;icounter++)
			{
				iStartElementPtr[icounter]=vecObj.iStartElementPtr[icounter];
			}

			iEndElementPtr   = iStartElementPtr + isize ;
			iCapacityPtr     = iStartElementPtr + icapacity;
		}
    }

    MyVector(MyVector &&vecObj)//copy constructor
    {
		iStartElementPtr = vecObj.iStartElementPtr;
		iEndElementPtr   = vecObj.iEndElementPtr;
		iCapacityPtr     = vecObj.iCapacityPtr;
    }

    void operator =(const MyVector &&vecObj)//copy assigment
    {
   		iStartElementPtr = vecObj.iStartElementPtr;
		iEndElementPtr   = vecObj.iEndElementPtr;
		iCapacityPtr     = vecObj.iCapacityPtr;     
    }

    void operator =(const MyVector &vecObj)//copy assigment
    {
		int icapacity = vecObj.iCapacityPtr - vecObj.iStartElementPtr;
		if(icapacity!=0)
		{
			int isize = vecObj.iEndElementPtr - vecObj.iStartElementPtr;
			int icounter = 0;

			iStartElementPtr = new T[icapacity];

			for(;icounter<isize;icounter++)
			{
				iStartElementPtr[icounter]=vecObj.iStartElementPtr[icounter];
			}

			iEndElementPtr   = iStartElementPtr + isize;
			iCapacityPtr     = iStartElementPtr + icapacity;
		}
    }

	T operator [](int iPos)
	{
		return iStartElementPtr[iPos];
	}
    void push_back(T iData)
    {
        if(iEndElementPtr == iCapacityPtr)
        {
            T *NewData = nullptr;
            int iCounter = 0;
            int iCapacity = 0;
            int iSize = size();
            iCapacity = capacity();
            
            if(iCapacity!=0)
            {
                iCapacity = iCapacity*2;
            }
            else
            {
                iCapacity = 1;
            }
            
            NewData = new T[iCapacity];

            for(iCounter = 0;iCounter<iSize;iCounter++)
            {
                NewData[iCounter] = iStartElementPtr[iCounter];
            }

            delete [] iStartElementPtr;
            iStartElementPtr = NewData;
            iEndElementPtr   = iStartElementPtr + iSize;
            iCapacityPtr     = iStartElementPtr + iCapacity;
        }

        *iEndElementPtr = iData;
        iEndElementPtr++;

    }
    int size()
    {
        return iEndElementPtr - iStartElementPtr;
    }

    int capacity()
    {
        return iCapacityPtr - iStartElementPtr;
    }

    T at(int iPos)
    {
        return iStartElementPtr[iPos];
    }

    void pop_back()
    {
        iEndElementPtr = iEndElementPtr - 1 ;
    }

    void clear()
    {
        iEndElementPtr   = iStartElementPtr;
    }

    void Shrink_to_fit()
    {
        delete [] iStartElementPtr;
        iStartElementPtr = nullptr;
        iEndElementPtr = nullptr;
        iCapacityPtr  = nullptr;
    }

   void resize(int iReserve)
    {
        int iCounter = 0;
        if(iReserve==0)
           return;
        T * resizePtr = new T[iReserve];


        for(;iCounter<size()-1;iCounter++)
        {
            resizePtr[iCounter] = iStartElementPtr[iCounter];
        }
		
        if(iReserve>size()-1)
        {
            while(iCounter<iReserve)
            {
                resizePtr[iCounter] = 0;
                iCounter++;
            }
            iCounter = size();
        }
		else
		{
			iCounter = iReserve;
		}

		iEndElementPtr   = resizePtr + iCounter ;
        delete []iStartElementPtr;
		
        iStartElementPtr = resizePtr; 
        iCapacityPtr     = iStartElementPtr + iReserve;
    } 

    void reserve(int ireserve)
    {
		int iCounter = 0;
		if(ireserve <=capacity())
		{
			return;
		}
		
		T * reserve = new T[ireserve];
		for(;iCounter<size();iCounter++)
		{
			reserve[iCounter] = iStartElementPtr[iCounter];
		}
		iEndElementPtr = reserve + iCounter;
		for(;iCounter<ireserve;iCounter++)
		{
			reserve[iCounter] = 0;
		}

		delete [] iStartElementPtr;
		iStartElementPtr = reserve;

		iCapacityPtr = iStartElementPtr + iCounter;
    }
    
};
int main(void)
{
    MyVector<char> vec;
    
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');


    cout<<"Capacity Of Vector is :- "<<vec.capacity()<<endl;
    cout<<"size Of Vector is :- "<<vec.size()<<endl;

    vec.pop_back();

    cout<<"After pop_back() Capacity Of Vector is :- "<<vec.capacity()<<endl;
    cout<<"After pop_back() size Of Vector is :- "<<vec.size()<<endl;

	vec.clear();

    cout<<"After pop_back() Capacity Of Vector is :- "<<vec.capacity()<<endl;
    cout<<"After pop_back() size Of Vector is :- "<<vec.size()<<endl;

    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');


	MyVector<char> vec1 = vec;
	cout<<"sizeof(vec1)"<<vec1.size()<<endl;
	cout<<"capacity(vec1)"<<vec1.capacity()<<endl;

	MyVector<char> vec2(vec);
	vec2.pop_back();
	cout<<"sizeof(vec2)"<<vec2.size()<<endl;
	cout<<"capacity(vec2)"<<vec2.capacity()<<endl;
	MyVector<char> vec3;

	vec3 = move(vec);

	cout<<"sizeof(vec3)"<<vec3.size()<<endl;
	cout<<"capacity(vec3)"<<vec3.capacity()<<endl;


	cout<<vec3[0]<<endl;
	cout<<vec3[1]<<endl;
	cout<<vec3[2]<<endl;

	vec3.resize(2);
	cout<<"after resize sizeof(vec3)"<<vec3.size()<<endl;
	cout<<"after resize capacity(vec3)"<<vec3.capacity()<<endl;

	vec3.reserve(5);
	cout<<"after resize sizeof(vec3)"<<vec3.size()<<endl;
	cout<<"after resize capacity(vec3)"<<vec3.capacity()<<endl;
    return 0;
}