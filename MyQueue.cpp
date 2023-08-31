//Implementation of queue including all of its operations.
#include<iostream>
// using namespace std;
template<class T>
class node{
    template<typename U>
    friend class queue;
    private:
        node* next;
        T data;
    public:
        node() : next(nullptr), data(){}
        node<T> *GetNext(){
            return next;
        }
        T GetData(){
            
            return data;
        }
        void SetNext(node<T> *a){
            next=a;
        }
        void SetData(T a){
            data=a;
        }
};

template<class Q>
class queue{
    private:
        node<Q>* front;
        node<Q>* rear;
        node<Q>* current;
        int count;
    public:
        queue() : front(nullptr), rear(nullptr), current(nullptr), count(0){}
        void Enqueue(Q value){
            node<Q>* temp=new node<Q>;
            temp->SetData(value);
            if(front==nullptr){
                temp->SetNext(nullptr);
                front=temp;
                rear=temp;
            }
            else{
                rear->SetNext(temp);
                rear=temp;
            }
            count++;
        }
        Q Dequeue(){
            if(!IsEmpty()){
                current=front->GetNext();
                delete front;
                front=current;
                count--;
            }
            else{
                std::cout<<std::endl<<"The Queue is empty."<<std::endl;
            }
            return front->GetData();
        }
        bool IsEmpty(){
            if(front==nullptr)
                return true;
            else
                return false;
        }
        int size(){
            return count;
        }    
        Q Get_data(){
            return front->GetData();
        }    
        void print(){
            std::cout<<std::endl<<"      [";
            current=front;
            while(current!=rear){
                std::cout<<current->GetData()<<",";
                current=current->next;
            }
            std::cout<<current->GetData()<<"]"<<std::endl<<"       ^"<<std::endl;
        }
};
