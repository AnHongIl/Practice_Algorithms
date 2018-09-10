def check(y, x, board):
    c = board[y][x]
    if c == board[y+1][x] and c == board[y][x+1] and c == board[y+1][x+1]:
        return True
    return False

def find(y, x, n, m, board):
    if check(y, x, board):
        return [(y,x)]
    return []

def marking(board, pairs):
	for y, x in pairs:
		board[y][x] = '1'
		board[y+1][x] = '1' 
		board[y][x+1] = '1'
		board[y+1][x+1] = '1'
        
def project(n, m, board):
	cnt = 0
	for j in range(n):		
		ones = board[j].count('1')
		for i in range(ones):
			board[j].remove('1')
		board[j] = ['0'] * ones + board[j]
		cnt += ones
	return cnt

def solution(m, n, board):
	answer = 0
	temp = board
	board = [[] for i in range(n)]
	for j in range(n):
		for i in range(m):
			board[j].append(temp[i][j])

	while True:
		pairs = []
		for j in range(n-1):
			for i in range(m-2, -1, -1):
				if board[j][i] == '0':
					break
				pairs += find(j, i, n, m, board) 
		marking(board, pairs)
		cnt = project(n, m, board)
		if cnt == 0:
			break
		answer += cnt
        
	return answer
