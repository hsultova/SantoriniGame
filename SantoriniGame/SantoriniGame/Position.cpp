#include "pch.h"
#include "Position.h"

namespace Santorini
{
    Position::Position()
    {
        m_x = 0;
        m_y = 0;
    }

    Position::Position(int _x, int _y)
    {
        m_x = _x;
        m_y = _y;
    }


    Position::~Position()
    {
    }
}
