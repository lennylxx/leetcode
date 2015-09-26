#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool dfs(char** board, int rows, int cols,
         bool** visited, int i, int j,
         char* word)
{
    if (*word == '\0') return true;

    if (i >= 0 && i < rows && j >= 0 && j < cols && !visited[i][j]
        && *word == board[i][j] )
    {
        visited[i][j] = true;

        bool found = false;
        found = dfs(board, rows, cols, visited, i, j - 1, word + 1); /* left */
        if (found) return true;
        found = dfs(board, rows, cols, visited, i, j + 1, word + 1); /* right */
        if (found) return true;
        found = dfs(board, rows, cols, visited, i - 1, j, word + 1); /* up */
        if (found) return true;
        found = dfs(board, rows, cols, visited, i + 1, j, word + 1); /* down */
        if (found) return true;

        visited[i][j] = false;
    }

    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if (board == NULL || boardRowSize == 0 || boardColSize == 0
        || word == NULL) return false;

    bool **visited = (bool **)calloc(boardRowSize, sizeof(bool *));
    int i, j;
    for (i = 0; i < boardRowSize; i++) {
        visited[i] = (bool *)calloc(boardColSize, sizeof(bool));
    }

    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == *word) {
                bool found = dfs(board, boardRowSize, boardColSize, visited, i, j, word);
                if (found) return true;
            }
        }
    }

    return false;
}

int main() {
    char *board[5] = { "aaaa", "aaaa", "aaaa", "aaaa", "aaab" };
    char word[] = "aaaaaaaaaaaaaaaaaaaa";

    assert(exist(board, 5, 4, word) == false);

    printf("all tests passed!\n");

    return 0;
}
