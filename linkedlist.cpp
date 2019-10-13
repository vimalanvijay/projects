#include <iostream>
#include<string>
#include <fstream>
using namespace std;

class Node
{
private:
    string name;
    Node* p_next;
public:
    Node();
    Node(string name_in, Node* p_next_in);
    string getName();
    void setName(string name_in);
    Node* getNext();
    void setNext(Node* p_next_in);
};

class Queue
{
private:
    Node* p_head;
public:
    Queue();
    void addNode(string name_in);
    string removeNode();
    void printQueue();
    ~Queue();
};

Node:: Node() //constructor 1
{
    name=" ";
    p_next=nullptr;
}

Node:: Node(string name_in, Node* p_next_in) //constructor w 2 arguments
{
    name=name_in;
    p_next=p_next_in;
}

string Node:: getName()
{
    return name;
}

void Node:: setName(string name_in)
{
    name=name_in;
}

Node* Node::getNext()
{
    return p_next;
}

void Node::setNext(Node *p_next_in)
{
    p_next=p_next_in;
}



Queue:: Queue()
{
    p_head=nullptr;
}

string Queue::removeNode()
{
    Node* p_seek;
    string removed_name=" ";
    
    for(p_seek=p_head; p_seek!=nullptr; p_seek=p_seek->getNext())
    {
        if((p_seek==p_head) && (p_seek->getNext()==nullptr))
        {
            removed_name= p_seek->getName();
            delete p_seek;
            p_head=nullptr;
            //cout<<"Removing in A"<<removed_name<<endl;
        }
        else if(p_seek->getNext()->getNext()==nullptr)
        {
            removed_name=p_seek->getNext()->getName();
            delete p_seek->getNext();
            p_seek->setNext(nullptr);
            //cout<<"Removing in B "<<removed_name<<endl;
        }
    }
    
    return removed_name;
}


void Queue:: addNode(string name_in)
{
    p_head=new Node(name_in,p_head);
}

void Queue::printQueue()
{
    Node* p_seek;
    cout<<"Current Que: "<<endl;
    for(p_seek=p_head; p_seek!=nullptr; p_seek=p_seek->getNext())
        cout<<" "<<p_seek->getName()<<endl;
}

Queue::~Queue()
{
    while (p_head != nullptr)
    {
        removeNode();
    }
}

int main()
{
    Queue line;
    
    line.addNode("james");
    line.addNode("greg");
    line.addNode("sarah");
    line.addNode("catherine");
    line.addNode("julie");
    line.addNode("alex");
    line.printQueue();
    
    cout<<" > removing "<<line.removeNode()<<" from queue."<<endl;
    cout<<" > removing "<<line.removeNode()<<" from queue."<<endl;
    line.printQueue();
    
    line.addNode("jack");
    line.addNode("angela");
    line.printQueue();
    
    
    return 0;
}
