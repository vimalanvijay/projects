#include <iostream>
#include <string>
#include <vector>

using namespace std;
void insertionSort(int *array);
void PrintArray(int *array);
int main()
{
    int array[10]={8,6,4,5,3,7,2,1,9,10};
    
    cout<<"intial:"<<endl;
    PrintArray(array);
    
    insertionSort(array);
    
    cout<<endl;
    cout<<"sorted:"<<endl;
    PrintArray(array);
    
    
}

void insertionSort(int *array)
{
    int value=0, index=0; //index value are 0
    
    for(int i=0; i<10; i++)
    { //for iteration 0 to 10 increase by 1
        value=array[i]; //set value to element i
        index= i; //set index to value of i
        while(index>0 && array[index-1]<value)
        {
            //while index is greater than 0 AND array element index -1 is less than value
            array[index]=array[index-1]; //array element at index is set to the value of element index-1
            index=index-1; //decrease index by 1
        }
        array[index]=value; //array at new index is equal to value
    }
    
}

void PrintArray(int *array)
{
    for(int i=0; i<10;i++)
        cout<<array[i]<<endl;
}

