#ifndef MATCHMAKER_H_INCLUDED
#define MATCHMAKER_H_INCLUDED

#include <vector>
#include <string>
#include <ostream>
#include "users.h"

void inputPreference(std::vector<user>, std::vector<std::string>&, std::ostream&);
std::string mostOccuringPref(std::vector<user>, std::vector<std::string>, std::ostream&);

bool findStrength(user, std::string);
bool findStrength(user, std::string, std::string);
void printMatches(std::vector<user>, std::ostream&);


#endif // MATCHMAKER_H_INCLUDED