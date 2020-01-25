#include "pch.h"
#include "GameManager.h"

#include <iostream>
#include <string>

#include "Player.h"
#include "Position.h"
#include "Builder.h"

namespace Santorini
{
    GameManager* GameManager::s_instance = nullptr;

    GameManager::GameManager()
    {
        s_instance = this;
    }


    GameManager::~GameManager()
    {
        s_instance = nullptr;
    }

    void GameManager::update()
    {
        m_board.initialize();

        std::cout << "Santorini\n";
        m_board.draw();

        std::cout << "Enter player 1 name: ";
        std::string player1Name;
        std::cin >> player1Name;
        Player player1 = Player(player1Name);

        std::cout << "Enter player 2 name: ";
        std::string player2Name;
        std::cin >> player2Name;
        Player player2 = Player(player2Name);

        m_players.push_back(player1);
        m_players.push_back(player2);
        setCurrentPlayer();

        while (true)
        {
            std::cout << m_currentPlayer.getName() + " turn.\n Place builders. Enter 2 numbers (0:4) for builder1 position and 2 (0:4) numbers for builder2 position:\n";

            int x1, x2, y1, y2;
            std::cin >> x1 >> y1;
            std::cin >> x2 >> y2;


            m_currentPlayer.placeBuilders(Position(x1, y1), Position(x2, y2));
            m_board.draw();

            //TODO refactor this to identify builders better, maybe just by index
            std::cout << m_currentPlayer.getName() + ", enter 1 or 2 to choose builder1 or builder2.";
            int builderNumber;
            std::cin >> builderNumber;
            std::string builderName;
            if (builderNumber == 1)
            {
                builderName = m_currentPlayer.getBuilder1Name();
            }
            else if (builderNumber == 2)
            {
                builderName = m_currentPlayer.getBuilder2Name();
            }

            std::cout << "Move " + builderName + " to adjacent position. Enter direction (Left, Right, Up, Down, LeftUp, LeftDown, RightUp, RightDown):";
            std::string inputDirection;
            std::cin >> inputDirection;
            Builder* builder = m_currentPlayer.getBuilder(builderName);
            if (builder != nullptr)
            {
                Santorini::EnumParser<Santorini::Direction> parser;
                Santorini::Direction direction = parser.ParseEnum(inputDirection);
                builder->move(direction);
                m_board.draw();

                std::cout << m_currentPlayer.getName() + ", build with Builder 1 (B1) to adjacent position. Enter direction (Left, Right, Up, Down, LeftUp, LeftDown, RightUp, RightDown):";
                std::cin >> inputDirection;
                direction = parser.ParseEnum(inputDirection);
                builder->build(direction);
                m_board.draw();

                m_counter++;
                setCurrentPlayer();
            }
        }
    }

    void GameManager::updateBoardCell(const Position & _position, const std::string & _type, const Santorini::Blocks & _block)
    {
        m_board.setCell(_position, _type, _block);
    }

    GameManager * GameManager::get()
    {
        return s_instance;
    }

    void GameManager::setCurrentPlayer()
    {
        if (m_counter % 2 == 0)
        {
            m_currentPlayer = m_players[0];
        }
        else
        {
            m_currentPlayer = m_players[1];
        }
    }

    static void checkVictory()
    {
    }
}
