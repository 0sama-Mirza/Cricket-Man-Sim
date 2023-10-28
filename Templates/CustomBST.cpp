#include "../includes/Globals.h"
#include "../includes/CustomBST.h"
#include<iostream>
#include<fstream>
template <class U>
bst<U>::bst() : Root(nullptr), Current(nullptr), s() {}

template <class U>
Node<U>* bst<U>::add(int id, U nam, int money, U country, U favfood, U favItem, U favSong, U baditem, U badsong, U badfood, Node<U>* SubRoot) {
    if(Root==nullptr){     //This will only run 1st time......     
        return Root = new Node<U>(id,nam, money,country,favfood,favItem,favSong,baditem,badsong,badfood);//.....
    }                   //just to make Root pointer = first node.
    if(SubRoot==nullptr){     //This Will Make a node whenever the currently selected node's                                     
        return new Node<U>(id,nam,money,country,favfood, favItem,favSong, baditem, badsong, badfood);//Left Or Right Side becomes Empty.
    }
    else if(money<SubRoot->GetMoneySpent()){   //This will move our SubRoot Pointer to the left if 
        SubRoot->SetLeft(add(id,nam,money,country,favfood, favItem,favSong, baditem, badsong, badfood,SubRoot->GetLeft()));//The Value inserted is less then the subroot.
    }
    else if(money>SubRoot->GetMoneySpent()){//if The Value inserted is more then the subroot.
        SubRoot->SetRight(add(id,nam,money,country,favfood, favItem,favSong, baditem, badsong, badfood,SubRoot->GetRight()));//This will move our SubRoot Pointer to the right
    }              //This Function will return the left or right side of the pointer's value
    else{
        // cout<<"Value Already Added!   ID: "<<id<<endl;
        return SubRoot;
    }                                                 
    int BF=Get_Balance_Factor(SubRoot);
    // cout<<"Balance Factor Of "<<SubRoot->GetID()<<": "<<BF<<endl;
    if(BF>1&&SubRoot->GetLeft()->GetMoneySpent()>money){ //LL ImBalance
        // cout<<"LL"<<endl;
        return RightRotation(SubRoot);
    }
    if(BF<-1&&SubRoot->GetRight()->GetMoneySpent()<money){ //RR ImBalance
        // cout<<"RR"<<endl;
        return LeftRotation(SubRoot);
    }
    if(BF>1&&SubRoot->GetLeft()->GetMoneySpent()<money){ //LR ImBalance
        SubRoot->SetLeft(LeftRotation(SubRoot->GetLeft()));
        // cout<<"LR"<<endl;
        return RightRotation(SubRoot);
    }
    if(BF<-1&&SubRoot->GetRight()->GetMoneySpent()>money){//RL ImBalance
        SubRoot->SetRight(RightRotation(SubRoot->GetRight()));
        // cout<<"RL"<<endl;
        return LeftRotation(SubRoot);
    }
    return SubRoot;
}

template <class U>
Node<U>* bst<U>::RightRotation(Node<U>* SubRoot){
    Node<U>* Temp=SubRoot->GetLeft();
    SubRoot->SetLeft(SubRoot->GetLeft()->GetRight());
    Temp->SetRight(SubRoot);
    if(SubRoot==Root)
        Root=Temp;
    return Temp;
}

template <class U>
Node<U>* bst<U>::LeftRotation(Node<U>* SubRoot){
    Node<U>* Temp=SubRoot->GetRight();
    // cout<<"Value Of Temp: "<<Temp->GetID()<<endl;
    SubRoot->SetRight(SubRoot->GetRight()->GetLeft());
    Temp->SetLeft(SubRoot);
    if(SubRoot==Root)
        Root=Temp;
    return Temp;
}

template <class U>
void bst<U>::inorderrr(Node<U>* t){
    if(t==nullptr)
        return;
    inorderrr(t->GetLeft());
    std::cout<<"--------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"|"<<t->GetID()<<"|"<<t->GetName()<<" | "<<t->GetMoneySpent()<<" | "<<t->GetCountryName()<<" | "<<t->GetFavFood()<<" | "<<t->GetFavItem()<<" | "<<t->GetFavSong()<<std::endl;
    inorderrr(t->GetRight());
}

