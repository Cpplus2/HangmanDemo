#ifndef WORD_H
#define WORD_H
#include <string>

using namespace std;

class Word
{
    private:
        string word;
        char *guess;
        string category;
        int wordNum;
        int wordSize;
        bool complete;

    public:
        ~Word();
        Word(int);
        Word(string);
        Word(int, string);
        Word();
        string getWord();
        void setWord(string);
        void setNum(int);
        int getNum();
        void setCategory(string);
        string getCategory();
        bool characterMatch(char);
        void setGuessString(int);
        void setGuessString();
        void insertCharacter(char);
        bool isComplete();
        bool alreadyInserted(char);
        string getGuessed();
};;
#endif // WORD_H
