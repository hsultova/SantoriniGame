#pragma once
namespace Santorini
{
    class Position
    {
    public:
        Position();
        Position(int _x, int _y);
        ~Position();

        const int getX() const { return m_x; }
        const int getY() const { return m_y; }

        void setX(int _x) { m_x = _x; }
        void setY(int _y) { m_y = _y; }

    private:
        int m_x;
        int m_y;
    };
}

