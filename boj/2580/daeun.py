# 150124KB 	2776ms
#c++도 할예정~

def getCols(board_, r, c):
    return set(board_[r])

def getRows(board_, r, c):
    return set([x[c] for x in board_])

def dfs(board):
    for r in range(9):
        for c in range(9):
            if(board[r][c] != 0):
                continue
            candi = {1, 2, 3, 4, 5, 6, 7, 8, 9}
            #가로
            candi = candi - getCols(board, r, c)
            #세로
            candi = candi - getRows(board, r, c)
            #사각형 범위
            for i in range((r//3)*3, (r//3)*3 + 3):
                for j in range((c//3)*3, (c//3)*3 + 3):
                    if board[i][j] == 0:
                        continue
                    if board[i][j] in candi:
                        candi.remove(board[i][j])
            if(len(candi) == 0):
                return False
            for candiVal in candi:
                tmp = board[r][c]
                board[r][c] = candiVal
                isSuccess = dfs(board)
                if isSuccess:
                    return isSuccess
                board[r][c] = tmp
            return False
    return True

if __name__ == "__main__":
    board = [list(map(int, input().split())) for _ in range(9)]

    # print(board)
    # for r in range(9):
    #     for c in range(9):
    #         print(board[r][c], " ", end="")
    #     print("")
    # print("")
    # print("")

    dfs(board)

    for r in range(9):
        for c in range(9):
            print(board[r][c], " ", end="")
        print("")
