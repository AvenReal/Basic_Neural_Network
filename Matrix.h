//
// Created by evan on 4/30/26.
//

#ifndef BASIC_NEURAL_NETWORK_MATRIX_H
#define BASIC_NEURAL_NETWORK_MATRIX_H
#include <format>
#include <iostream>
#include <stdexcept>


class Matrix {
protected:
    double **matrix;

public:
    int Width;
    int Height;

    Matrix(int height, int width) {
        Width = width;
        Height = height;
        matrix = new double *[Height];
        for (int i = 0; i < Height; i++) {
            matrix[i] = new double[Width];
        }
    }

    Matrix(int height, int width, double **array, bool destroy = true) {
        Width = width;
        Height = height;
        matrix = new double *[Height];
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


    Matrix operator*(const Matrix &other) const {
        if (Width != other.Height)
            throw std::runtime_error(
                "Matrix Multiplication: Invalid dimensions: (" + std::to_string(Height) + ", " + std::to_string(Width) +
                ") + (" + std::to_string(other.Height) + ", " + std::to_string(other.Width) + ").");

        Matrix result = Matrix(other.Height, Width);

        for (int line = 0; line < result.Height; ++line) {
            for (int col = 0; col < result.Width; ++col) {
                double n = 0;
                for (int i = 0; i < result.Width; ++i) {
                    n += matrix[line][i] * other.matrix[i][col];
                }
                result.matrix[line][col] = n;
            }
        }
        return result;
    }

    Matrix operator*(const int n) const {
        Matrix result = *this;
        for (int line = 0; line < result.Height; ++line) {
            for (int col = 0; col < result.Width; ++col) {
                result.matrix[line][col] = result.matrix[line][col] * n;
            }
        }
        return result;
    }

    Matrix operator+(const Matrix &other) const {
        if (Height != other.Height || Width != other.Width)
            throw std::runtime_error(
                "Matrix Addition: Invalid dimensions: (" + std::to_string(Height) + ", " + std::to_string(Width) +
                ") + (" + std::to_string(other.Height) + ", " + std::to_string(other.Width) + ").");

        Matrix result = Matrix(Height, Width);

        for (int i = 0; i < Height; ++i) {
            for (int j = 0; j < other.Width; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    Matrix &operator=(const Matrix &other) {
        if (this == &other)
            return *this;

        if (Height != other.Height || Width != other.Width)
            throw std::runtime_error(
                "Matrix Replacement (operator=): Invalid dimensions: (" + std::to_string(Height) + ", " + std::to_string(Width) +
                ") + (" + std::to_string(other.Height) + ", " + std::to_string(other.Width) +
                ").");

        for (int i = 0; i < Height; ++i) {
            for (int j = 0; j < Width; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    void Set(const int x, const int y, const double value) const {
        matrix[y][x] = value;
    }

    double get(int x, int y) const {
        return matrix[y][x];
    }


    std::string ToString() const {
        std::string result;
        for (int i = 0; i < Height; ++i) {
            result += i == 0 ? "[ " : (i == Height - 1 ? "[ " : "| ");
            for (int j = 0; j < Width; ++j) {
                result += std::to_string(matrix[i][j]) + (j == Width - 1 ? "" : "\t");
            }
            result += i == 0 ? " ]" : (i == Height - 1 ? " ]" : " |");
            result += "\n";
        }

        return result;
    }
};

std::ostream& operator<<(std::ostream& os, Matrix& other);

#endif //BASIC_NEURAL_NETWORK_MATRIX_H