//
// Created by evan on 5/1/26.
//

#ifndef BASIC_NEURAL_NETWORK_NN_LAYER_H
#define BASIC_NEURAL_NETWORK_NN_LAYER_H
#include "Matrix.h"


class Layer {
    protected:
        Matrix W_l; // Weights of layer l
        Matrix b_l; // biases of layer l

        Matrix Z_l; // Pre activation function matrix of layer l
        Matrix A_l; // Post activation function matrix of layer l
        Matrix& (*ActivationFunction)(Matrix&); // Activation function of layer l


        Matrix* A_lm1; // Post activation function matrix of layer l - 1
        Layer* L_lm1; // Pointer to Layer - 1
    public:
        Layer(int size, int prevLayerSize, Layer* PreviousLayer, Matrix& (*activationFunction)(Matrix&)) : ActivationFunction(activationFunction) {
            W_l = Matrix(size, prevLayerSize);
            b_l = Matrix(size, 1);


            L_lm1 = PreviousLayer;
        }


};


#endif //BASIC_NEURAL_NETWORK_NN_LAYER_H