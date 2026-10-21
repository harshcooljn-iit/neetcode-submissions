class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        row = [[] for _ in range(n)]
        col = [[] for _ in range(n)]
        box = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if board[i][j] == ".":
                    continue
                board[i][j] = int(board[i][j])
                row[i].append(board[i][j])
                col[j].append(board[i][j])
                box[(i//3)*3 + j//3].append(board[i][j])
        # print(row, col, box, sep="end")
        for l in row:
            f = [0 for _ in range(10)]
            for x in l:
                f[x] += 1
                if f[x] > 1:
                    return False
        for l in col:
            f = [0 for _ in range(10)]
            for x in l:
                f[x] += 1
                if f[x] > 1:
                    return False
        for l in box:
            f = [0 for _ in range(10)]
            for x in l:
                f[x] += 1
                if f[x] > 1:
                    return False
        
        return True