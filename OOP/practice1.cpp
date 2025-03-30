#include<iostream>
#include <string>

using namespace std;

class User {
    private:
        int id;
        string password;

    public:
        string username;
    

    User(int id){
        this->id =id;
    }

    void setPass(string password){
        this-> password = password;
    }


    string getPass(){
        return password;
    }

};

int main(){
    User user1(1);
    user1.username="Shreyas";
    user1.setPass("12345fd");
    cout<<"username: "<< user1.username<<endl;
    cout<<"Password: "<< user1.getPass()<<endl;
    return 0;
}