template <class U>
void bst<U>::prr(Node<U>* t){
    if(t==nullptr)
        return;
    prr(t->GetRight());
    std::cout<<"--------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"|"<<t->GetID()<<"|"<<t->GetName()<<" | "<<t->GetMoneySpent()<<" | "<<t->GetCountryName()<<" | "<<t->GetFavFood()<<" | "<<t->GetFavItem()<<" | "<<t->GetFavSong()<<std::endl;
    prr(t->GetLeft());
    
}

template <class U>
void bst<U>::post(Node<U>* t){
    if(t==nullptr)
        return;
    prr(t->GetLeft());
    std::cout<<t->GetID()<<",";
    prr(t->GetRight());
}

template <class U>
Node<U>* bst<U>::minn(Node<U>* t){
    if(t==nullptr)
        return nullptr;
    else if(t->GetLeft()==nullptr)
        return t;
    else
        return minn(t->GetLeft());
}

template <class U>
Node<U>* bst<U>::maxx(Node<U>* t){
    if(t==nullptr)
        return nullptr;
    else if(t->GetRight()==nullptr)
        return t;
    else
        return maxx(t->GetRight());
}

template <class U>
Node<U>* bst<U>::Searchh(Node<U>* SubRoot,U value){
    if(SubRoot==nullptr)
        return nullptr;
    if(SubRoot->GetID()==value)
        return SubRoot;
    if(SubRoot->GetID()>value)
        return Searchh(SubRoot->GetLeft(),value);
    return Searchh(SubRoot->GetRight(),value);
}

template <class U>
int bst<U>::counter(Node<U>* SubRoot){
    if(SubRoot==nullptr)
        return 0;
    return counter(SubRoot->GetLeft())+counter(SubRoot->GetRight())+1;
}

template <class U>
int bst<U>::TotalDepth(Node<U>* SubRoot){
    if(SubRoot==nullptr)
        return 0;
    int LeftHight=TotalDepth(SubRoot->GetLeft());
    int RightHight=TotalDepth(SubRoot->GetRight());
    return std::max(LeftHight,RightHight)+1;
}

template <class U>
int bst<U>::Get_Balance_Factor(Node<U> *SubRoot){
    if(SubRoot==nullptr)
        return 0;
    else
        return (TotalDepth(SubRoot->GetLeft())-TotalDepth(SubRoot->GetRight()));
}

template <class U>
Node<U>* bst<U>::Khatm(Node<U>*SubRoot,U v){
    if(v<SubRoot->GetID())
        SubRoot->SetLeft(Khatm(SubRoot->GetLeft(),v));
    else if(v>SubRoot->GetID())
        SubRoot->SetRight(Khatm(SubRoot->GetRight(),v));
    else{
        if(SubRoot->GetLeft()==nullptr){//If It has One Child at Left.
            Node<U>* Temp=SubRoot->GetRight();
            delete SubRoot;
            return Temp;
        }
        if(SubRoot->GetRight()==nullptr){//If It has One Child at Right.
            Node<U>* Temp=SubRoot->GetLeft();
            delete SubRoot;
            return Temp;
        }
    Node<U>* Temp= minn(SubRoot->GetRight());
    SubRoot->SetValue(Temp->GetID(),Temp->GetName(),Temp->GetMoneySpent(),Temp->GetCountryName(),Temp->GetFavFood(),Temp->GetFavItem(),Temp->GetFavSong(),Temp->GetBadItem(),Temp->GetBadSong(),Temp->GetBadFood());
    SubRoot->SetRight(Khatm(SubRoot->GetRight(),Temp->GetID()));
    }
    s.pop();
    return SubRoot;
}

