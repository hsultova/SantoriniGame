#pragma once
#include <vector>
#include <string>

#include "Builder.h"
#include "Position.h"
namespace Santorini
{
    class Player
    {
    public:
        Player();
        Player(const std::string& _name);
        ~Player();

        const std::string& getName() const { return m_name; }
        Builder* getBuilder(const std::string& _name);

        const std::string getBuilder1Name() const { return m_name + ":B1"; }
        const std::string getBuilder2Name() const { return m_name + ":B2"; }

        void placeBuilders(const Position& _builder1Position, const Position& _builder2Position);

        void addBuilder(const std::string& _name, const Position & _position);

    private:
        std::string m_name;
        //Board* m_board;
        std::vector<Santorini::Builder> m_builders;
    };
}

