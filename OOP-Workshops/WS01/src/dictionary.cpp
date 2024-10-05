/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "settings.h"
#include "dictionary.h"

using namespace std;

namespace seneca
{
    
    Dictionary::Dictionary() : m_words(nullptr), m_size(0){}

    // constructor that loads dictionary from a file
    Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_size(0){
        ifstream file(filename); // open the input file

        if (file.is_open())
        {
            string lineContent;
            size_t wordCount{ 0 };

            // count the number of lines in the file
            while (getline(file, lineContent))
            {
                wordCount++;
            }

            // reset file state and back to the beginning
            file.clear();
            file.seekg(0);

            m_words = new Word[wordCount];
            m_size = 0;

            //read each line from the file and store the word 
            while (getline(file, lineContent))
            {
                stringstream lineStream(lineContent);

                string currentWord, currentPartOfSpeech, currentDefinition;

                getline(lineStream, currentWord, ','); // extract word
                getline(lineStream, currentPartOfSpeech, ','); // extract part of speech
                getline(lineStream, currentDefinition); // extract definition

                // store the word, def, partOfSpeech
                m_words[m_size].word = currentWord;
                m_words[m_size].definition = currentDefinition;
                m_words[m_size].pos = getPosFromString(currentPartOfSpeech);

                m_size++;
            }
        }
    }

    Dictionary::Dictionary(const Dictionary& src)
    {
        m_size = src.m_size;

        if (m_size > 0) {
            m_words = new Word[m_size];
            for (size_t i = 0; i < m_size; ++i) {
                m_words[i] = src.m_words[i];
            }
        }
        else {
            m_words = nullptr;
        }
    }

    Dictionary& Dictionary::operator=(const Dictionary& src)
    {
        if (this != &src) // self-assignment check
        {
            if (m_words != nullptr)
            {
                delete[] m_words;
            }

            m_size = src.m_size;

            if (m_size > 0)
            {
                m_words = new Word[m_size];
                for (size_t i = 0; i < m_size; i++)
                {
                    m_words[i] = src.m_words[i];
                }
            }
            else
            {
                m_words = nullptr;
            }
        }

        return *this;
    }

    // move constructor
    Dictionary::Dictionary(Dictionary&& src) noexcept : m_words{ src.m_words }, m_size{ src.m_size }
    {
        src.m_words = nullptr;
        src.m_size = 0;
    }

    // move operator
    Dictionary& Dictionary::operator=(Dictionary&& src) noexcept
    {
        if (this != &src)
        {
            delete[] m_words;

            // shallow copy
            m_size = src.m_size;
            m_words = src.m_words;

            // nullify the source
            src.m_words = nullptr;
            src.m_size = 0;
        }

        return *this;
    }

  
    Dictionary::~Dictionary()
    {
        delete[] m_words;
    }

    // searching a word and display with definition and part of speech
    void Dictionary::searchWord(const char* word)
    {
        bool foundWord = false;
        size_t len = strlen(word);
        bool flag = true;

        // Iteration through the list of words to find a match
        for (size_t i = 0; i < m_size && flag; i++)
        {
            if (m_words[i].word == word) {
                if (!foundWord)
                {
                    cout << m_words[i].word;
                }
                else
                {
                    cout << setw(len + 3); 
                }

                cout << " - ";

                // check to display PartOfSpeech
                if (m_words[i].pos != PartOfSpeech::Unknown && g_settings.m_verbose)
                {
                    cout << "(";

                    switch (m_words[i].pos) {
                    case PartOfSpeech::Noun:
                        cout << "noun";
                        break;
                    case PartOfSpeech::Verb:
                        cout << "verb";
                        break;
                    case PartOfSpeech::Adjective:
                        cout << "adjective";
                        break;
                    case PartOfSpeech::Adverb:
                        cout << "adverb";
                        break;
                    case PartOfSpeech::Preposition:
                        cout << "preposition";
                        break;
                    case PartOfSpeech::Pronoun:
                        cout << "pronoun";
                        break;
                    case PartOfSpeech::Interjection:
                        cout << "interjection";
                        break;
                    case PartOfSpeech::Conjunction:
                        cout << "conjunction";
                        break;
                    default:
                        break;
                    }

                    cout << ") ";
                }

                cout << m_words[i].definition << endl;
                foundWord = true;
                if (!g_settings.m_show_all)
                {
                    flag = false; // stop is there is no more definitions
                }
            }
        }
        if (!foundWord)
        {
            cout << "Word '" << word << "' was not found in the dictionary." << endl;
        }
    }

    // converting the part of speech from a string and return the enum value
    PartOfSpeech Dictionary::getPosFromString(const std::string& strPos)
    {
        PartOfSpeech pos = PartOfSpeech::Unknown;

        if (strPos == "n." || strPos == "n.pl.")
        {
            pos = PartOfSpeech::Noun;
        }
        else if (strPos == "adv.")
        {
            pos = PartOfSpeech::Adverb;
        }
        else if (strPos == "a.")
        {
            pos = PartOfSpeech::Adjective;
        }
        else if (strPos == "v." || strPos == "v. i." || strPos == "v. t." || strPos == "v. t. & i.")
        {
            pos = PartOfSpeech::Verb;
        }
        else if (strPos == "prep.")
        {
            pos = PartOfSpeech::Preposition;
        }
        else if (strPos == "pron.")
        {
            pos = PartOfSpeech::Pronoun;
        }
        else if (strPos == "conj.")
        {
            pos = PartOfSpeech::Conjunction;
        }
        else if (strPos == "interj.")
        {
            pos = PartOfSpeech::Interjection;
        }

        return pos;
    }
}
