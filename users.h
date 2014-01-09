#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


class user{
    private:
        std::string nameFirst;
        std::string nameLast;
        std::string gender;
        std::string strengths[5];


    public:
        std::string getNameFirst();
        std::string getNameLast();
        std::string getName();
        std::string getGender();
        std::string getStrength(int);

        void setNameFirst(std::string);
        void setNameLast(std::string);
        void setGender(std::string);
        void setStrength(int&, std::string);
};


std::string promptMainInput(std::ostream&);
void addUser(std::vector<user>&, std::ostream&);
void outputUserData(user, std::ostream&);
user inputUserData(std::istream&);
void initialUserList(std::vector<user>&, std::ostream&);





#endif // USERS_H_INCLUDED
