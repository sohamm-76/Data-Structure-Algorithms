#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    // Allocate memory for rows
    int **matrix = new int *[rows];

    // Allocate memory for each column
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    // Store data
    int x = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = x++;
        }
    }

    // Display matrix
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
            // cout << *(*(matrix+2)+2) << endl;
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
