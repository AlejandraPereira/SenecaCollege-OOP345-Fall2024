/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>

namespace seneca
{
    enum class PartOfSpeech {
        Unknown,
        Noun,
        Verb,
        Adjective,
        Adverb,
        Preposition,
        Pronoun,
        Conjunction,
        Interjection
    };

    struct Word {
        std::string word;         
        std::string definition;   
        PartOfSpeech pos;       
    };

    class Dictionary {
    private:
        Word* m_words;   
        size_t m_size;   

    public:
        // Constructors and destructor
        Dictionary();
        Dictionary(const char* filename);
        Dictionary(const Dictionary& src);           // Copy constructor
        Dictionary& operator=(const Dictionary& src); // Copy assignment operator
        Dictionary(Dictionary&& src) noexcept;       // Move constructor
        Dictionary& operator=(Dictionary&& src) noexcept; // Move assignment operator
        ~Dictionary();

        // Member functions
        void searchWord(const char* word);
        PartOfSpeech getPosFromString(const std::string& strPos); 
    };
}

#endif // SENECA_DICTIONARY_H
