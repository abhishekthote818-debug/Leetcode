class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word,
             int i, int j, int index) {

        // Word complete ho gaya
        if (index == word.size())
            return true;

        // Boundary check
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return false;

        // Character match nahi hua
        if (board[i][j] != word[index])
            return false;

        // Already visited cell
        if (board[i][j] == '#')
            return false;

        // Cell ko visited mark karo
        char temp = board[i][j];
        board[i][j] = '#';

        // 4 directions
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};