import re

def solution(dartResult):
    p1 = re.compile("[\d]+[SDT][*#]?")
    
    results = p1.findall(dartResult)
    answer = 0
    isNext = False
    for result in reversed(results):
        number = int(re.findall("[\d]+", result)[0])
        bonus = re.findall("[SDT]", result)[0]

        if bonus is 'D':
            number **= 2
        elif bonus is 'T':
            number **= 3
            
        if isNext:
            number *= 2
            isNext = False
            
        isStar = False
        if result.find("*") > -1:
            number *= 2
            isStar = True
        elif result.find("#") > -1:
            number *= -1

        if isStar:
            isNext = True
            
        answer += number
    return answer
