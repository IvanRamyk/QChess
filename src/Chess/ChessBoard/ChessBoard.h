//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSBOARD_H
#define CH_CHESSBOARD_H

#include "../Figure/Figure.h"
#include "../Move/Move.h"

#include <vector>

using matrix = Figure*[8][8];

class ChessBoard {
public:
    ChessBoard();

    bool makeMove(Move move);

    [[nodiscard]] Figure* getFigure(std::pair<int, int> pos) const;

    [[nodiscard]] bool checkMove(Move move) const;

    [[nodiscard]] std::vector<std::string> getField() const;

    [[nodiscard]] bool isCheck(Color color, std::pair<int, int> kingPos = {-1, -1}) const;

    [[nodiscard]] bool isCheckmate(Color color, std::pair<int, int> kingPos = {-1, -1});

    [[nodiscard]] bool isStalemate(Color color, std::pair<int, int> kingPos = {-1, -1});

    [[nodiscard]] bool isCapture(Move move) const;

    //0-0 == 1
    //0-0-0 == 2
    [[nodiscard]]  int isCastle(Move move) const;

    Figure* getFigure(std::pair<int, int> position);

private:
    matrix _board;

    Move _prev;

    [[nodiscard]] bool checkBetween(Move move) const;

    static std::vector<std::pair<int, int>> getBetween(std::pair<int, int> begin, std::pair<int, int> end);

    void pawnTransform(std::pair<int, int> pos, FigureType to);

    static std::string figureToString(std::pair<int, int> pos, Figure* fig);

    [[nodiscard]] std::pair<int, int> findKing(Color color) const;

    [[nodiscard]] bool possibleMove(Color color);
};


#endif //CH_CHESSBOARD_H
