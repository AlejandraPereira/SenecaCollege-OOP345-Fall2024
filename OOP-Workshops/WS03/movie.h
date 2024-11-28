/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include "mediaItem.h"
#include <string>
namespace seneca
{
	class Movie : public MediaItem
	{
		Movie(const std::string& title, unsigned short year, const std::string& summary);

	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};


}
#endif //SENECA_MOVIE_H