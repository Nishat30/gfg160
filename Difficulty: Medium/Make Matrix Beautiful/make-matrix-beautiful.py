class Solution:
    def balanceSums(self, mat):
        n = len(mat)
        if n == 0:
           return 0

        max_row_sum = 0
        for i in range(n):
            current_row_sum = 0
            for j in range(n):
                current_row_sum += mat[i][j]

            if current_row_sum > max_row_sum:
                max_row_sum = current_row_sum

        max_col_sum = 0
        for j in range(n):
            current_col_sum = 0
            for i in range(n):
                current_col_sum += mat[i][j]

            if current_col_sum > max_col_sum:
                max_col_sum = current_col_sum

        target_sum = max(max_row_sum, max_col_sum)

        total_operations = 0
        for i in range(n):
            current_row_sum = 0
            for j in range(n):
                current_row_sum += mat[i][j]

            total_operations += (target_sum - current_row_sum)

        return total_operations