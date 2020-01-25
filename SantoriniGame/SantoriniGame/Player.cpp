#include "pch.h"
#include "Player.h"

#include <algorithm>

#include "Builder.h"
#include "Position.h"
//#include "Board.h"

#include "GameManager.h"

namespace Santorini
{
    Player::Player()
    {
    }

    Player::Player(const std::string & _name)
    {
        m_name = _name;
        //m_board = GameManager::get()->getBoard();
    }

    Player::~Player()
    {
        //m_board = nullptr;
    }

    Builder * Player::getBuilder(const std::string & _name)
    {
        const auto it = std::find_if(m_builders.begin(), m_builders.end(), [&_name](Builder& obj) {return obj.getName() == _name; });
        if (it != m_builders.end())
        {
            auto index = std::distance(m_builders.begin(), it);

            return &m_builders[index];
        }
        return nullptr;
    }

    void Player::placeBuilders(const Position & _builder1Position, const Position & _builder2Position)
    {
        addBuilder(getBuilder1Name(), _builder1Position);
        addBuilder(getBuilder2Name(), _builder2Position);
    }

    void Player::addBuilder(const std::string & _name, const Position & _position)
    {
        GameManager::get()->updateBoardCell(_position, _name, Santorini::Ground);
        //m_builders.push_back(Builder(_name, _position, Santorini::Ground));
    }
}


