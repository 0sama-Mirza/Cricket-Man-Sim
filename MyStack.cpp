#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyNode{
    template<typename U>
    friend class MyStack;
    private:
        MyNode* next;
        T data;
    public:
        MyNode(): next(nullptr), data() {}
        MyNode<T> *GetNext(){
            return next;
        }
        T GetData(){
            return data;
        }
        void SetNext(MyNode<T> *a){
            next=a;
        }
        void SetData(T a){
            data=a;
        }
};

template<typename A>
class MyStack{
    private:
        MyNode<A>* top;
        MyNode<A>* current;
        int count;
    public:
        MyStack<A>(): top(nullptr), current(nullptr), count(0){}
        void insert(A value){
            MyNode<A>* temp=new MyNode<A>;
            temp->SetData(value);
            if(top==nullptr){
                temp->SetNext(nullptr);
                top=temp;
            }
            else{
                temp->SetNext(top);
                top=temp;
            }
            count++;
        }
        void del(){
            if(!IsEmpty()){
                current=top->next;
                delete top;
                top=current;
                count--;
            }
            else
                cout<<"There Are No Participants!"<<endl;
        }
        bool IsEmpty(){
            if(top==nullptr)
                return true;
            else
                return false;
        }
        void print(){
            if(IsEmpty())
                cout<<"";
            else{
                current=top;
                cout<<"|";
                while(current->next!=nullptr){
                    cout<<current->data<<"|"<<endl<<"|";
                    current=current->next;
                }
                cout<<current->data<<"|"<<endl;
            }
        }
        int size(){
            return count;
        }
        A gettop(){
            return top->GetData();
        }
};