#include "pch.h"
#include "Builder.h"

#include "GameManager.h"
#include "Types.h"
//#include "Board.h"
#include "Position.h"

namespace Santorini
{
    Builder::~Builder()
    {
    }

    void Builder::move(const Santorini::Direction& _direction)
    { 
        //Todo check if GameManager exists
        Santorini::EnumParser<Santorini::Blocks> parser;
        GameManager::get()->updateBoardCell(m_position, ToString(Santorini::Empty), parser.ParseEnum(GameManager::get()->getBoard()->getCell(m_position.getX(), m_position.getY()).second));
        switch (_direction)
        {
        case Santorini::Up:
            m_position.setX(m_position.getY() - 1);
            break;
        case Santorini::Down:
            m_position.setX(m_position.getY() + 1);
            break;
        case Santorini::Left:
            m_position.setY(m_position.getX() - 1);
            break;
        case Santorini::Right:
            m_position.setY(m_position.getX() + 1);
            break;
        case Santorini::LeftUp:
            m_position.setX(m_position.getX() - 1);
            m_position.setY(m_position.getY() - 1);
            break;
        case Santorini::LeftDown:
            m_position.setX(m_position.getX() - 1);
            m_position.setY(m_position.getY() + 1);
            break;
        case Santorini::RightUp:
            m_position.setX(m_position.getX() + 1);
            m_position.setY(m_position.getY() - 1);
            break;
        case Santorini::RightDown:
            m_position.setX(m_position.getX() + 1);
            m_position.setY(m_position.getY() + 1);
            break;
        }

        //Use cell blocks from the board
        GameManager::get()->updateBoardCell(m_position, m_name, parser.ParseEnum(GameManager::get()->getBoard()->getCell(m_position.getX(), m_position.getY()).second));
    }

    void Builder::build(const Santorini::Direction& _direction)
    {
        Position buildPosition;
        switch (_direction)
        {
        case Santorini::Up:
            buildPosition.setX(m_position.getY() - 1);
            break;
        case Santorini::Down:
            buildPosition.setX(m_position.getY() + 1);
            break;
        case Santorini::Left:
            buildPosition.setY(m_position.getX() - 1);
            break;
        case Santorini::Right:
            buildPosition.setY(m_position.getX() + 1);
            break;
        case Santorini::LeftUp:
            buildPosition.setX(m_position.getX() - 1);
            buildPosition.setY(m_position.getY() - 1);
            break;
        case Santorini::LeftDown:
            buildPosition.setX(m_position.getX() - 1);
            buildPosition.setY(m_position.getY() + 1);
            break;
        case Santorini::RightUp:
            buildPosition.setX(m_position.getX() + 1);
            buildPosition.setY(m_position.getY() - 1);
            break;
        case Santorini::RightDown:
            buildPosition.setX(m_position.getX() + 1);
            buildPosition.setY(m_position.getY() + 1);
            break;
        }

        //TODO Replace with better solution. Remove converting to int and back to enum.
        Santorini::EnumParser<Santorini::Blocks> parser;
        Santorini::Blocks block = parser.ParseEnum(GameManager::get()->getBoard()->getCell(m_position.getX(), m_position.getY()).second);
        int blockInt = ToInt(block);
        blockInt++;

        Santorini::Blocks newBlock = parser.ParseFromInt(blockInt);
        //Todo check if GameManager exists
        GameManager::get()->updateBoardCell(buildPosition, ToString(Santorini::Empty), newBlock);
    }

    static bool isValidPosition(const Santorini::Blocks _level)
    {
    }
}

