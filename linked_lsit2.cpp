#include <iostream>
#include <string>
using namespace std;

//---------------------- NODE CLASS ----------------------------------
class Node
{
private:
    string name;
    Node* p_next;
    
public:
    Node();
    Node(string name_in, Node *p_next_in);
    string getName();
    void setName(string name_in);
    
    Node *getNext()
    {
        return p_next;
    }
    
    void setNext(Node *p_next_in);
};

//------------------------ NODE FUNCTIONS ------------------------------------

Node::Node()
{
    name="";
    p_next=nullptr;
}

Node::Node(string name_in, Node *p_next_in)
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

void Node:: setNext(Node *p_next_in)
{
    p_next=p_next_in;
}

//----------------------- QUEUE CLASS-----------------------------

class Queue
{
private:
    Node* p_head;
    
public:
    Queue();
    void addNode(string name_in);
    void printQueue();
};


//----------------------- QUEUE FUNCTIONS -------------------------

Queue::Queue() //constructor always point to null
{
    p_head=nullptr;
}

void Queue:: addNode(string name_in)
{
    p_head=new Node(name_in, p_head);
}

void Queue:: printQueue()
{
    Node *p_peek;
    for(p_peek=p_head; p_peek!=nullptr; p_peek=p_peek->getNext())
    {
        cout<<" "<<p_peek->getName()<<endl;
    }
}



//------------------------ MAIN --------------------

int main()
{
    Queue line;
    
    line.addNode("James");
    line.addNode("john");
    line.addNode("Vimalan");
    line.addNode("THALA");
    line.printQueue();
}
