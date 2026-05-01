//
// Created by evan on 4/30/26.
//

#include "Matrix.h"

std::ostream& operator<<(std::ostream& os, Matrix& other) {
    return os << other.ToString();
}
