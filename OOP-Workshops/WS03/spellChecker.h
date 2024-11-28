/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
#include <string>
#include <array>
#define NUM_WORDS 6
namespace seneca{
    class SpellChecker{
        std:: string  m_badWords[NUM_WORDS];
        std:: string m_goodWords[NUM_WORDS];
        std::array<int, NUM_WORDS> m_replacementCount;// Keep track of replacements

    public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif //SENECA_SPELLCHECKER_H