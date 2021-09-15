#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "random"
using namespace std;

string input;
bool f;
vector<string> srcWords = {"apple", "markup", "watchdog"};
string srcWord;
string outWord;

void print() {
    system("clear");
    cout << "Try to find the premordial word(to exit write \"exit\")" << endl;
    cout << "The encrypted word is " << outWord << endl;
    cout << "Enter your guess ";
    cin >> input;
}

bool control() {
    if (input == "exit") return true;
    else if (input == srcWord) {
        cout << "You're right!" << endl;
        return true;
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(srcWords.begin(), srcWords.end());
    srcWord = srcWords[0];
    outWord = srcWord;
    random_shuffle(outWord.begin(), outWord.end());
    while (!f) {
        print();
        f = control();  
    }
    return 0;
}