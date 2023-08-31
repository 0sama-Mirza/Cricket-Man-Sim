//EveryThing In A BST Tree!!!!!!!!!
#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

template<class T>
class Node{
    private:
        int height;
        T Name;
        int ID;
        int MoneySpent;
        T CountryName;
        T FavFood;
        T FavItem;
        T FavSong;
        T BadItem;
        T BadSong;
        T BadFood;
        Node *Left,*Right;     
    public:
        Node(int id,T nam,int money,T country,T favfood, T favItem,T favSong,T baditem,T badsong,T badfood):
            height(0),
            Name(nam),
            ID(id),
            MoneySpent(money),
            CountryName(country),
            FavFood(favfood),
            FavItem(favItem),
            FavSong(favSong),
            BadItem(baditem),
            BadSong(badsong),
            BadFood(badfood),
            Left(nullptr),
            Right(nullptr){}
        Node* GetLeft(){
            return Left;
        }
        Node* GetRight(){
            return Right;
        }
        int GetID(){
            return ID;
        }
        T GetName(){
            return Name;
        }
        int GetMoneySpent(){
            return MoneySpent;
        }
        T GetCountryName(){
            return CountryName;
        }
        T GetFavFood(){
            return FavFood;
        }
        T GetFavItem(){
            return FavItem;
        }
        T GetFavSong(){
            return FavSong;
        }
        T GetBadItem(){
            return BadItem;
        }
        T GetBadFood(){
            return BadFood;
        }
        T GetBadSong(){
            return BadSong;
        }
        void SetLeft(Node*L){
            Left=L;
        }
        void SetRight(Node*R){
            Right=R;
        }
        void SetValue(int id,T nam,int money,T country,T favfood, T favItem,T favSong,T baditem,T badsong,T badfood){
            Name=nam;
            MoneySpent=money;
            ID=id;
            CountryName=country;
            FavFood=favfood;
            FavItem=favItem;
            FavSong=favSong;
            BadItem=baditem;
            BadSong=badsong;
            BadFood=badfood;
        }
};

