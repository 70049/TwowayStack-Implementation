#include<iostream>
#include<conio.h>
using namespace std;
class Twowatstack
{
private:
    int capacity;
    int top_left;
    int top_right;
    int *ptr;
public:
    Twowatstack(int cap)
    {
        capacity=cap;
        top_left=-1;
        top_right=capacity;
        ptr=new int[capacity];
    }
    ~Twowatstack()
    {
        delete []ptr;
    }
    void Pushleft(int val);
    void Pushright(int val);
    int Popleft();
    int Popright();
    int peekleft();
    int peekright();
    int Isemptyleft();
    int Isemptyright();
    int Isfull();
};
int Twowatstack::Isfull()
{
    if(top_left+1==top_right)
        return(1);
    else
        return(0);
}
int Twowatstack::Isemptyright()
{
    if(top_right==capacity)
        return(-1);
    else
        return(1);
}
int Twowatstack::Isemptyleft()
{
    if(top_left==-1)
        return(-1);
    else
        return(1);
}
 int Twowatstack:: peekright()
{
    if(Isemptyright()){
        cout<<"\nStack Is Empty";
        return(-1);
    }
    else
        return(ptr[top_right]);
}
int Twowatstack::peekleft()
{
    if(Isemptyleft()){
        cout<<"\nStack Is Empty:";
        return(-1);
    }
    else
        return(ptr[top_left]);
}
int Twowatstack::Popright()
{
    int val;
    if(Isemptyright())
    {
        cout<<"\nStack underflow:";
        return(-1);
    }
    else{
        val=ptr[top_right];
        top_right++;
        return(val);
    }
}
int Twowatstack::Popleft()
{
    int val;
    if(Isemptyleft()){
        cout<<"\nStack Underflow:";
        return(-1);
    }
    else{
        val=ptr[top_left];
        top_left--;
        return(val);
    }
}
void Twowatstack::Pushright(int val)
{
    if(Isfull()){
        cout<<"\nStack Underflow:";
    }
    else{
        top_right--;
        ptr[top_right]=val;
    }
}
void Twowatstack::Pushleft(int val)
{
    if(Isfull()){
        cout<<"\nStack Underflow:";    }
    else{
        top_left++;
        ptr[top_left]=val;
    }
}

int main()
{
    Twowatstack s(11);
    s.Pushleft(20);
    cout<<"\n Peek From Stack1"<<s.peekleft();
    cout<<endl<<"Peek from Stack2"<<s.peekright();
    getch();
}
