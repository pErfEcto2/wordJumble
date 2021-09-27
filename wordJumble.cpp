#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "random"
using namespace std;

string input; // string for an input information
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
    cout << "Try to unjumble the word" << endl;
    cout << "To exit write \"exit\"" << endl;
    cout << "To show a hint write \"hint\"" << endl;
    printRevealedWord(hintCounter);
    cout << "Your score is " << score << endl;
    cout << "The encrypted word is " << outWord << endl;
    cout << "Enter your guess ";
    cin >> input;
}

int control() {
    if (input == "exit") return 1; // 1 code to exit
    else if (input == "hint") {
        if (hintCounter < 3) hintCounter++; // increase hintCounter unless hintCounter < 3
    }
    else if (input == srcWord) { // if user's guess is right
        system("clear"); // clear an user's display
        cout << "You're right!" << endl;
        cout << "You get " << (10 - hintCounter) << " points" << endl;
        cout << "Do you want to continue playing?(y/n): ";
        string yesNo;
        cin >> yesNo;
        if (yesNo == "n") return 1; // 1 code to exit
        score = score + 10 - hintCounter;
        hintCounter = 0;
        return 2; // 2 code to start a new game iteration
    }
    return -1; // -1 code to continue
}

int main() {
    bool startFlag = sayHi();
    while (startFlag) {
        srand(static_cast<unsigned int>(time(0))); // seed the random
        random_shuffle(srcWords.begin(), srcWords.end());
        srcWord = srcWords[0]; // choose first word from the random shuffled vector
        outWord = srcWord; // define the copy
        random_shuffle(outWord.begin(), outWord.end()); // shuffle the copy
        toContinue = true;
        while (toContinue) {
            print(); // prints gamefield
            switch (control()) {
                case 2: // if user's guess was right
                    toContinue = false;
                    break;
                case 1: // if user wants to exit
                    toContinue = false;
                    startFlag = false;
                    break;
            }
        }
    }
    return 0;
}