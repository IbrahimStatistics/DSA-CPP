// Todo App

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H"; // Clear and move cursor to top-left
}

void action(char option){
    vector<string> task = {"No task"};
    string new_task;
    switch (option)
    {
    case 'a':
        getline(cin, new_task);
        task.push_back(new_task);
        break;
    
    case 'q':
        clearScreen();
        break;
    
    case 'r':
        int removal;
        cout << "Remove task : ";
        cin >> removal;
        

    default:
        break;
    }
}


int main(){
    cout << " ~ TO-DO List ~ "<<'\n';
    char option;
    // a : add, q : quit, r : remove
    cout << "Select Action" << endl;
    cout << "a : add" << endl;
    cout << "q : quit" << endl;
    cout << "r : remove" << endl;

    cout << "Selected : "; cin >> option;

    return 0;
}