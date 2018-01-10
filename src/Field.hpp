//
//  Field.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef Field_hpp
#define Field_hpp

enum class Field {
    Empty = -1,
    X     =  0,
    O     =  1
};

// returns opposite field, ie. X -> O
Field operator~(Field const&);

#endif /* Field_hpp */
