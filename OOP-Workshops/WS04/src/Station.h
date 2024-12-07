/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>

namespace seneca
{
	class Station
	{
		int m_id{};
		std::string m_name{};
		std::string m_desc{};
		unsigned int m_serial{};
		size_t m_stock{};

		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station();
		Station(const std::string& record);
		virtual ~Station();
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};

}

#endif