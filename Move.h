//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_MOVE_H
#define CH_MOVE_H

#include <utility>
#include <string>

#include "Figure.h"

class Move {
public:
    Move(std::pair<int, int> begin, std::pair<int, int> end, Figure* fig);

    std::string getMove();

    std::pair<int, int> getBegin();

    std::pair<int, int> getEnd();
private:
    std::pair<int, int> _begin;
    std::pair<int, int> _end;
    Figure* _fig;

    std::string getStockFishMove();
};


#endif //CH_MOVE_H