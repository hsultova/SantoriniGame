#pragma once

#include <vector>
#include <string>

#include "Board.h"
#include "Player.h"
#include "Types.h"
#include "Position.h"

//class Position;
namespace Santorini
{
    class GameManager
    {
    public:
        GameManager();
        ~GameManager();

        Board* getBoard() { return &m_board; }
        void update();
        void updateBoardCell(const Position& _position, const std::string&  _type, const Santorini::Blocks& _block);

        static GameManager* get();

    private:
        static GameManager* s_instance;

        Board m_board;
        std::vector<Player> m_players;
        Player m_currentPlayer;
        int m_counter = 0;

        void setCurrentPlayer();
    };
}

