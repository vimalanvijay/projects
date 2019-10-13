#include <iostream>

using namespace std;

template<typename T>
class Calculator
{
private:
    T x;
    T y;
    
public:
    Calculator();
    Calculator(T x_in, T y_in);
    void MainMenu();
    T Addition();
    T Subtraction();
    T Division();
    T Multiply();
    
};

template<typename T>
Calculator<T>::Calculator()
{
    x=0;
    y=0;
}

template<typename T>
Calculator<T>::Calculator(T x_in, T y_in)
{
    x=x_in;
    y=y_in;
}

template<typename T>
void Calculator<T>:: MainMenu()
{
    int select=0;
    
    cout<<" *** Simple Calculator *** "<<endl;
    cout<<" Enter 1 for addition."<<endl;
    cout<<" Enter 2 for minus."<<endl;
    cout<<" Enter 3 for multiple."<<endl;
    cout<<" Enter 4 for division."<<endl;
    
    cin>>select;
    
    switch(select)
    {
        case 1: select= 1;
            Addition();
            break;
        case 2: select=2;
            Subtraction();
            break;
        case 3: select=3;
            Multiply();
            break;
        case 4: select=4;
            Division();
            break;
            
        default:
            cout<<"Error!"<<endl;
            
    }
}

template<typename T>
T Calculator<T>:: Addition()
{
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    
    cout<<"Answer: "<<x+y<<endl;
    return x+y;
}

template<typename T>
T Calculator<T>:: Subtraction()
{
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Answer: "<<x-y<<endl;

    
    return x-y;
}


template<typename T>
T Calculator<T>:: Multiply()
{
   
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Answer: "<<x*y<<endl;

    return x*y;
}


template<typename T>
T Calculator<T>:: Division()
{
   
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Answer: "<<x/y<<endl;

    return x/y;
}



int main()
{
    
    Calculator<int> c1(19,20);
    c1.MainMenu();
    
    Calculator<float> c2;
    c2.MainMenu();

    Calculator<double> c3;
    c3.MainMenu();
    
    
}
