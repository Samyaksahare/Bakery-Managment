#include <iostream>
#include <type_traits>
#include <cstring>
#include <vector>
using namespace std;
#include <deque>
const int max_size = 100;
template <typename T>
class queue {
private:
    int front;
    int rear;
    T arr[max_size]={};
public:
    queue(){
        front=-1;
        rear =-1;
    }
    bool isEmpty(){
        return front==-1&&rear==-1;
    }
    bool isFull(){
        return rear==max_size-1;
    }
    void enqueue(T value){
        if(isFull()) {
            cout<<"queue is Full"<<endl;
            return;
        }
        if(isEmpty()){
            front =0;
            rear =0;
        } else {
            rear++;
        }
        arr[rear]= value;
        // cout<<"Element enqueued : "<<value<<endl;
    }
    void dequeue(){
        if(isEmpty()) {
            cout<<"queue is Empty "<<endl;
            return;
        }
        T removedVal=arr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        } else {
            front++;
        }
//        cout<<"dequeued element : "<<removedVal<<endl;
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        return rear;
    }
    int getFrontNumber(){
        return front;
    }
    void display(){
        if(isEmpty()){
            cout<<"The queue is empty "<<endl;
            return;
        }
        cout<<"queue elements : "<<endl;
        for (int i = front; i <= rear; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int getFirst(int element){
        return arr[element].first;
    }
    int getSecond(int element){
        return arr[element].second;
    }
    template<typename NumericType = T>
    NumericType sum() const {
        if(!std::is_arithmetic<NumericType>::value)
        {
            cout<<"Summation can only be calculated for numeric data types"<<endl;
            return NumericType();
        }else{
            NumericType total = NumericType();
            for (int i = front; i != (rear + 1) % max_size; i = (i + 1) % max_size) {
                total += arr[i];
            }
            return total;
        };
    }
    int length(){
        if(isEmpty()){
            return 0;
        }
        return rear-front+1;
    }
    void clear(){
        front=-1;
        rear=-1;
    }
    int size(){
        return max_size;
    }

};

queue<int>payingQueue;
queue<pair<int,int>>bakeryMaleQueue;
queue<pair<int,int>>bakeryFemaleQueue;

void homePage();
bool breadValidation(int breadNum, int familySize);
void loginAdmin();
void registerAdmin();
void loginRegister();
void invalid();
void addCard();
void paymentLine();
void buyBreadWithCard();
void buyBreadWithoutCard();
void bakeryQueue();
void totalBreadRevenue();
int Confirmation();
void displayMaleQueue();
void displayFemaleQueue();
void done();
// 6 In Home Page
float moneyCard = 0;
int breadCard = 0;
float moneyNoCard = 0;
int breadNoCard = 0;
float TotalmoneyCard = 0;
int TotalbreadCard = 0;

class admin{
private:
    string userName, password;

public:
    admin() {}
    admin(string userName , string password){
        this->userName=userName;
        this->password=password;
    }

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        admin::userName = userName;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        admin::password = password;
    }
};
vector<admin> adminsList;

int cardsID = 0;
class cardsInformation{
private:
    string name;
    int familySize , monthlyBread;
    int id;

public:
    cardsInformation() {}
    cardsInformation(string n,int fz) {
        this->name=n;
        this->familySize=fz;
        this->monthlyBread=familySize*150;
        this->id=++cardsID;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        cardsInformation::name = name;
    }

    int getFamilySize() const {
        return familySize;
    }

    void setFamilySize(int familySize) {
        cardsInformation::familySize = familySize;
    }

    int getMonthlyBread() const {
        return monthlyBread;
    }

    void setMonthlyBread(int monthlyBread) {
        cardsInformation::monthlyBread = monthlyBread;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        cardsInformation::id = id;
    }
};
vector<cardsInformation> cardsList;

int customerMaleID = 0;
int customerFemaleID = 0;
class customerInformation{
private:
    bool gender;
    int customerID;
    int breadNum = 0;
public:
    customerInformation(bool g){
        this->gender=g;
        if(this->gender)
        {
            this->customerID=++customerMaleID;
        }
        else
        {
            this->customerID=++customerFemaleID;
        }
    }
    customerInformation() {}

