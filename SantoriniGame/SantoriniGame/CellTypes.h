#pragma once

namespace Santorini 
{
    enum CellTypes
    {
        Empty,
        Builder,
        Level1,
        Level2,
        Level3
    };


    inline const char* ToString(CellTypes _types)
    {
        switch (_types)
        {
        case Empty:     return "E";
        case Builder:   return "B";
        case Level1:    return "L1";
        case Level2:    return "L2";
        case Level3:    return "L3";
        default:        return "E";
        }
    }
}
