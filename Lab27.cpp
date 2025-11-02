#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printV (const map<string, tuple<int, string, string>> villagers){
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
    // access the map using a range-based for loop
    
    int choice=0;
    string name;
    cout << "Menu" <<endl;
    cout << "1. Increase Friendship\n" << "2. Decrease Friendship\n" << "3. Search for Villager\n" << "4. Exit" <<endl;
    cin >> choice;
    while (choice!=4){
        cout << "Menu" <<endl;
        cout << "1. Increase Friendship\n" << "2. Decrease Friendship\n" << "3. Search for Villager\n" << "4. Exit" <<endl;
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
                string searchKey = name;
                auto it = villagers.find(searchKey);
                if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                cout << "\nFound " << searchKey << "'s information: " << get<0>(it->second) << ", "<< get<1>(it->second) << ", "<< get<2>(it->second) << endl;
                } else
                cout << endl << searchKey << " not found." << endl;
                printV(villagers);
            }
            case 4:{
                cout << "Exitting" << endl;
                break;
            }
    }

    cout << "\nVillagers and their informations (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": " << get<0>(it->second) << ", "<< get<1>(it->second) << ", "<< get<2>(it->second) << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s information: " << get<0>(it->second) << ", "<< get<1>(it->second) << ", "<< get<2>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;
    return 0;
}
}
