#include <iostream>
using namespace std;

class Point //base class
{
protected:
    double y;
    double x;
    
public:
    //constructors and deconstructors
    Point(); //default constructor
    Point(const Point &pt); //copy constructor
    Point(double x_in, double y_in); //parameterised constructors
    ~Point();
    
    //access func
    double get_x();
    double get_y();
    
    //virtual func
    virtual void print(); //virtual func declared here can be overwritten by derived class
    
    //operator overloading
    friend Point operator+(const Point &pt1, const Point &pt2);
    friend Point operator-(const Point &pt1, const Point &pt2);
    friend ostream& operator<<(ostream &os, Point &pt1);
};

Point::Point()
{
    y=0;
    x=0;
}

Point::Point(const Point &pt) //copy constuctors
{
    x=pt.x; //initialise an object using another object of the same class
    y=pt.y;
}

Point::Point(double x_in, double y_in)
{
    x=x_in;
    y=y_in;
}

Point::~Point() //destructors
{
    
}

double Point:: get_x()
{
    return x;
}

double Point:: get_y()
{
    return y;
}

//VIRTUAL FUCtion
void Point::print()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

//operator overloading

Point operator+(const Point &pt1, const Point &pt2)
{
    Point pt;
    pt.x= pt1.x+pt2.x;
    pt.y=pt1.y+pt2.y;
    return pt;
}

ostream& operator << (ostream &os, Point &pt1)
{
    return os<< "("<<pt1.x<<","<<pt1.y<<")"<<endl;
}

Point operator-(const Point &pt1, const Point &pt2)
{
    Point pt;
    pt.x= pt1.x-pt2.x;
    pt.y=pt1.y-pt2.y;
    return pt;
}


class Rectangle : public Point //derived class
{
private:
    double w;
    double h;
    
public:
    Rectangle();
    Rectangle(double x_in, double y_in, double w_in, double h_in);
    Rectangle(const Rectangle &rect_in);
    ~Rectangle();
    
    double get_w()
    {
        return w;
    }
    
    double get_h()
    {
        return h;
    }
    
    void print();
};

//derived class const&destructors

Rectangle::Rectangle():Point()
{
    w=0;
    h=0;
}

Rectangle::Rectangle(double x_in, double y_in, double w_in, double h_in):Point()
{
    w=w_in;
    h=h_in;
    x=x_in;
    y=y_in;
}

Rectangle::Rectangle(const Rectangle &rect_in):Point() //copy constuctors
{
    h=rect_in.h;
    w=rect_in.w;
    x=rect_in.x;
    y=rect_in.y;
}

Rectangle:: ~Rectangle()
{
    
}

void Rectangle::print()
{
    cout<<"("<<x<<","<<y<<","<<w<<","<<h<<")"<<endl;
}







int main ()
{
    Point origin(0,0);
    Point pt1 (1,3);
    Point pt2 (2,4); //reuqires constructors
    Point pt3;
    Point pt4=pt2; //requires copy constructors
    
    cout<<"These are base class values: "<<endl;
    origin.print();
    pt1.print();
    pt2.print();
    pt3.print();
    pt4.print();
    
    Rectangle rect1;            // requires constructors
    Rectangle rect2(2, 0, 1, 1);
    Rectangle rect3(2, 3, 7, 5);
    Rectangle rect4 = rect3;    // requires copy assignment
    
     cout<<"These are rectangle class values: "<<endl;
    rect1.print();
    rect2.print();
    rect3.print();
    rect4.print();
    
    cout<<endl;
    cout<<"Pointer on classes!"<<endl;
    
    Point* p_bs; //pointer base object
    p_bs= &pt4; //sets the pointer to the address of pt4 object
    cout<<"This prints using pointers"<<endl;
    p_bs->print(); //now pt_bs points to pt4, so use arrow to access the print fuction
    
    //operator overloading
    
    Point pt5;
    pt5=pt1+pt2; //here we need operator overloading
    cout<<"operator overloading"<<endl;
    cout<<"pt1 is ";
    pt1.print();
    cout<<"pt2 is ";
    pt2.print();
    
    cout<<"pt1 + pt2 = ";
    
    pt5.print();
    
    cout<<pt1; //we need to overload the << too
    cout<<pt2;
    cout<<pt3;
    cout<<pt4;
    
    Point pt6;
    pt6=pt3-pt2;
    cout<< pt6;
    
    
    
    
    /*
    
    //pointer example
    
    int var=19;
    int *pointer_var;
    
    pointer_var=&var;
    
    cout<<*pointer_var<<endl;
    
    *pointer_var=1010;
    
    cout<<&*pointer_var<<endl;
    cout<<var<<endl; */
    
}
