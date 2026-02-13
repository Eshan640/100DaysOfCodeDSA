int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    *returnSize = rows * cols;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        
        // 1. Left -> Right
        for (int j = left; j <= right; j++) {
            result[idx++] = matrix[top][j];
        }
        top++;

        // 2. Top -> Bottom
        for (int i = top; i <= bottom; i++) {
            result[idx++] = matrix[i][right];
        }
        right--;

        // 3. Right -> Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[idx++] = matrix[bottom][j];
            }
            bottom--;
        }

        // 4. Bottom -> Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}
