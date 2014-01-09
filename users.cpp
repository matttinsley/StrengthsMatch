#include "users.h"

std::string promptMainInput(std::ostream& out){
    std::string menuInput;
    bool validInput = false;
    while(!validInput){
        out << "\nWould you like to add, search, matchmake, or exit?\n";
        std::cin >> menuInput;
        if(menuInput.compare("add")==0 ||
           menuInput.compare("search")==0 ||
           menuInput.compare("matchmake")==0 ||
           menuInput.compare("exit")==0)
        {
            validInput = true;
        }
    }
    return menuInput;
}


void addUser(std::vector<user> &users, std::ostream& out){
    user temp;
    std::string gender, nameFirst, nameLast, strength;
    std::cout << "Enter first and last name of user: " << std::endl;
    std::cin >> nameFirst >> nameLast;
    temp.setNameFirst(nameFirst);
    temp.setNameLast(nameLast);
    std::cout << "Enter gender of user: " << std::endl;
    std::cin >> gender;
    temp.setGender(gender);
    std::cout << "Enter user's top 5 strenghts: " << std::endl;
    for(int i=0; i<5; i++){
        std::cin >> strength;
        temp.setStrength(i, strength);
    }
    users.insert(users.end(), temp);

    std::ofstream outfile;
    outfile.open("userData.txt", std::ios::app);
    outputUserData(temp, outfile);
    outfile.close();
}

void outputUserData(user temp, std::ostream& out){
    out << temp.getGender() << " " << temp.getName() << " ";
    for(int i=0; i<5; i++){
        out << temp.getStrength(i) << " ";
    }
    out << std::endl;
}

user inputUserData(std::istream& infile){
    user temp;
    std::string inGender, inFirst, inLast, inStrength;
    infile >> inGender >> inFirst >> inLast;
    temp.setGender(inGender);
    temp.setNameFirst(inFirst);
    temp.setNameLast(inLast);
    for(int i=0; i<5; i++){
        infile >> inStrength;
        temp.setStrength(i, inStrength);
    }
    return temp;
}

void initialUserList(std::vector<user> &users, std::ostream& out){
    std::ifstream infile;
    infile.open("userData.txt");
    int i = 0;
    while(infile.good()){
        user temp = inputUserData(infile);
        if(temp.getGender() != ""){
            users.insert(users.end(), temp);
            out << users[i].getName() << " added." << std::endl;
            i++;
        }
    }
    out << i << " users loaded." << std::endl;
    infile.close();
}

//user class

std::string user::getNameFirst(){
    return nameFirst;
}

std::string user::getNameLast(){
    return nameLast;
}

std::string user::getName(){
    return nameFirst + " " + nameLast;
}

std::string user::getGender(){
    return gender;
}

std::string user::getStrength(int i){
    return strengths[i];
}

void user::setNameFirst(std::string newFirst){
    nameFirst = newFirst;
}

void user::setNameLast(std::string newLast){
    nameLast = newLast;
}

void user::setGender(std::string newGender){
    gender = newGender;
}

void user::setStrength(int& i, std::string newStrength){
    strengths[i] = newStrength;
}
