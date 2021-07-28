#ifndef WORD_CPP
#define WORD_CPP
#include "Word.h"

Word::Word()
{
    wordNum = 0;
    word = "";
    guess = new char[1];
    wordSize - 0;
}

Word::Word(int num)
{
    wordNum = num;
    word = "";
    guess = new char[1];
}

Word::Word(int num, string newWord)
{
    wordNum = num;
    word = newWord;
    guess = new char[word.size()];
    setGuessString();
    wordSize = word.size();
}

Word::Word(string newWord)
{
    word = newWord;
    wordNum = 0;
    guess = new char[word.size()];
    setGuessString();
    wordSize = word.size();
}

Word::~Word()
{
    word = "";
    wordNum = 0;
    category = "";
    delete [] guess;
}

void Word::setWord(string newWord)
{
    word = newWord;
}

string Word::getWord()
{
    return word;
}

void Word::setCategory(string newCategory)
{
    category = newCategory;
}

string Word::getCategory()
{
    return category;
}

void Word::setGuessString()
{
    int count;
    for(count = 0; count < word.size(); count++)
        guess[count] = '_';

    guess[count] = '\0';
}

void Word::setGuessString(int size)
{
    guess = new char[size];
}

void Word::setNum(int num)
{
    wordNum = num;
}

bool Word::alreadyInserted(char guessed)
{
    for(int count = 0; count < wordSize; count++)
        if(guess[count] == guessed)
            return true;
}

bool Word::characterMatch(char guessed)
{
    for(int count = 0; count < wordSize; count++)
        if(guessed == word[count])
            return true;

    return false;
}

void Word::insertCharacter(char guessChar)
{
    int count;
    for(count = 0; count < wordSize; count++)
        if(word[count] == guessChar)
            guess[count] = guessChar;

    for(count = 0; count < wordSize; count++)
        if(guess[count] == '_')
            return;

    complete = true;
}

bool Word::isComplete()
{
    return complete;
}

string Word::getGuessed()
{
    string temp = guess;
    return temp;
}

#endif // WORD_CPP
