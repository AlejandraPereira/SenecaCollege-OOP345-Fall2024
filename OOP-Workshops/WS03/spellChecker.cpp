/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "spellChecker.h"
namespace seneca{

    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            throw "Bad file name!";
        }
        std::string line;
        int i = 0;
        for (int j = 0; j < NUM_WORDS; ++j) {
            m_badWords[j] = "";
            m_goodWords[j] = "";
            m_replacementCount[j] = 0;
        }
       while (std::getline(file, line) && i < NUM_WORDS) {
			std::istringstream iss(line);
			std::string badWord, goodWord;
			iss >> badWord >> goodWord; 
			m_badWords[i] = badWord;
			m_goodWords[i] = goodWord;
			i++;
		}
       
    }
    
    //replaces any misspelled word with the correct version
    void SpellChecker::operator()(std::string& text)
	{
		for (auto i = 0; i < 6; i++)
		{
			size_t idx = 0;

			while ((idx = text.find(m_badWords[i], idx)) != std::string::npos)
			{
				text.replace(idx, m_badWords[i].length(), m_goodWords[i]);

				idx += m_goodWords[i].length();
				m_replacementCount[i]++;
			}
		}
	}

    // Display the statistics
    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < NUM_WORDS; ++i) {
            if (!m_badWords[i].empty()) { 
                out << std::left << std::setw(15) << m_badWords[i] << ": " 
                    << m_replacementCount[i] << " replacements" << std::endl;
            }
        }
    }
} 