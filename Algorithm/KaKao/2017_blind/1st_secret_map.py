def strToWall(row):
    ret = ""
    for c in row:
        if c is '0':
            ret += ' '
        else:
            ret +='#'
    return ret

def convertToMap(n, arr):
    for i, row in enumerate(arr):
        arr[i] = strToWall(format(row, '016b')[16-n:]) 

def combineMaps(n, arr1, arr2):
    ret = []
    for row1, row2 in zip(arr1, arr2):
        row = ""
        for c1, c2 in zip(row1, row2):
            if c1 is '#' or c2 is '#':
                row += '#'
            else:
                row += ' '
        ret.append(row)
    return ret

def solution(n, arr1, arr2):
    answer = []
    convertToMap(n, arr1)
    convertToMap(n, arr2)
    answer = combineMaps(n, arr1, arr2)
    return answer
