#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Word.h"

using namespace std;

int main()
{
    cout << "\t\tRandom Number Generator" << endl;
    cout << endl << "Random number generated.\t\tRange: [1-100]" << endl << endl;

    srand(time(NULL));

    int randomNum, guessNum;

    randomNum = rand()%100+1;
    for(guessNum = 0; guessNum != randomNum;)
    {
        while(! (cin >> guessNum))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, only integers allowed between [1-100]" << endl << "Enter again: ";
        }
        if(guessNum > randomNum)
            cout << "Think smaller. " << endl;
        else if(guessNum < randomNum)
            cout << "Go big or go home. " << endl;
        else
            break;

        cout << endl << "Guess again: ";
    }
    cout << "You have guessed correctly!" << endl;

    string category;
    switch(guessNum/10)
    {
        case 0:
            category = "[Presidents]";
            break;


        case 1:
            category = "[World Famous Athletes]";
            break;

        case 2:
            category = "[Sports Cars]";
            break;

        case 3:
            category = "[Leading Companies]";
            break;

        case 4:
            category = "[Sports]";
            break;

        case 5:
            category = "[Languages]";
            break;

        case 6:
            category = "[Scientists and Mathematicians]";
            break;

        case 7:
            category = "[Billionaires]";
            break;

        case 9:
            category = "[Hollywood Actors/Actresses]";
            break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;

    }

    ifstream inFile; inFile.open("Words.txt");
    string allWords[100];
    int counter = 0;

    while(inFile >> allWords[counter++]);

    for(int count = 0; count < 5; count++)
        cout << "test run " << allWords[count] << endl;

    Word yourWord(randomNum, allWords[randomNum]);
    yourWord.setCategory(category);
    int life = 6; int turn = 1;
    string line, astrices;
    line = "___________________________________________________________________________________\n";
    astrices ="***************************************************************************************\n";

    inFile.close();
    cout << endl << astrices << "Random word generated " << "\t\tCategory: " << category << endl << astrices;
    char guessChar; string guessed = "none";
    while(life && !yourWord.isComplete())
    {
        cout << line << "[Life: " << life << "]\t[Turn: " << turn << "]\t[Guessed Letters: " << guessed << "]" << endl;
        cout << endl << yourWord.getGuessed() << endl;

        if(guessed == "none")
            guessed = "";

        cout << "Guess a letter: "; cin >> guessChar;

        if(yourWord.characterMatch(guessChar))
        {
            if(yourWord.alreadyInserted(guessChar))
            {
                do{
                    cout << "You have already chosen this character. Try a different one. " << endl;
                    cout << "Guess another letter: "; cin >> guessChar;
                }while(yourWord.alreadyInserted(guessChar));
            }
        }
        else
        {
            cout << "Sorry, the letter does not match. " << endl;
            life--;
        }
        guessed+=guessChar;
        guessed+=" ";
        turn++;
        cout << line;
    }
    if(life)
        cout << "Congratulations! You have guessed the word correctly! " << endl;
    else
        cout << "Sorry! You have been hanged man. " << endl;

    cout << "Word: " << yourWord.getWord() << endl;

    return 0;
}
