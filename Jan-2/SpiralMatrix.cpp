class Solution {
public:
  //to get all elements of the matrix we can divide operation into 4 parts: move left,move right, move down and move up. I have also maintained a headstart variable cuz after once cycle is completed, it will need to go intto the deeper matrix inside the orginal one
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int headStart = 0;
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int m = 0, n = 0;
        while (ans.size() < (rows * cols)) {
            while (n < (cols - headStart) && ans.size() < (rows * cols)) {
                ans.push_back(matrix[m][n]);
                n++;
            }
            n--;
            m++;
            while (m < (rows - headStart) && ans.size() < (rows * cols)) {
                ans.push_back(matrix[m][n]);
                m++;
            }
            m--;
            n--;
            while (n >= headStart && ans.size() < (rows * cols)) {
                ans.push_back(matrix[m][n]);
                n--;
            }
            n++;
            m--;
            while (m > headStart && ans.size() < (rows * cols)) {
                ans.push_back(matrix[m][n]);
                m--;
            }
            m++;
            n++;
            headStart++;
        }
        return ans;
    }
};
