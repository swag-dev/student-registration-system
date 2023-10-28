#include "student.h"

string capitalize(string str){
    str[0] = toupper(str[0]);
    return str;
}

string stringify_object(Student student){
    string str = "";
    str += student.get_username() + "\n";
    str += student.get_password() + "\n";
    str += student.get_first_name() + "\n";
    str += student.get_last_name() + "\n";
    str += std::to_string(student.get_birth_year()) + "\n";
    str += std::to_string(student.get_level()) + "\n";
    return str;
}

int main(){

    Student students[10];
    int student_count = 0;
    string username;
    string password;
    string first_name;
    string last_name;
    int birth_year;
    int level;

    std::cout << "Welcome to the Student Management System\n";
    std::cout << "Do you want to create a new student or login? (1/2)\n";

    int response;
    std::cin >> response;

    if(response == 1){
        
        std::cout << "Enter the student's username: ";
        std::cin >> username;
        students[student_count].set_username(username);
        std::cout << "Enter the student's password: ";
        std::cin >> password;
        students[student_count].set_password(password);
        std::cout << "Enter the student's first name: ";
        std::cin >> first_name;
        students[student_count].set_first_name(capitalize(first_name));
        std::cout << "Enter the student's last name: ";
        std::cin >> last_name;
        students[student_count].set_last_name(capitalize(last_name));
        std::cout << "Enter the student's birth_year: ";
        std::cin >> birth_year;
        students[student_count].set_birth_year(birth_year);
        std::cout << "Enter the student's level: ";
        std::cin >> level;
        students[student_count].set_level(level);
        
        std::ofstream outfile(students[student_count].get_username() + ".txt", std::ios::app);
         if (outfile.is_open())
    {
        outfile << stringify_object(students[student_count]);
        outfile.close();
        std::cout << "File written successfully.\n";
    }
    else
    {
        std::cout << "Unable to open file.\n";
    }
        student_count++;
        std::cout << "Student created successfully!\n";
        std::cout << "Press 1 to login or 2 to exit\n";
        

    }
    else if(response == 2){
        std::cout << "Enter the student's username: ";
        string username;
        std::cin >> username;
        std::cout << "Enter the student's password: ";
        string password;
        std::cin >> password;
        Student student;

        std::ifstream infile(username + ".txt");
        if(infile.is_open()){
            std::string line;
            int line_count = 0;
            while(getline(infile, line)){
                switch(line_count){
                    case 0:
                        student.set_username(line);
                        break;
                    case 1:
                        student.set_password(line);
                        break;
                    case 2:
                        student.set_first_name(line);
                        break;
                    case 3:
                        student.set_last_name(line);
                        break;
                    case 4:
                        student.set_birth_year(std::stoi(line));
                        break;
                    case 5:
                        student.set_level(std::stoi(line));
                        break;
                }
                line_count++;
            }
        }
        else{
            std::cout << "Unable to open file.\n";
        }
        if(student.username == username && student.password == password){
            
            std::cout << "Login successful!\n";
            std::cout << "Welcome " << student.get_first_name() << " " << student.get_last_name() << "\n";
            std::cout << "Your birth year is " << student.get_birth_year() << "\n";
            std::cout << "Your level is " << student.get_level() << "\n";
        }
        else{
            std::cout << "Login failed!\n";
        }
    }
    else{
        std::cout << "Invalid response!\n";
    }
    return 0;
}