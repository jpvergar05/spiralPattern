#include <iostream>
#include <iomanip>

using namespace std;

// Create a dynamic 2D array and fill it using the provided patterns
char** generateSpiralMatrix(int n, int m) {
    //Complete me
    // Allocate memory for 2D array
    char** matrix = new char*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[m];
    }

    // Initialize the matrix with spaces
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = ' ';
        }
    }

    // Initialize boundaries
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // Top row, left to right (excluding corners)
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = '-';
        }
        matrix[top][right] = '.'; // Mark the corner after completing the path

        // Right column, top to bottom
        for (int i = top + 1; i <= bottom - 1; ++i) {
            matrix[i][right] = '|';
        }
        matrix[bottom][right] = '.'; // Mark the corner after completing the path

        // Bottom row, right to left
        for (int i = right; i >= left; --i) {
            matrix[bottom][i] = '_';
        }
        matrix[bottom][left] = '.'; // Mark the corner after completing the path

        // Left column, bottom to top
        for (int i = bottom - 1; i > top; --i) { 
            matrix[i][left] = '|';
        }
      

        if (left == 0 && top == 0) matrix[top][left] = '.';

        // Update boundaries for the next layer
        left++; right--; top++; bottom--;
    }

    return matrix;
}

// Delete the matrix
void deleteMatrix(char** matrix, int n) {
    //Complete me 
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void drawMatrix(int n, int m) {
    char** spiralMatrix = generateSpiralMatrix(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << spiralMatrix[i][j];
        }
        cout << endl;
    }
    deleteMatrix(spiralMatrix, n);
}

int main() {
    cout << "10x6:" << endl;
    drawMatrix(10,6);
    cout << endl << endl; 
    cout << "8x16:" << endl;
    drawMatrix(8,16);
    cout << endl << endl;
    cout << "12x4:" << endl;
    drawMatrix(12, 4);
    return 0;
}
