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
int score = 0;
string toStart;
bool toContinue;

bool sayHi() {
    system("clear");
    cout << "Hi, human!" << endl;
    cout << "I'll show you jumbled word, you have to understand what word it is and write it" << endl;
    cout << "Also you have the score, +10 points if your guess was right, -5 if wasn't";
    cout << "(and yes, you can get negative score, it's not a bug, it's the feature)" << endl;
    cout << "Do you want to try? (y/n): ";
    cin >> toStart;
    if (toStart == "n") return false;
    return true;
}

void print() {
    system("clear");
    cout << "Try to find the premordial word(to exit write \"exit\")" << endl;
    cout << "Your score is " << score << endl;
    cout << "The encrypted word is " << outWord << endl;
    cout << "Enter your guess ";
    cin >> input;
}

int control() {
    if (input == "exit") return 1; // 1 code to exit
    else if (input == srcWord) {
        system("clear");
        cout << "You're right!" << endl;
        cout << "Do you want to continue playing?(y/n): ";
        string yesNo;
        cin >> yesNo;
        if (yesNo == "n") return 1;
        score = score + 10;
        return 2; // 2 code to start new iteration
    }
    return 0; // 0 code to continue
}

int main() {
    bool startFlag = sayHi();
    while (startFlag) {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(srcWords.begin(), srcWords.end());
        srcWord = srcWords[0];
        outWord = srcWord;
        random_shuffle(outWord.begin(), outWord.end());
        while (!f) {
            print();
            switch (control()) {
                case 0: f = false; score = score - 5; break;
                case 1: f = true; startFlag = false; break;
            }
            break;
        }
    }
    return 0;
}