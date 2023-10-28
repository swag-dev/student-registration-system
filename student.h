#include <iostream>
#include <fstream>
#include <string>

using std::cout, std::string, std::cin;
class Student{
    public:
        string username;
        string first_name;
        string last_name;
        int birth_year;
        int level;
        string password;
        void set_username(string username){
            this->username = username;
        }
        void set_first_name(string first_name){
            this->first_name = first_name;
        }
        void set_last_name(string last_name){
            this->last_name = last_name;
        }
        void set_birth_year(int birth_year){
            this->birth_year = birth_year;
        }
        void set_level(int level){
            this->level = level;
        }
        void set_password(string password){
            this->password = password;
        }
        string get_username(){
            return this->username;
        }
        string get_first_name(){
            return this->first_name;
        }
        string get_last_name(){
            return this->last_name;
        }
        int get_birth_year(){
            return this->birth_year;
        }
        int get_level(){
            return this->level;
        }
        string get_password(){
            return this->password;
        }
        

};