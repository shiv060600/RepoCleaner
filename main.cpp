#include <iostream>
#include <ostream>
#include <string>
#include "CleanerClass/CleanerDefiner.h"
using namespace std;

int main() {
    string instructionOne = "Please enter root directory you want cleaned ex. C:\\dir";
    cout << instructionOne << endl;
    string rootDir;
    cin >> rootDir;

    string removalKey;
    cout << "please enter the removal_key (part of string you want removed) ex: ._ " << endl;
    cin >> removalKey;

    string removalType;
    cout << "Please enter the type of removal Examples:" << endl;
    cout << "for starts with, please enter A: starts_with: removes any file or dir starting with removal_key" <<endl;
    cout << "for ends with, please enter B: ends_with: removes any file or dir ending with removal_key"<<endl;
    cout << "for contains, please enter C: containts: removes any file or dir that contains removal_key"<<endl;
    cin >> removalType;

    CodeCleaner dirCleaner(rootDir,removalType,removalKey);

    cout << "Beginning the cleaner" << endl;

    dirCleaner.Clean();

    cout << "Finished the cleaner" <<endl;

    return 0;
}
