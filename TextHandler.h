#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include "templates.cpp"

class TextHandler {
    private:
        std::set<char>* characters;
        std::map<char, int>* charactersStatistics;
        std::set<char>* numbers;
        std::map<char, int>* numbersStatistics;
        std::set<char>* specialSymbols;
        std::map<char, int>* specialSymbolsStatistics;
        std::set<std::string>* words;
        std::map<std::string, int>* wordsStatistics;
        long long quantity;
        std::string lastWord;
        bool inWord;
        long long wordsQuantity;

        void insert(char symbol, std::set<char>* lst);
        void insert(char symbol, std::map<char, int>* lst);
        void insert(std::string word, std::set<std::string>* lst);
        void insert(std::string word, std::map<std::string, int>* lst);
        bool isDelimiter(char symbol);
        bool isLetter(char symbol);
        bool isNumber(char symbol);
        bool isSpecial(char symbol);
    public:
        TextHandler();
        ~TextHandler();
        
        const std::set<char>& getCharacters() const;
        const std::map<char, int>& getCharactersStatistics() const;
        const std::set<char>& getNumbers() const;
        const std::map<char, int>& getNumbersStatistics() const;
        const std::set<char>& getSpecialSymbols() const;
        const std::map<char, int>& getSpecialSymbolsStatistics() const;
        const std::set<std::string>& getWords() const;
        const std::map<std::string, int>& getWordsStatistics() const;
        const std::string getLastWord() const;
        long long getQuantity() const;
        long long getWordsQuantity() const;
        
        void setInWord();
        
        void parseText(std::ifstream& file);
};

std::ostream& operator<<(std::ostream& out, const TextHandler& handler);

#endif //TEXT_HANDLER_H