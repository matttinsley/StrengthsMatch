#include "users.h"
#include "matchmaker.h"

using namespace std;

int main(int argc, const char* argv[])
{
    vector<user> users (0);

    initialUserList(users, cout);

    string menuInput;
    menuInput = promptMainInput(cout);

    while(menuInput.compare("exit") != 0){
        if(menuInput.compare("add") == 0){
            string input = "yes";
            do{
                cout << "Would you like to add a new user?" << endl;
                cin >> input;
                if(!input.compare("yes")){
                    addUser(users, cout);
                }
            }while(!input.compare("yes") || !input.compare("Yes"));
            menuInput = promptMainInput(cout);
        }

        else if(menuInput.compare("search") == 0){
            vector<user> matches (0);
            cout << "What strength are you looking for?" << endl;
            string desiredStrength;
            cin >> desiredStrength;

            for(unsigned int i=0; i<users.size(); i++){
                if(findStrength(users[i], desiredStrength)){
                    matches.insert(matches.end(), users[i]);
                }
            }

            printMatches(matches, cout);

            menuInput = promptMainInput(cout);
        }
        else if(menuInput.compare("matchmake") == 0){
            vector<string> prefStrengths(0);
            int prefNum;
            cout << "How many preferences would you like to add?\n";
            cin >> prefNum;
            for(int i=0; i<prefNum; i++){
                inputPreference(users, prefStrengths, cout);
            }

            cout << "Your preferred strengths are: " << endl;

            for(unsigned int i=0; i < prefStrengths.size(); i++){
                cout << prefStrengths[i] << endl;
            }

            cout << "\nTop strength is:\n";
            string desiredStrength = mostOccuringPref(users, prefStrengths, cout);

            cout << "\nOther users with this strength:\n";
            vector<user> matches (0);
            for(unsigned int i=0; i<users.size(); i++){
                if(findStrength(users[i], desiredStrength)){
                    matches.insert(matches.end(), users[i]);
                }
            }

            printMatches(matches, cout);

            menuInput = promptMainInput(cout);
        }
        else{
            menuInput = promptMainInput(cout);
        }
    }

    return 0;
}


