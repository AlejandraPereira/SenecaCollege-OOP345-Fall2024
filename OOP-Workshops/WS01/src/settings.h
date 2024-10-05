/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#ifndef SENECA_SETTINGS_H 
#define SENECA_SETTINGS_H

#include <string>

namespace seneca {
    struct Settings {
        bool m_show_all;
        bool m_verbose;
        std::string m_time_units;
    };

    extern Settings g_settings; 
}

#endif // SENECA_SETTINGS_H
