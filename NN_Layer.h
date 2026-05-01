//
// Created by evan on 5/1/26.
//

#ifndef BASIC_NEURAL_NETWORK_NN_LAYER_H
#define BASIC_NEURAL_NETWORK_NN_LAYER_H
#include "Matrix.h"


class NN_Layer {
    protected:
        Matrix* Weights;
        Matrix* Biases;
        NN_Layer* Previous_Lqyer;
    public:

};


#endif //BASIC_NEURAL_NETWORK_NN_LAYER_H