#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "random"
using namespace std;

string input;
bool f;
vector<string> srcWords = {"apple", "markup", "watchdog", "orange", "programmer", "hushbringer"};
string srcWord;
string outWord;
int score = 0;
string toStart;
bool toContinue;
int hintCounter = 0;

void printRevealedWord(int num) {
    cout << "Revealed letters: ";
        for (int i = 0; i < num; i++) {
            cout  << srcWord[i];
        }
        cout << endl;
}

void printHint() {
    if (hintCounter > 3) {
        printRevealedWord(3);
    }
    else if (hintCounter) {
        printRevealedWord(hintCounter);
    }
}

bool sayHi() {
    system("clear");
    cout << "Hi, human!" << endl;
    cout << "I'll show you jumbled word, you have to understand what word it is and write it" << endl;
    cout << "Also you have the score, +10 points if your guess was right, -5 if wasn't";
    cout << "(and yes, you can get negative score, it's not a bug, it's the feature)" << endl;
    cout << "If you were right, but you used hint, to your score would be added 10 - number of hints" << endl;
    cout << "To show hint write \"hint\"(you can use hints only three times at each game iteration)" << endl;
    cout << "To exit write \"exit\"" << endl;
    cout << "Do you want to try? (write \"n\" to exit or something another to start): ";
    cin >> toStart;
    return toStart != "n";
}

void print() {
    system("clear");
    cout << "Try to find the premordial word(to exit write \"exit\")" << endl;
    cout << "To show hint write \"hint\"" << endl;
    printHint();
    cout << "Your score is " << score << endl;
    cout << "The encrypted word is " << outWord << endl;
    cout << "Enter your guess ";
    cin >> input;
}

int control() {
    if (input == "exit") return 1; // 1 code to exit
    else if (input == "hint") hintCounter++;
    else if (input == srcWord) {
        system("clear");
        cout << "You're right!" << endl;
        cout << "Get your 10 points" << endl;
        cout << "Do you want to continue playing?(y/n): ";
        string yesNo;
        cin >> yesNo;
        if (yesNo == "n") return 1;
        score = score + 10 - hintCounter;
        hintCounter = 0;
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
                case 0:
                    f = false;
                    score = score - 5;
                    break;
                case 1:
                    f = true;
                    startFlag = false;
                    break;
            }
            break;
        }
    }
    return 0;
}