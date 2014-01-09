#include "matchmaker.h"

void inputPreference(std::vector<user> users, std::vector<std::string>& prefStrengths, std::ostream& out){
    std::string prefNameFirst, prefNameLast;
    out << "What kind of person are you looking for?" << std::endl;
    std::cin >> prefNameFirst >> prefNameLast;
    bool foundUser = false;
    for(unsigned int i=0; i<users.size(); i++){
        if(users[i].getNameFirst().compare(prefNameFirst)==0 && users[i].getNameLast().compare(prefNameLast)==0){
            foundUser = true;
            for(int j=0; j<5; j++){
                prefStrengths.insert(prefStrengths.end(), users[i].getStrength(j));
            }
        }
    }
    if(!foundUser){
        std::cout << "No match found.\n";
    }
}

std::string mostOccuringPref(std::vector<user> users, std::vector<std::string> prefStrengths,
                             std::ostream& out){
    int maxCount = 0;
    int prefLoc;
    for(unsigned int i=0; i < prefStrengths.size(); i++){
        int tempCount = 1;
        for(unsigned int j=i+1; j < prefStrengths.size(); j++){
            if(prefStrengths[i].compare(prefStrengths[j])==0){
                tempCount++;
            }
        }
        if(tempCount > maxCount){
            maxCount = tempCount;
        }
    }

    //print out all that occur maxCount times
    for(unsigned int i=0; i < prefStrengths.size(); i++){
        int tempCount = 1;
        for(unsigned int j=i+1; j<prefStrengths.size(); j++){
            if(prefStrengths[i].compare(prefStrengths[j])==0){
                tempCount++;
            }
        }
        if(tempCount == maxCount){
            out << prefStrengths[i] << std::endl;
            prefLoc = i;
        }
    }
    return prefStrengths[prefLoc];
}

bool findStrength(user potential, std::string desiredStrength){
    bool match = false;
    for(int j=0; j<5; j++){
        if(potential.getStrength(j) == desiredStrength){
            match = true;
        }
    }
    return match;
}

bool findStrength(user potential, std::string desiredStrength1, std::string desiredStrength2){
    bool match1 = false;
    bool match2 = false;
    for(int j=0; j<5; j++){
        if(potential.getStrength(j) == desiredStrength1){
            match1 = true;
        }
        else if(potential.getStrength(j) == desiredStrength2){
            match2 = true;
        }
    }
    return match1 && match2;
}

void printMatches(std::vector<user> matches, std::ostream& out){
    out << "Matches are:\n";
    for(unsigned int i=0; i<matches.size(); i++){
        out << matches[i].getName() << std::endl;
    }
    if(matches.size() == 0){
        out << "No matches found.\n";
    }
}