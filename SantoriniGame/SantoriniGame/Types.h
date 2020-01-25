#pragma once

#include <string>
#include <map>

namespace Santorini
{
    using namespace std;

    template <typename T>
    class EnumParser
    {
        map <string, T> enumMap;
        map <int, T> enumMapInt;
    public:
        EnumParser() {};

        T ParseEnum(const string &value)
        {
            typename map <string, T>::const_iterator iValue = enumMap.find(value);
            if (iValue == enumMap.end())
                throw runtime_error("");
            return iValue->second;
        }

        T ParseFromInt(const int &value)
        {
            typename map <int, T>::const_iterator iValue = enumMapInt.find(value);
            if (iValue == enumMapInt.end())
                throw runtime_error("");
            return iValue->second;
        }
    };

   enum CellTypes
    {
        Empty,
        BuilderType
    };

   enum Blocks
   {
       Ground,
       Level1,
       Level2,
       Level3,
       Dome
   };

    enum Direction
    {
        Left,
        Right,
        Up,
        Down,
        LeftUp,
        LeftDown,
        RightUp,
        RightDown,
    };

    inline const char* ToString(CellTypes _types)
    {
        switch (_types)
        {
        case Empty:     return "E";
        case BuilderType:   return "B";
        default:        return "E";
        }
    }

    inline const char* ToString(Blocks _block)
    {
        switch (_block)
        {
        case Ground:    return "G";
        case Level1:    return "L1";
        case Level2:    return "L2";
        case Level3:    return "L3";
        case Dome:      return "D";
        default:        return "G";
        }
    }

    inline const int ToInt(Blocks _block)
    {
        switch (_block)
        {
        case Ground:    return 0;
        case Level1:    return 1;
        case Level2:    return 2;
        case Level3:    return 3;
        case Dome:      return 4;
        default:        return 0;
        }
    }

    EnumParser<Direction>::EnumParser()
    {
        enumMap["Left"] = Left;
        enumMap["Right"] = Right;
        enumMap["Up"] = Up;
        enumMap["Down"] = Down;
        enumMap["LeftUp"] = LeftUp;
        enumMap["LeftDown"] = LeftDown;
        enumMap["RightUp"] = RightUp;
        enumMap["RightDown"] = RightDown;      
    }

    EnumParser<Blocks>::EnumParser()
    {
        enumMap["G"] = Ground;
        enumMap["L1"] = Level1;
        enumMap["L2"] = Level2;
        enumMap["L3"] = Level3;
        enumMap["D"] = Dome;

        enumMapInt[0] = Ground;
        enumMapInt[1] = Level1;
        enumMapInt[2] = Level2;
        enumMapInt[3] = Level3;
        enumMapInt[4] = Dome;
    }
}
