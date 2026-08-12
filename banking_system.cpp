#include<bits/stdc++.h>
using namespace std;
long long acc=260000;
int users=0;
class bank{
    public:
    long long acc_no;
    string acc_holder_name;
    double balance;
    string acc_type;
    double with_amo;
    bank(){
        acc_no=++acc;
        acc_holder_name="";
        balance=0;
        acc_type="";
        with_amo=0;
    }
    ~bank(){
        
    }
    void create_account(){
        int temp=0; 
        cout<<"Enter Your Information"<<endl;
        cout<<"Enter Name:";
        getchar();
        getline(cin,acc_holder_name);
        while(temp!=1 && temp!=2 && temp!=3 && temp!=4){
        cout<<"Choose Account Type\n1:Zero Balance\n2:Saving\n3:Current\n4:Bussiness"<<endl;
        cin>>temp;
        switch(temp){
            case 1: acc_type="Zero Balance";
                    break;
            case 2: acc_type="Saving";
                    break;
            case 3: acc_type="Current";
                    break;
            case 4: acc_type="Bussiness";
                    break;
            default:    cout<<"Enter Valid Choice Again"<<endl;
        }
    }
        cout<<"Your Account Number is:"<<endl;
        cout<<acc_no;
        cout<<"\nEnter Initilal Amount to be deposited:";
        cin>>balance;
        cout<<"Account Created Successfully "<<endl;
    }
    void display(){
        cout<<"Account Holder Name:->"<<acc_holder_name<<endl;
        // cout<<"Balance:-"<<balance<<endl;
        printf("Balance:-> %.2f\n", balance);
        cout<<"Account Type:->"<<acc_type<<endl;
    }
    void balance_check(){
        printf("Balance: %.2f\n", balance);
    }
    void withdraw(){
        cout<<"Enter Withdrwal Amount:";
        cin>>with_amo;
        if(with_amo>balance) cout<<"Insufficient Funds"<<endl;
        else{
            balance-=with_amo;
            cout<<"Transaction Successful"<<endl;
            printf("Updated Balance:%.2f\n",balance);
        }
    }
    void deposit(){
        double am;
        cout<<"Enter Amount to be deposited";
        cin>>am;
        balance+=am;
        printf("Updated Balance:%.2f\n",balance);            
    }
};
int main(){
    long long a;
    int flag=0;
    vector<bank> b;
    int choice,ch,i;
    long long t1;
    do{
        cout<<"---MENU---\n0:Create Account\n1:Dispaly Information\n2:Check balance\n3:Withdraw Amount\n4:Deposit Amount\n5:Delete Account\n6:Exit\n";
        cout<<"Enter Your Choice";
        cin>>choice;
        if(choice==6)   return 0;
        // if(choice==1)   b.display();
        // else if(choice==2) b.balance_check();
        // else if(choice==3) b.withdraw();
        // else if(choice==4) b.deposit();
        switch(choice){ 
        case 0:             {bank temp;
                            temp.create_account();
                            b.push_back(temp);
                            users++;
                            break;
        }
            case 1:     if(users>0){
                        flag=0;
                        cout<<"Enter Account Number:"<<endl;
                        cin>>t1;
                        for(i=0;i<users;i++){
                            if(b[i].acc_no==t1){
                                cout<<"Data of Customer having account no-> "<<t1<<endl;
                                b[i].display();
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0) cout<<"Account No. Does Not Found"<<endl;
                    }
                        else{
                            cout<<"The Records Are Empty"<<endl;
                        }
                        break;
            case 2:     if(users>0){
                        cout<<"Enter Accout No.";
                        flag=0;
                        cin>>a;
                        for(int i=0;i<users;i++){
                            if(a==b[i].acc_no){
                                b[i].balance_check();
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0){
                                cout<<"Account No. Does not Found"<<endl;
                            }
                        }
                        else{
                            cout<<"The Records Are Empty"<<endl;
                        }
                        break;
            case 3:     if(users>0){
                        cout<<"Enter Accout No.";
                        flag=0;
                        cin>>a;
                        for(int i=0;i<users;i++){
                            if(a==b[i].acc_no){
                                b[i].withdraw();
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0){
                                cout<<"Account No. Does not Found"<<endl;
                            }
                        }
                        else{
                            cout<<"The Records Are Empty"<<endl;
                        }
                        break;
            case 4:     if(users>0){
                        cout<<"Enter Accout No.";
                        flag=0;
                        cin>>a;
                        for(int i=0;i<users;i++){
                            if(a==b[i].acc_no){
                                b[i].deposit();
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0){
                                cout<<"Account No. Does not Found"<<endl;
                            }
                    }
                        else{
                            cout<<"The Records Are Empty"<<endl;
                        }
                        break;
            case 5:     cout<<"Enter Account Number to be Deleted:"<<endl;
                        cin>>t1;
                        flag=0;
                        for(int i=0;i<users;i++){
                            if(b[i].acc_no==t1){
                                b.erase(b.begin() + i);
                                cout<<"Acoount Deleted Successfully with Account Number:-> "<<t1<<endl;
                                flag=1;
                                users--;
                                break;
                            }
                        }
                        if(flag==0) cout<<"Account Not Find with Account No.:-> "<<t1<<endl;
                        break;
            default:    cout<<"Invalid Choice"<<endl;
                    
        }
        cout<<"Do you Want to Continue(1/0)";
        cin>>ch;
    }while(ch==1);
    return 0;
}
