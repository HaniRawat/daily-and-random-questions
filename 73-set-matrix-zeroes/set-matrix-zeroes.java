class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[] rowZero = new int[m];
        Arrays.fill(rowZero, 1);
        int[] colZero = new int[n];
        Arrays.fill(colZero, 1);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    rowZero[i] = 0;
                    colZero[j] = 0;
                }
            }
        }

        for(int i=0; i<m; i++) {
            if(rowZero[i] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (colZero[j] == 0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}