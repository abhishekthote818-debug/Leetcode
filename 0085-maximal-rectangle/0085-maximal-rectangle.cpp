class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() &&
                   heights[i] < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};