#include <iostream>
using namespace std;

// Function to expand around center and find longest palindrome
string expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindrome
        string odd = expandFromCenter(s, i, i);
        
        // Even length palindrome
        string even = expandFromCenter(s, i, i + 1);
        
        // Update longest palindrome
        if (odd.length() > longest.length()) longest = odd;
        if (even.length() > longest.length()) longest = even;
    }
    
    return longest;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    cout << "Longest Palindromic Substring: " << longestPalindrome(str) << endl;
    
    return 0;
}
