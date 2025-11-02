#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printV (const map<string, tuple<int, string, string>> villagers){ //I created a function so that later in the code, I can just call back to this without needing to rewrite the whole thing
    cout << "Villagers and their informations :" << endl;
    for (auto pair : villagers) {
        cout << pair.first << ": " << get<0>(pair.second) << ", "<< get<1>(pair.second) << ", "<< get<2>(pair.second) << endl;
    }
}

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    //friendship level, species, and catchphrase
    villagers["Audie"] = make_tuple(8, "mouse", "i want cheese");
    villagers["Raymond"] = make_tuple(5, "cat", "where did the mouse go");
    villagers.insert({"Marshal", make_tuple(9, "elephant", "the sunrise is so pretty")});
    //get<n> where n is the index is used to get the data from tuple
    
    int choice=0;
    string name;
    while (choice!=4){
        cout << "Menu" <<endl;
        cout << "1. Increase Friendship\n" << "2. Decrease Friendship\n" << "3. Search for Villager\n" << "4. Add Villager\n" << "5. Delete Villager\n"<<"6. Exit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1 :{
                cout << "Enter the name to increase friendship: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int level = get<0>(it->second);
                    if (level < 10) level++;
                    get<0>(it->second) = level;
                    cout << name << "'s friendship increased to " << level << "!\n";
                } 
                else {
                    cout << "Villager not found.\n";
                }
                printV(villagers);
                break;
            }
            case 2 :{
                cout << "Enter the name to decrease friendship: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int level = get<0>(it->second);
                    if (level > 0) level--;
                    get<0>(it->second) = level;
                    cout << name << "'s friendship decreased to " << level << "!\n";
                } 
                else {
                    cout << "Villager not found.\n";
                }
                printV(villagers);
                break;
            }
            case 3:{
                cout << "Enter the name to search for: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                cout << "\nFound " << name << "'s information: " << get<0>(it->second) << ", "<< get<1>(it->second) << ", "<< get<2>(it->second) << endl;
                } else
                cout << endl << name << " not found." << endl;
                printV(villagers);
                break;
            }
            case 4:{
                int level;
                string species, phrase;
                cout << "Name of villager: ";
                cin >> name;
                cout << "\nLevel of friendship: ";
                cin >> level;
                cout << "\nSpecies: ";
                cin >> species;
                cout << "\nA phrase that this villager will say: ";
                cin >> phrase;
                villagers[name] = make_tuple(level, species, phrase);
                printV(villagers);
                break;
            }
            case 5:{
                cout << "Enter name of the villager to remove: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                    villagers.erase(it);
                } 
                else{
                    cout << endl << name << " not found." << endl;
                }
                cout<<name<<" added!!"<< endl;
                cout<< endl;
                cout << "New list: " <<endl;
                printV(villagers);
                break;
            }
            
            case 6:{
                cout << "Exitting" << endl;
                break;
            }
    }

    return 0;
}
}
