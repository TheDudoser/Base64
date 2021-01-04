#include <iostream>
#include "Base64_lib.h"
#include <vector>
#include <string>

using namespace std;

int main() {
    string message;
    vector<int> vec;
    short choice;
    do {
        cout << "Codding or deccoding? 1/2:" << endl;
        cin >> choice;
        cin.ignore();
    } while ((choice != 1) && (choice != 2));
    cout << "Enter message:" << endl;
    getline(cin, message);
    if (choice == 1) {
        //message = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
        //message = "la";
        cout << codingMessage(vec, message) << endl;
    } else {
        //string message2 = "bGE=";
        //message = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
        cout << DecodingMessage(message) << endl;
    }
    return 0;
}