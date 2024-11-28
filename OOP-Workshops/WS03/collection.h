/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <string>
#include <vector>
#include <stdexcept>
#include "mediaItem.h"

namespace seneca {

    class Collection {
        std::string m_name;
        std::vector<MediaItem*> m_items;
        void (*m_observer)(const Collection&, const MediaItem&) = nullptr;

    public:
        // Constructor
        explicit Collection(const std::string& name);
        ~Collection();

        // Deleted Copy and Move Operations
        Collection(const Collection&) = delete;
        Collection(Collection&&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection& operator=(Collection&&) = delete;

        //Member Functions
        const std::string& name() const;
        size_t size() const;
        void setObserver(void (*observer)(const Collection&, const MediaItem&));
        Collection& operator+=(MediaItem* item);
        MediaItem* operator[](size_t idx) const;
        MediaItem* operator[](const std::string& title) const;
        void removeQuotes();
        void sort(const std::string& field);

        // Overload insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Collection& collection);

         
    };

}
#endif // SENECA_COLLECTION_H