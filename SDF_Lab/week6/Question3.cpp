#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class ThroneInheritance {
private:
    string king;
    unordered_map<string, vector<string>> children; // parent → children
    set<string> dead; // store dead people

    // DFS to generate inheritance order
    void dfs(string person, vector<string> &order) {
        if (dead.find(person) == dead.end()) {
            order.push_back(person); // include only if alive
        }

        // visit children in birth order
        for (string child : children[person]) {
            dfs(child, order);
        }
    }

public:
    // Constructor
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    // Birth
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }

    // Death
    void death(string name) {
        dead.insert(name);
    }

    // Get Inheritance Order
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};

int main() {
    // Step 1: Initialize kingdom
    ThroneInheritance kingdom("King");

    // Step 2: Add family members
    kingdom.birth("King", "Charles");
    kingdom.birth("King", "Anne");
    kingdom.birth("Charles", "William");
    kingdom.birth("William", "George");

    // Step 3: Display inheritance order
    cout << "Current Inheritance Order:\n";
    vector<string> order1 = kingdom.getInheritanceOrder();
    for (string name : order1) {
        cout << name << " ";
    }
    cout << endl;

    // Step 4: Mark a person as dead
    kingdom.death("Charles");

    // Step 5: Display updated inheritance order
    cout << "Updated Inheritance Order:\n";
    vector<string> order2 = kingdom.getInheritanceOrder();
    for (string name : order2) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}