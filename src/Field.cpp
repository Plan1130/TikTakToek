//
//  Field.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "Field.hpp"

#include <stdexcept>

Field operator~(Field const& field) {
    switch (field) {
        case Field::X: // X -> O
            return Field::O;
        case Field::O: // O -> X
            return Field::X;
        default: // throw error since there is no opposite of and empty field
            throw std::runtime_error("cannot get opposite field");
    }
}