template <class U>
void bst<U>::Write_Data_To_CSVFile(Node<U>* Data,std::string FileName){
    std::fstream myFile;
	 myFile.open(FileName+".csv",std::ios::app);
	 if(myFile.is_open()){
	 	myFile<<Data->GetID()<<","<<Data->GetName()<<","<<Data->GetCountryName()<<","<<Data->GetMoneySpent()<<","<<Data->GetFavSong()<<","<<Data->GetFavItem()<<","<<Data->GetFavFood()<<","<<Data->GetBadSong()<<","<<Data->GetBadItem()<<","<<Data->GetBadFood()<<std::endl;
	 	myFile.close();
	 }
}

template <class U>
void bst<U>::Going_Inorder_For_CSV(Node<U>* t,std::string FileName){
    if(t==nullptr)
        return;
    Going_Inorder_For_CSV(t->GetLeft(),FileName);
    Write_Data_To_CSVFile(t,FileName);    
    Going_Inorder_For_CSV(t->GetRight(),FileName);
    // Write_Data_To_CSVFile(t,FileName);
}

template <class U>
void bst<U>::insert(int id,U nam,int money,U country,U favfood,U favItem,U favSong,U baditem,U badsong,U badfood){
    s.push(id);
    add(id,nam,money,country,favfood,favItem,favSong,baditem,badsong,badfood,Root);
}

template <class U>
void bst<U>::Search(int v){
    if(Searchh(Root,v)==nullptr){
        std::cout<<"This Value Doesnot exist."<<std::endl;
    }
    else
        std::cout<<"Value "<<v<<" Found!"<<std::endl;
}

template <class U>
void bst<U>::Del(U v){
    Khatm(Root,v);
    std::cout<<"\n.......Data "<<v<< " Deleted......"<<std::endl;
}

template <class U>
U bst<U>::LastElement(){
    return s.top();
}

template <class U>
void bst<U>::inorder(){
    std::cout<<" #ID "<<" Name        "<<" Money "<<" Country "<<" FavFood "<<" Favitem " <<" FavSong "<<std::endl;
    inorderrr(Root);
}

template <class U>
void bst<U>::PreOrder(){
    std::cout<<" #ID "<<" Name        "<<" Money "<<" Country "<<" FavFood "<<" Favitem " <<" FavSong "<<std::endl;
    prr(Root);
}

template <class U>
void bst<U>::PostOrder(){
    post(Root);
}

template <class U>
int bst<U>::count(){
    return counter(Root);
}

template <class U>
void bst<U>::minvalue() {
    Node<U>* minNode = minn(Root);
    if (minNode) {
        std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "#ID \tName \t\t\tMoney Spent($$) \tCountry" << std::endl;
        std::cout << minNode->GetID() << " \t" << minNode->GetName() << "\t\t\t" << minNode->GetMoneySpent() << " \t\t" << minNode->GetCountryName() << std::endl;
        std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "No minimum value found (Tree is empty)." << std::endl;
    }
}


template <class U>
void bst<U>::maxvalue(){
    Node<U>* maxNode = maxx(Root);
    if (maxNode) {
        std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "#ID \tName \t\t\tMoney Spent($$) \tCountry" << std::endl;
        std::cout << maxNode->GetID() << " \t" << maxNode->GetName() << "\t\t" << maxNode->GetMoneySpent() << " \t\t" << maxNode->GetCountryName() << std::endl;
        std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "No maximum value found (Tree is empty)." << std::endl;
    }
}

template <class U>
int bst<U>::Depth(){
    return Get_Balance_Factor(Root);
}

template <class U>
void bst<U>::RootValue(){
    std::cout<<"Root Value: "<<Root->GetID()<<std::endl;
    // cout<<"Root Right Value: "<<Root->GetRight()->GetID()<<endl;
}

template <class U>
void bst<U>::Write_Data_To_CSV(std::string Filename){
    std::fstream myFile;
	myFile.open(Filename+".csv",std::ios::out);//Write
	if(myFile.is_open()){
	    myFile<<"ID#,Name,Country,Money Spent,Favourite Song,Favourite Item,Favourite Food,Worst Song,Worst Item,Worst Food"<<std::endl;
	 	myFile.close();
	}
    Total_Attendees++;
    Going_Inorder_For_CSV(Root,Filename);
}






