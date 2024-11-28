/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#include "collection.h"
#include <algorithm>
#include <iostream>
namespace seneca
{
    Collection::Collection(const std::string& name)
    : m_name(name), m_observer(nullptr) {};

    //  cleans allocated MediaItems
    Collection::~Collection() {
        for (auto item : m_items) {
            delete item;
        }
    }

    // Get the name of the collection
    const std::string& Collection::name() const {
        return m_name;
    }

    // Get the size of the collection
    size_t Collection::size() const {
        return m_items.size();
    }

    // Set the observer callback function
    void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
        m_observer = observer;
    }

    // Add item to collection, ensuring no duplicates
    Collection& Collection::operator+=(MediaItem* item) {
        if (!item) return *this;

        // Check for duplicates by title
        bool it = std::any_of(m_items.begin(), m_items.end(), [item](const MediaItem* originItem)
			{
				return originItem->getTitle() == item->getTitle();
			});

        if (it) {
            delete item; // Item already exists, discard the new item

        }else{
             // Add the item to the collection
             m_items.push_back(item);
        
            // If observer exists, notify about the new item
            if (m_observer) {
                m_observer(*this, *item);
            }
        }

        return *this;
    }

    // Access item by index
    MediaItem* Collection::operator[](size_t idx) const {
        if (idx >= m_items.size()) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) +
                                    "]. Collection has [" + std::to_string(m_items.size()) + "] items.");
        }
        return m_items[idx];
    }

    // Access item by title
    MediaItem* Collection::operator[](const std::string& title) const {
        MediaItem* other = nullptr;

		// Find item withe matching title
		auto address = std::find_if(m_items.begin(), m_items.end(), [title](const MediaItem* item)
			{
				return item->getTitle() == title;
			});

		if (address != m_items.end())
		{
			other = *address;
		}

		return other;
	}

    // Remove quotes from all items titles and summaries
    void Collection::removeQuotes()
	{
		std::for_each(m_items.begin(), m_items.end(), [](MediaItem* item)
			{
				std::string title = item->getTitle();
				std::string summary = item->getSummary();

				// remove for title
				if (!title.empty() && title.front() == '"')
				{
					title.erase(0, 1);
				}
				if (!title.empty() && title.back() == '"')
				{
					title.erase(title.size() - 1);
				}

				// remove for summary
				if (!summary.empty() && summary.front() == '"')
				{
					summary.erase(0, 1);
				}
				if (!summary.empty() && summary.back() == '"')
				{
					summary.erase(summary.size() - 1);
				}
				
				// update title and summary
				item->setTitle(title);
				item->setSummary(summary);

			});

	}
    // Sort the collection by a given field (title, year, etc.)
    void Collection::sort(const std::string& field) {
        std::sort(m_items.begin(), m_items.end(), [&](const MediaItem* a, const MediaItem* b) {
            if (field == "title") {
                return a->getTitle() < b->getTitle();
            } else if (field == "year") {
                return a->getYear() < b->getYear();
            } else if (field == "summary") {
                return a->getSummary() < b->getSummary();
            }
            return false; // Default behavior if no valid field is specified
        });
    }

    // Insert the content of the collection into an ostream object
    std::ostream& operator<<(std::ostream& os, const Collection& collection) {
        std::for_each(collection.m_items.begin(), collection.m_items.end(), [&os](const MediaItem* item) {
            os << *item; 
        });
        return os;
    }
}
