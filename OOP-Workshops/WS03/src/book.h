/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "mediaItem.h"
#include <string>
namespace seneca{
   class Book : public MediaItem
	{
		std::string m_author{};
		std::string m_country{};
		double m_price{};

		Book(const std::string& author, const std::string& title, const std::string& country, unsigned short year, double price, const std::string& summary);

	public:
		void display(std::ostream& out) const override;
		static Book* createItem(const std::string& strBook);

	};
}
#endif //SENECA_BOOK_H