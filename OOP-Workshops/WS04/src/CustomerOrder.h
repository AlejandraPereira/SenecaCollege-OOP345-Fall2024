/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include <vector>

namespace seneca {
    class Station; 
}

namespace seneca
{
    class CustomerOrder {
    private:
        struct Item {
            std::string m_itemName;
            size_t m_serialNumber{ 0 };
            bool m_isFilled{ false };

            Item(const std::string& src) : m_itemName(src) {}
        };

        std::string m_name;
        std::string m_product;
        size_t m_cntItem{ 0 };
        Item** m_lstItem{ nullptr };
        static size_t m_widthField;

    public:
        CustomerOrder() {};
        CustomerOrder(const std::string& record);
        CustomerOrder(const CustomerOrder& src); 
        CustomerOrder& operator=(const CustomerOrder& src) = delete; 
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;

    };
}


#endif 