#pragma once
#include <string>

#include "Position.h"
#include "Types.h"

namespace Santorini
{
    class Builder
    {
    public:
        Builder(const std::string& _name, Position _position, Santorini::Blocks _level) :
            m_name(_name),
            m_position(_position),
            m_level(_level)
        {}
        ~Builder();

        std::string& getName() { return m_name; }

        void move(const Santorini::Direction& _direction);
        void build(const Santorini::Direction& _direction);

    private:
        std::string m_name;
        Position m_position;
        Santorini::Blocks m_level;
    };
}