template<class U>
class bst{
    private:
        Node<U>* Root,*Current;//The Current Pointer is only used for searching and displaying.
        stack<int>s;      
        Node<U>* add(int id,U nam,int money,U country,U favfood,U favItem,U favSong,U baditem,U badsong,U badfood,Node<U>* SubRoot){//SubRoot Pointer exists only to insert the values.
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

        Node<U>* RightRotation(Node<U>* SubRoot){
            Node<U>* Temp=SubRoot->GetLeft();
            SubRoot->SetLeft(SubRoot->GetLeft()->GetRight());
            Temp->SetRight(SubRoot);
            if(SubRoot==Root)
                Root=Temp;
            return Temp;
        }

        Node<U>* LeftRotation(Node<U>* SubRoot){
            Node<U>* Temp=SubRoot->GetRight();
            // cout<<"Value Of Temp: "<<Temp->GetID()<<endl;
            SubRoot->SetRight(SubRoot->GetRight()->GetLeft());
            Temp->SetLeft(SubRoot);
            if(SubRoot==Root)
                Root=Temp;
            return Temp;
        }
        void inorderrr(Node<U>* t){
            if(t==nullptr)
                return;
            inorderrr(t->GetLeft());
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|"<<t->GetID()<<"|"<<t->GetName()<<" | "<<t->GetMoneySpent()<<" | "<<t->GetCountryName()<<" | "<<t->GetFavFood()<<" | "<<t->GetFavItem()<<" | "<<t->GetFavSong()<<endl;
            inorderrr(t->GetRight());
        }
        void prr(Node<U>* t){
            if(t==nullptr)
                return;
            prr(t->GetRight());
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|"<<t->GetID()<<"|"<<t->GetName()<<" | "<<t->GetMoneySpent()<<" | "<<t->GetCountryName()<<" | "<<t->GetFavFood()<<" | "<<t->GetFavItem()<<" | "<<t->GetFavSong()<<endl;
            prr(t->GetLeft());
            
        }
        void post(Node<U>* t){
            if(t==nullptr)
                return;
            prr(t->GetLeft());
            cout<<t->GetID()<<",";
            prr(t->GetRight());
        }
        Node<U>* minn(Node<U>* t){
            if(t==nullptr)
                return nullptr;
            else if(t->GetLeft()==nullptr)
                return t;
            else
                return minn(t->GetLeft());
        }
        Node<U>* maxx(Node<U>* t){
            if(t==nullptr)
                return nullptr;
            else if(t->GetRight()==nullptr)
                return t;
            else
                return maxx(t->GetRight());
        }
        Node<U>* Searchh(Node<U>* SubRoot,U value){
            if(SubRoot==nullptr)
                return nullptr;
            if(SubRoot->GetID()==value)
                return SubRoot;
            if(SubRoot->GetID()>value)
                return Searchh(SubRoot->GetLeft(),value);
            return Searchh(SubRoot->GetRight(),value);
        }
        int counter(Node<U>* SubRoot){
            if(SubRoot==nullptr)
                return 0;
            return counter(SubRoot->GetLeft())+counter(SubRoot->GetRight())+1;
        }
        int TotalDepth(Node<U>* SubRoot){
            if(SubRoot==nullptr)
                return 0;
            int LeftHight=TotalDepth(SubRoot->GetLeft());
            int RightHight=TotalDepth(SubRoot->GetRight());
            return max(LeftHight,RightHight)+1;
        }
        int Get_Balance_Factor(Node<U> *SubRoot){
            if(SubRoot==nullptr)
                return 0;
            else
                return (TotalDepth(SubRoot->GetLeft())-TotalDepth(SubRoot->GetRight()));
        }
        Node<U>* Khatm(Node<U>*SubRoot,U v){
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


        void Write_Data_To_CSVFile(Node<U>* Data,string FileName){
            fstream myFile;
        	 myFile.open(FileName+".csv",ios::app);
        	 if(myFile.is_open()){
        	 	myFile<<Data->GetID()<<","<<Data->GetName()<<","<<Data->GetCountryName()<<","<<Data->GetMoneySpent()<<","<<Data->GetFavSong()<<","<<Data->GetFavItem()<<","<<Data->GetFavFood()<<","<<Data->GetBadSong()<<","<<Data->GetBadItem()<<","<<Data->GetBadFood()<<endl;
        	 	myFile.close();
			 }
        }

        void Going_Inorder_For_CSV(Node<U>* t,string FileName){
            if(t==nullptr)
                return;
            Going_Inorder_For_CSV(t->GetLeft(),FileName);
            Write_Data_To_CSVFile(t,FileName);    
            Going_Inorder_For_CSV(t->GetRight(),FileName);
            // Write_Data_To_CSVFile(t,FileName);
        }
    public:
        bst(): Root(nullptr), Current(nullptr),s(){}
        void insert(int id,U nam,int money,U country,U favfood,U favItem,U favSong,U baditem,U badsong,U badfood){
            s.push(id);
            add(id,nam,money,country,favfood,favItem,favSong,baditem,badsong,badfood,Root);
        }
        void Search(int v){
            if(Searchh(Root,v)==nullptr){
                std::cout<<"This Value Doesnot exist."<<std::endl;
            }
            else
                std::cout<<"Value "<<v<<" Found!"<<std::endl;
        }
        void Del(U v){
            Khatm(Root,v);
            std::cout<<"\n.......Data "<<v<< " Deleted......"<<std::endl;
        }
        U LastElement(){
            return s.top();
        }
        void inorder(){
            cout<<" #ID "<<" Name        "<<" Money "<<" Country "<<" FavFood "<<" Favitem " <<" FavSong "<<endl;
            inorderrr(Root);
        }
        void PreOrder(){
            cout<<" #ID "<<" Name        "<<" Money "<<" Country "<<" FavFood "<<" Favitem " <<" FavSong "<<endl;
            prr(Root);
        }
        void PostOrder(){
            post(Root);
        }
        int count(){
            return counter(Root);
        }
        void minvalue(){
            cout<<"-------------------------------------------------------------------------------------------"<<endl;
            cout<<"#ID \tName \t\t\tMoney Spent($$) \tCountry"<<endl;
            cout<<minn(Root)->GetID()<<" \t"<<minn(Root)->GetName()<<"\t\t\t"<<minn(Root)->GetMoneySpent()<<" \t\t"<<minn(Root)->GetCountryName()<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
        }
        void maxvalue(){
            cout<<"-------------------------------------------------------------------------------------------"<<endl;
            cout<<"#ID \tName \t\t\tMoney Spent($$) \tCountry"<<endl;
            cout<<maxx(Root)->GetID()<<" \t"<<maxx(Root)->GetName()<<"\t\t"<<maxx(Root)->GetMoneySpent()<<" \t\t"<<maxx(Root)->GetCountryName()<<endl;
            cout<<"-------------------------------------------------------------------------------------------"<<endl;
        }
        int Depth(){
            return Get_Balance_Factor(Root);
        }
        void RootValue(){
            cout<<"Root Value: "<<Root->GetID()<<endl;
            // cout<<"Root Right Value: "<<Root->GetRight()->GetID()<<endl;
        }
        void Write_Data_To_CSV(string Filename){
            fstream myFile;
        	myFile.open(Filename+".csv",ios::out);//Write
        	if(myFile.is_open()){
        	    myFile<<"ID#,Name,Country,Money Spent,Favourite Song,Favourite Item,Favourite Food,Worst Song,Worst Item,Worst Food"<<endl;
        	 	myFile.close();
			}
            Total_Attendees++;
            Going_Inorder_For_CSV(Root,Filename);
        }
};
// int main(){
//     bst<string> a;
//     a.insert(1,"Osama",32131,"Pakistan","Pizza","Flag","Mera Dil Badl Dy","Dildo","STFU","Puke");
//     a.insert(2,"Burhan",2312,"India","Biriyani","Shirt","TeriMeri","Boom Boom","STFU","Puke");
//     a.insert(3,"Bilal",2324,"Pakistan","Pizza","Cap","Oolala OooLala","Dildo","STFU","Puke");
//     a.insert(4,"Agha",32131,"Israel","Pizza","GPA","GPA GPA GPA","Dildo","STFU","Puke");
//     a.insert(5,"Noor",2324,"SaudiArab","Pizza","Pickle Rick","TUm Jeeto Ya Haro","Dildo","STFU","Puke");
//     a.insert(6,"Arham",2324,"Pakistan","Pizza","Baja","BoomBastick","Dildo","STFU","Puke");
//     a.insert(7,"Lucky",2324,"Pakistan","Pizza","Star","Lucky Star Opening","Dildo","STFU","Puke");
//     a.inorder();
//     cout<<endl;
//     a.PreOrder();
//     cout<<endl;
//     a.RootValue();
//     a.Write_Data_To_CSV();
//     return 0;
// }