    bool isGender() {
        if(this->gender)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void setGender(bool gender) {
        customerInformation::gender = gender;
    }

    int getCustomerId() const {
        return customerID;
    }

    void setCustomerId(int customerId) {
        customerID = customerId;
    }

    int getBreadNum() const {
        return breadNum;
    }

    void setBreadNum(int breadNum) {
        customerInformation::breadNum = breadNum;
    }
};
vector<customerInformation> customersList;

int main() {
    loginRegister();
    return 0;
}
void loginAdmin(){
    cout<<"\n=============================\n";
    cout<<"Login Page";
    a:cout << "\nEnter your UserName :";
    string userName,password;
    cin>>userName;
    cout << "Enter your password :";
    cin>>password;
    for(auto it : adminsList)
    {
        if(userName == it.getUserName() && password == it.getPassword())
        {
            cout<<"Login Successfully";
            cout<<"\n=============================\n";
            homePage();
            break;
        }
    }
    invalid();
    loginRegister();
}

void registerAdmin(){
    cout<<"\n=============================\n";
    cout<<"Register Page";
    cout << "\nEnter your UserName :";
    string userName,password;
    cin>>userName;
    cout << "Enter your password :";
    cin>>password;
    admin insert = *new admin(userName,password);
    adminsList.push_back(insert);
    cout<<"Admin Added Successfully";
    cout<<"\n=============================\n";
    loginRegister();
}

void loginRegister(){
    cout << "\n---> Welcome To Sha5syat ElBatl Bakery! <---\nChoose Your Option\n1. Register\n2. Login\nChoose Option :";
    int option;
    cin >> option;
    if(option == 1){
        registerAdmin();
    }
    else if(option == 2){
        loginAdmin();
    }
    else{
        invalid();
        loginRegister();
    }
}

void invalid(){
    cout<<"Invalid Input !!";
}

void homePage()
{
    cout<<"\n=============================\n";
    cout<<"Home Page";
    cout<<"\n1. Add Card\n2. Payment Line\n3. Buy Bread With Card\n4. Buy Bread Without Card\n5. Bakery Queue\n6. Total Bread Revenue\n7. Logout\nChoose Option :";
    int option;
    cin>>option;
    cout<<"=============================\n";
    switch (option) {
        case 1:
            addCard();
            break;
        case 2:
            paymentLine();
            break;
        case 3:
            buyBreadWithCard();
            break;
        case 4:
            buyBreadWithoutCard();
            break;
        case 5:
            bakeryQueue();
            break;
        case 6:
            totalBreadRevenue();
            break;
        case 7:
            loginRegister();
            break;
        default:
            invalid();
            homePage();
            break;

    }
}
void addCard(){
    cout<<"\n=============================\n";
    cout<<"Add Card Page";
    cout<<"\nEnter Your Name :";
    string name;
    cin >> name;
    cout<<"Enter Your Family Size :";
    int familySize;
    cin>>familySize;
    cardsInformation c = *new cardsInformation(name,familySize);
    cardsList.push_back(c);
    cout<<"Your Monthly Bread : "<<c.getMonthlyBread()<<"\nYour Card ID : "<<c.getId();
    done();

}
void paymentLine(){
    cout<<"\n=============================\n";
    cout<<"Payment Line Page\n";
    cout<<"Input Your Gender\n1. Male\n2. Female\nChoose Option :";
    int option;
    cin>>option;
    bool gender = false;
    if(option == 1)
    {
        gender = true;
    }
    else if(option == 2)
    {
        gender = false;
    }
    else
    {
        invalid();
        cout<<"=============================\n";
        paymentLine();
    }
    customerInformation c = *new customerInformation(gender);
    cout<<"Your Queue ID Is : "<<c.getCustomerId();
    payingQueue.enqueue(c.getCustomerId());
    customersList.push_back(c);
    done();
}
void buyBreadWithCard(){
    cout<<"\n=============================\n";
    cout<<"Buy With Card Page\n";
    cout<<"Enter Your ID  :";
    int id , flag = 0;
    cin>>id;
    int gender;
    cout<<"Enter Your Gender\n1. Male\n2. Female\nChoose Option :";
    cin>>gender;
    bool s = false;
    if(gender == 1)
    {
        s = true;
    }
    else if(gender == 2)
    {
        s = false ;
    }
    else
    {
        cout<<"=============================\n";
        invalid();
        buyBreadWithCard();
    }
    for(auto it : cardsList){
        if(it.getId() == id)
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        x:cout<<"This ID Doesn't Exist !\n1. HomePage\n2. Logout\nChoose Option :";
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"=============================\n";
            homePage();
        }
        else if(op==2)
        {
            cout<<"=============================\n";
            loginRegister();
        }
        else
        {
            invalid();
            goto x;
        }
    }
    else
    {
        cout<<"Enter Your Card ID :";
        int id2 , flag2 = 0;
        cin>>id2;
        auto it2 = cardsList.begin();
        int index = 0;
        for(auto ite : cardsList){
            if(ite.getId() == id2)
            {
                it2 = cardsList.begin() + index;
                flag2 = 1;
                break;
            }
            index++;
        }
        if(!flag2)
        {
            invalid();
            cout<<"\n=============================\n";
            buyBreadWithCard();
        }
        else
        {
            //Myabe An Error
            cout<<"Your Card Information\nHouse Holder Name : "<<it2->getName()<<"\nFamily Size : "<<it2->getFamilySize()<<"\nMonthly Bread : "<<it2->getMonthlyBread();
            w:cout<<"\nHow many bread the user wants :";
            int breadNum;
            cin>>breadNum;
            //Function Validation Ya Omar !!

            if(breadValidation(breadNum, it2->getFamilySize()))
            {
                a:cout << "Your total price is : " << breadNum  * 0.05 << " L.E"<< endl;
                cout<<"Are You Sure You Want To Buy ?\n1. Yes\n2. No\nChoose Option :";
                int option;
                cin >> option;
                if(option == 1){
                    moneyCard+=breadNum  * 0.05;
                    breadCard+=breadNum;
                    TotalmoneyCard+=breadNum  * 0.05;
                    TotalbreadCard+=breadNum;
                    it2->setMonthlyBread(it2->getMonthlyBread() - (breadNum));
                    cout << "Payment Success \nYour total monthly bread is: " << it2->getMonthlyBread();
                    pair<int, int>p;
                    p.first = it2->getId();
                    p.second = breadNum;
                    if(s == true) {
                        bakeryMaleQueue.enqueue(p);
                    }
                    else{
                        bakeryFemaleQueue.enqueue(p);
                    }
                    payingQueue.dequeue();
                    done();
                    //go . to somewhere
                }
                else if(option == 2){
                    done();
                }
                else{
                    invalid();
                    goto a;
                }
            }
            else
            {
                cout << "\nYou cant exceed your Daily Limit.\n";
                done();
            }
        }
    }
}
bool breadValidation(int breadNum, int familySize){
    if(breadNum > familySize * 5){
        return false;
    }
    else{
        return true;
    }
}
void buyBreadWithoutCard(){
    cout<<"\n=============================\n";
    cout<<"Buy Without Card Page\n";
    cout<<"Enter Your ID  :";
    int id , flag = 0;
    cin>>id;
    int gender;
    cout<<"Enter Your Gender\n1. Male\n2. Female\nChoose Option :";
    cin>>gender;
    bool s = false;
    if(gender == 1)
    {
        s=true;
    }
    else if(gender == 2)
    {
        s = false;
    }
    else
    {
        invalid();
        buyBreadWithoutCard();
    }
    auto it = customersList.begin();
    int index = 0;
    for(auto ite : customersList){
        if(ite.getCustomerId() == id)
        {
            it = customersList.begin() + index;
            flag = 1;
            break;
        }
        index++;
    }
    if(!flag)
    {
        x:cout<<"This ID Doesn't Exist !\n1. HomePage\n2. Logout\nChoose Option :";
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"=============================\n";
            homePage();
        }
        else if(op==2)
        {
            cout<<"=============================\n";
            loginRegister();
        }
        else
        {

            invalid();
            goto x;
        }
    }
    else
    {
        a:cout<<"How many bread the user wants : ";
        int breadQ , price;
        cin>>breadQ;
        price = breadQ*1;
        cout<<"You Should Pay : "<<price<<" L.E";
        cout<<"\nAre You Sure You Want To Buy ?\n1. Yes\n2. No\nChoose Option :";
        int op;
        cin>>op;
        if(op == 1)
        {
            moneyNoCard+=price;
            breadNoCard+=breadQ;
            TotalmoneyCard+=price;
            TotalbreadCard+=breadQ;
            it->setBreadNum(breadQ);
            pair<int,int>p;
            p.first = id;
            p.second = breadQ;
            if(s == true)
            {
                bakeryMaleQueue.enqueue(p);
                payingQueue.dequeue();
                done();
            }
            else
            {
                bakeryFemaleQueue.enqueue(p);
                payingQueue.dequeue();
                done();
            }
        }
        else if(op == 2)
        {
            done();
        }
        else
        {
            invalid();
            goto a;
        }

    }
}
void bakeryQueue(){
    cout<<"\n=============================\n";
    cout<<"Bakery Queue Page\n";
    cout<<"Choose Queue\n1. Male Line\n2. Female Line\nChoose Option :";
    int op;
    cin>>op;
    if(op == 1)
    {
        displayMaleQueue();
    }
    else if(op == 2)
    {
        displayFemaleQueue();
    }
    else
    {
        invalid();
        bakeryQueue();
    }
};
void totalBreadRevenue(){
    cout<<"\n=============================\n";
    cout<<"Revenue Page";
    cout<<"\nProfit With Card : "<<moneyCard;
    cout<<"\nNumber Bread Selled With Card : "<<breadCard;
    cout<<"\n\nProfit Without Card : "<<moneyNoCard;
    cout<<"\nNumber Bread Selled Without Card : "<<breadNoCard;
    cout<<"\n\nTotal Profit : "<<TotalmoneyCard;
    cout<<"\nTotal Bread Selled : "<<TotalbreadCard;
    done();
};
void displayMaleQueue(){
    if(bakeryMaleQueue.isEmpty())
    {
        cout << "\nThe queue is empty" << endl;
    }
    else
    {
        for(int i= bakeryMaleQueue.getFrontNumber() ; i <= bakeryMaleQueue.getRear();i++)
            cout<<"\nID number: "<<bakeryMaleQueue.getFirst(i)<<"----> Number of Breads: "<<bakeryMaleQueue.getSecond(i)<<endl;

        cout << "\nThe bread is ready to Go ? " << endl;
        cout << "1. Yes\n";
        cout << "2. No\nChoose Option :";
        int option;
        cin >> option;
        if(option == 1)
        {
            cout << "Bread Deleivered.\n";
            bakeryMaleQueue.dequeue();
        }
        else
        {
            cout << "The bread is not ready yet" << endl;
        }
    }
    done();
}
void displayFemaleQueue(){
    if(bakeryFemaleQueue.isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        for(int i= bakeryFemaleQueue.getFrontNumber() ; i <= bakeryFemaleQueue.getRear() ; i++)
            cout<<"\nID number: "<<bakeryFemaleQueue.getFirst(i)<<"----> Number of Breads: "<<bakeryFemaleQueue.getSecond(i)<<endl;

        cout << "The bread is ready to Go ? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No\nChoose Option :";
        int option;
        cin >> option;
        if(option == 1)
        {
            cout << "Bread Deleivered.\n";
            bakeryFemaleQueue.dequeue();
        }
        else
        {
            cout << "The bread is not ready yet" << endl;
        }
    }
    done();
}
void done()
{
    cout<<"\n=============================\n";
    cout<<"\n=============================";
    cout<<"\nYour Action Has Been Completed Successfully!\n1. HomePage\n2. Logout\nChoose Option :";
    int op;
    cin>>op;
    if(op == 1)
    {
        cout<<"=============================\n";
        homePage();
    }
    else if(op == 2)
    {
        cout<<"=============================\n";
        loginRegister();

    }
    else
    {
        cout<<"=============================\n";
        invalid();
        done();
    }

}