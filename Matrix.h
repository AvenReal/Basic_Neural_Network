//
// Created by evan on 4/30/26.
//

#ifndef BASIC_NEURAL_NETWORK_MATRIX_H
#define BASIC_NEURAL_NETWORK_MATRIX_H
#include <format>
#include <stdexcept>


class Matrix {
    protected:
        double **matrix;

    public:
        int Width;
        int Height;

        Matrix(int width, int height) {
            Width = width;
            Height = height;
            matrix = new double*[Height];
            for (int i = 0; i < Height; i++) {
                matrix[i] = new double[Width];
            }
        }

        ~Matrix() {
            for (int i = 0; i < Height; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }


        Matrix operator*(const Matrix& other) {
            if (Height != other.Width)
                throw std::runtime_error( "Matrix Multiplication: Invalid dimensions: (" + std::to_string(Width) + ", " + std::to_string(Height) + ") * (" + std::to_string(other.Width) + ", " + std::to_string(other.Height)  + ")." );

            Matrix result = Matrix(Width, other.Height);

            for (int h = 0; h < result.Height; ++h) {
                for (int w = 0; w < result.Width; ++w) {
                    double n = 0;
                    for (int y = 0; y < result.Height; ++y) {
                        for (int x = 0; x < result.Width; ++x) {
                            n += matrix[h][x] * matrix[y][w];
                        }
                    }
                    result.matrix[h][w] = n;
                }
            }
            return result;
        }

        Matrix operator+(const Matrix& other) {
            if (Height != other.Height || Width != other.Width)
                throw std::runtime_error( "Matrix Addition: Invalid dimensions: (" + std::to_string(Width) + ", " + std::to_string(Height) + ") + (" + std::to_string(other.Width) + ", " + std::to_string(other.Height)  + ")." );

            Matrix result = Matrix(Width, Height);

            for (int i = 0; i < Height; ++i) {
                for (int j = 0; j < other.Width; ++j) {
                    result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                }
            }

            return result;
        }

        [[nodiscard]] std::string ToString() const {
            std::string result;
            for (int i = 0; i < Height; ++i) {
                result += i == 0 ? '[' : (i == Height -1 ? '[' : '|');
                for (int j = 0; j < Width; ++j) {
                    result += std::to_string(matrix[i][j]) + "\t";
                }
                result += i == 0 ? ']' : (i == Height -1 ? ']' : '|');
                result += '\n';
            }

            return result;
        }
};

std::ostream& operator<<(std::ostream& os, Matrix& other);

#endif //BASIC_NEURAL_NETWORK_MATRIX_H