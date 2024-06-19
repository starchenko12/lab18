#include <iostream>

class Matrix3x5 {
private:
    int data[3][5];

public:
    Matrix3x5(int initData[3][5]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                data[i][j] = initData[i][j];
            }
        }
    }

    Matrix3x5 operator-(const Matrix3x5& other) const {
        int resultData[3][5];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                resultData[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return Matrix3x5(resultData);
    }

    Matrix3x5 operator*(const Matrix3x5& other) const {
        int resultData[3][5];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                resultData[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return Matrix3x5(resultData);
    }

    bool operator==(const Matrix3x5& other) const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int data1[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    int data2[3][5] = {
        {5, 4, 3, 2, 1},
        {10, 9, 8, 7, 6},
        {15, 14, 13, 12, 11}
    };

    Matrix3x5 matrix1(data1);
    Matrix3x5 matrix2(data2);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.print();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.print();

    Matrix3x5 resultSub = matrix1 - matrix2;
    std::cout << "Subtraction Result:" << std::endl;
    resultSub.print();

    Matrix3x5 resultMul = matrix1 * matrix2;
    std::cout << "Multiplication Result:" << std::endl;
    resultMul.print();

    bool isEqual = (matrix1 == matrix2);
    std::cout << "Matrices are equal: " << (isEqual ? "Yes" : "No") << std::endl;

    return 0;
}
