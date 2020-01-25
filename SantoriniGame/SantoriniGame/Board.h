#pragma once

#include <vector>
#include "Types.h"

namespace Santorini
{
    class Position;

    class Board
    {
    public:
        Board();
        ~Board();

        void initialize();
        void clear();
        void draw();
        //Maybe use template or something better instead of void*, Enum....
        void setCell(const Position& _position, const std::string&  _type, const Santorini::Blocks& _level);
        std::pair<std::string, std::string> getCell(int x, int y) const;

    private:
        const int width = 5;
        std::vector<std::vector<std::pair<std::string, std::string>>> m_board;
    };
}

