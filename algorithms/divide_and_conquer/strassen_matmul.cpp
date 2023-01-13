#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }
    vector<vector<int>> a11(n / 2, vector<int>(n / 2));
    vector<vector<int>> a12(n / 2, vector<int>(n / 2));
    vector<vector<int>> a21(n / 2, vector<int>(n / 2));
    vector<vector<int>> a22(n / 2, vector<int>(n / 2));
    vector<vector<int>> b11(n / 2, vector<int>(n / 2));
    vector<vector<int>> b12(n / 2, vector<int>(n / 2));
    vector<vector<int>> b21(n / 2, vector<int>(n / 2));
    vector<vector<int>> b22(n / 2, vector<int>(n / 2));

    // Divide A and B into 4 sub-matrices
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + n / 2];
            a21[i][j] = A[i + n / 2][j];
            a22[i][j] = A[i + n / 2][j + n / 2];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + n / 2];
            b21[i][j] = B[i + n / 2][j];
            b22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    // Compute P1, P2, P3, P4, P5, P6 and P7
    vector<vector<int>> P1 = strassen(a11, subtract(b12, b22));
    vector<vector<int>> P2 = strassen(add(a11, a12), b22);
    vector<vector<int>> P3 = strassen(add(a21, a22), b11);
    vector<vector<int>> P4 = strassen(a22, subtract(b21, b11));
    vector<vector<int>> P5 = strassen(add(a11, a22), add(b11, b22));
    vector<vector<int>> P6 = strassen(subtract(a12, a22), add(b21, b22));
    vector<vector<int>> P7 =
        strassen(subtract(a11, a21), add(b11, b12));

    // Compute C11, C12, C21, and C22
    vector<vector<int>> c11 = add(subtract(add(P5, P4), P2), P6);
    vector<vector<int>> c12 = add(P1, P2);
    vector<vector<int>> c21 = add(P3, P4);
    vector<vector<int>> c22 = subtract(subtract(add(P5, P1), P3), P7);

    // Combine the 4 sub-matrices back into one matrix
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            C[i][j] = c11[i][j];
            C[i][j + n / 2] = c12[i][j];
            C[i + n / 2][j] = c21[i][j];
            C[i + n / 2][j + n / 2] = c22[i][j];
        }
    }
    return C;
}

void test_strassen()
{
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    auto C = strassen(A, B);
    vector<vector<int>> expected_C = {{19, 22}, {43, 50}};

    assert(C == expected_C);

    A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    C = strassen(A, B);
    expected_C = {{30, 24, 18}, {84, 69, 54}, {138, 114, 90}};

    assert(C == expected_C);
}

int main()
{
    test_strassen();
    return 0;
}