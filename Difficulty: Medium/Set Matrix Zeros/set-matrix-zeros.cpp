class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int rows = mat.size();
    int cols = mat[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Step 1: Determine if the first row or column needs to be zero
    for (int i = 0; i < rows; i++) {
        if (mat[i][0] == 0) firstColZero = true;
    }
    for (int j = 0; j < cols; j++) {
        if (mat[0][j] == 0) firstRowZero = true;
    }

    // Step 2: Use the first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0; // Mark row
                mat[0][j] = 0; // Mark column
            }
        }
    }

    // Step 3: Set the matrix zeroes based on the markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Step 4: Handle the first row and column separately
    if (firstColZero) {
        for (int i = 0; i < rows; i++) mat[i][0] = 0;
    }
    if (firstRowZero) {
        for (int j = 0; j < cols; j++) mat[0][j] = 0;
    }
    }
};