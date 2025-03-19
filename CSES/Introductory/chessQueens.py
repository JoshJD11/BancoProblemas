def TEST(msk, i):
    return msk & (1 << i)



def SET(msk, i):
    return msk | (1 << i)



def eightQueens(board):
    ans = 0
    stack = [[0, 0, 0, 0, 0]] 
    while stack:
        rows, colums, rDiagonal, lDiagonal, cantR = stack.pop()
        if cantR == 8: ans += 1
        else:
            for j in range(8):
                if not (board[cantR][j] == '*' or TEST(rows, j) or TEST(colums, j) or TEST(rDiagonal, cantR - j + 7) or TEST(lDiagonal, cantR + j)):
                    newCantR = cantR + 1
                    newRows = SET(rows, j)
                    newColumns = SET(colums, j)
                    newRDiagonal = SET(rDiagonal, cantR - j + 7)
                    newLDiagonal = SET(lDiagonal, cantR + j)
                    stack.append([newRows, newColumns, newRDiagonal, newLDiagonal, newCantR])

    return ans



chessboard = []
for _ in range(8):
    row = str(input())
    chessboard.append(row)

print(eightQueens(chessboard))

