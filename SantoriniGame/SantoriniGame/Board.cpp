#include "pch.h"
#include "Board.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include "Types.h"
#include "Position.h"

namespace Santorini
{
    Board::Board()
    {
    }


    Board::~Board()
    {
    }

    void Board::initialize()
    {
        for (int i = 0; i < width; i++)
        {
            std::vector<std::pair<std::string, std::string>> row;

            for (int j = 0; j < width; j++)
            {
                row.push_back(std::pair<std::string, std::string>(ToString(Santorini::Empty), ToString(Santorini::Ground)));
            }

            m_board.push_back(row);
        }
    }

    void Board::clear()
    {
    }

    void Board::draw()
    {
        HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout << "-----------------------------------\n";
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (m_board[i][j].first != ToString(Santorini::Empty) || m_board[i][j].second != ToString(Santorini::Ground))
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                }
                std::cout << m_board[i][j].first + ":" + m_board[i][j].second + " ";
            }
            std::cout << "\n";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    }

    void Board::setCell(const Position& _position, const std::string& _type, const Santorini::Blocks& _level)
    {
        m_board[_position.getX()][_position.getY()].first = _type;
        m_board[_position.getX()][_position.getY()].second = ToString(_level);
    }

    std::pair<std::string, std::string> Board::getCell(int x, int y) const
    {
        return m_board[x][y];
    }
}
