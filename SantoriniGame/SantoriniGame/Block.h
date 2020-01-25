#pragma once
#include <string>

class Block
{
public:
    Block(int _value, std::string& _name) :m_value(_value), m_name(_name) {}
    int GetBlock() const { return m_block; }

    static Block Ground() { return Block(0, "G"); }
    static Block Level1() { return Block(1, "L1"); }
    static Block Level2() { return Block(2, "L2"); }
    static Block Level3() { return Block(3, "L3"); }
    static Block Dome() { return Block(4, "D"); }

private:
    int m_value;
    std::string m_name;
};

