//
// Created by evan on 5/1/26.
//

#ifndef BASIC_NEURAL_NETWORK_NN_LAYER_H
#define BASIC_NEURAL_NETWORK_NN_LAYER_H
#include "Matrix.h"


class Base_Layer {
    protected:
        Matrix W_l; // Weights of layer l
        Matrix b_l; // biases of layer l

        Matrix Z_l; // Pre activation function matrix of layer l
        Matrix A_l; // Post activation function matrix of layer l
        Matrix& (*ActivationFunction)(Matrix&); // Activation function of layer l


        Matrix& A_lm1; // Post activation function matrix of layer l - 1

        void CalulateZ() {
            Z_l = A_lm1 * W_l + b_l;
        }
    public:
        Base_Layer(int size, Matrix& previous_entry, Matrix& (*activationFunction)(Matrix&))
            : W_l(Matrix(size, previous_entry.Height)),
              b_l(Matrix(size, 1)),

              Z_l(Matrix(size, 1)),
              A_l(Matrix(size, 1)),

              A_lm1(previous_entry),

              ActivationFunction(activationFunction)  {}



        void CalculateA() {
            CalulateZ();
            A_l = ActivationFunction(Z_l);
        }
};


#endif //BASIC_NEURAL_NETWORK_NN_LAYER_H