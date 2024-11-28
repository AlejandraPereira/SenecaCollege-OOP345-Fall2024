/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
namespace seneca
{
    struct Settings
    {
        int m_maxSummaryWidth {80};
        bool m_tableView {false};
    };
    extern Settings g_settings;
} 
#endif //SENECA_SETTINGS_H