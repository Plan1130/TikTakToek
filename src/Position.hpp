//
//  Position.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef Position_hpp
#define Position_hpp

class Position {
public:
    // constructs a position
    Position(int x, int y);
    
    // returns true if the current position is valid
    bool isValid() const;
    
    // returns the x coordinate
    int getX() const;
    // returns the y coordinate
    int getY() const;

    // constant used for unknown positions (often return in Player::getNextMove(...) when there are no moves available)
    static const Position unknown_position;
    
private:
    // constructs an invalid position
    Position();
    
    // the coordinates
    int x_, y_;
};

#endif /* Position_hpp */
