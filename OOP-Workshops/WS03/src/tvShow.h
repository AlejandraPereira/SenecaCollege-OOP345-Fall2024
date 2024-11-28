/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include "mediaItem.h"
#include "collection.h"

namespace seneca
{
    class TvShow;

    struct TvEpisode
    {
        const TvShow* m_show{};
        unsigned short m_numberOverall{};
        unsigned short m_season{};
        unsigned short m_numberInSeason{};
        std::string m_airDate{};
        unsigned int m_length{};
        std::string m_title{};
        std::string m_summary{};
    };

    class TvShow : public MediaItem
    {
        std::string m_id;
        std::vector<TvEpisode> m_episodes;

        TvShow(const std::string& id, const std::string& title, unsigned short year, const std::string& summary);

    public:
        static TvShow* createItem(const std::string& strShow);

        template<typename Collection_t>
        static void addEpisode(Collection_t& col, const std::string& strEpisode);

        void display(std::ostream& out) const override;
        double getEpisodeAverageLength() const;
        std::list<std::string> getLongEpisodes() const;
    };
    // add Episode 
    template<typename Collection_t>
    void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode)
    {
        if (strEpisode.empty() || strEpisode[0] == '#')
        {
            throw "Not a valid episode.";
        }

        std::istringstream iss(strEpisode);
        std::string id;
        std::string token;
        std::string tokens[8];
        size_t idx = 0;
        TvShow* show = nullptr;

        while (idx < 7 && std::getline(iss, token, ','))
        {
            MediaItem::trim(token);
            tokens[idx++] = token;
        }

        std::getline(iss, tokens[idx]);
        MediaItem::trim(tokens[idx]);
        idx++;

        if (idx != 8)
        {
            throw "Not a valid episode.";
        }

        id = tokens[0];
        for (size_t i = 0; i < col.size() && show == nullptr; i++)
        {
            show = dynamic_cast<TvShow*>(col[i]);
            if (show->m_id != id)
            {
                show = nullptr;
            }
        }

        if (show)
        {
            auto timeToSeconds = [](const std::string& time)
                {
                    std::istringstream iss(time);
                    std::string token;
                    int hours = 0, minutes = 0, seconds = 0;

                    if (std::getline(iss, token, ':')) hours = std::stoi(token);
                    if (std::getline(iss, token, ':')) minutes = std::stoi(token);
                    if (std::getline(iss, token)) seconds = std::stoi(token);

                    return hours * 3600 + minutes * 60 + seconds;
                };

            TvEpisode episode = { show, // show
            static_cast<unsigned short>(std::stoi(tokens[1])), // number overall
            static_cast<unsigned short>(tokens[2].empty() ? 1 : std::stoi(tokens[2])), //  for the season
            static_cast<unsigned short>(std::stoi(tokens[3])), // The number in season
            tokens[4], // The air date
            static_cast<unsigned int>(timeToSeconds(tokens[5])), // the length of show
            tokens[6], // the title
            tokens[7] }; // the summary

            show->m_episodes.push_back(episode);
        }

    };

} 

#endif //SENECA_TVSHOW_H