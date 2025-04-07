#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    int index;

    // Input string
    cout << "Enter the string: ";
    cin >> s;

    // Input index
    cout << "Enter the index: ";
    cin >> index;

    // Validate index
    if (index < 0 || index >= s.length()) {
        cout << "Invalid index!" << endl;
        return 1;
    }

    // Create final string
    string finalString = s.substr(index + 1) + s.substr(0, index+1 );

    // Print the final string
    cout << "Final string: " << finalString << endl;

    // Count occurrences of each character
    unordered_map<char, int> freq;
    for (char c : finalString) {
        freq[c]++;
    }

    // Print occurrences
    cout << "Character occurrences:" << endl;
    for (auto it : freq) {
        cout << it.first << ": " << it.second << endl;
    }

    return 0;
}
