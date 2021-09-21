#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "random"
using namespace std;

string input;
vector<string> srcWords = {"apple", "markup", "watchdog", "orange", "programmer", "hushbringer"};
string srcWord;
string outWord;
int score = 0;
string toStart;
bool toContinue = true;
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
    cout << "I'll show you a jumbled word, you have to guess the word and write it" << endl;
    cout << "You get 10 points if your guess is right and -5 if isn't ";
    cout << "(and yes, you can get a negative score, it's not a bug, it's a feature)" << endl;
    cout << "If your guess is correct, but you used hints, your score will be increased by 10 minus <the number of hints>" << endl;
    cout << "You can use hints only three times for each word" << endl;
    cout << "Do you want to try? (write \"n\" to exit or any other key to start): ";
    cin >> toStart;
    return toStart != "n";
}

void print() {
    system("clear");
    cout << "Try to unjumble the word" << endl; // print()
    cout << "To exit write \"exit\"" << endl;
    cout << "To show a hint write \"hint\"" << endl;
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
        cout << "You get 10 points" << endl;
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
        while (toContinue) {
            print();
            switch (control()) {
                case 0:
                    toContinue = true;
                    score = score - 5;
                    break;
                case 1:
                    toContinue = false;
                    startFlag = false;
                    break;
            }
            break;
        }
    }
    return 0;
}