import datetime
def solution(lines):
    answer = 0
    
    logs = []
    param = ["year", "month", "day", "hour", "minute", "second", "microsecond"]
    one_delta = datetime.timedelta(milliseconds = 1)
    for line in lines:
        log = line.split(' ')
        dic = {}        
        for j in range(6):
            if j < 3:
                dic[param[j]] = log[0].split('-')[j]
            elif j < 5:
                dic[param[j]] = log[1].split(':')[j-3]
            else:
                dic[param[j]] = log[1].split(':')[j-3].split('.')[0]
                dic[param[j+1]] = log[1].split(':')[j-3].split('.')[1] 

        dic = {k:int(v) for k, v in dic.items()}
        dic['microsecond'] *= 1000
        edt = datetime.datetime(**dic)    

        pd = log[2][:-1]
        delta = datetime.timedelta(seconds = 0)
        if pd.find('.') is -1:
            delta = datetime.timedelta(seconds = int(pd))
        else:
            pd = list(map(int, list(pd.split('.'))))
            delta = datetime.timedelta(seconds = pd[0], milliseconds = pd[1])

        sdt = edt - delta + one_delta
        logs.append([sdt, edt])
    
    start = logs[0][0]
    end = logs[-1][1]
    one_seconds = datetime.timedelta(seconds = 1)
    
    while start <= end:
        if start.day < 15:
            start += one_delta
            continue

        cnt = 0
        for log in logs:
            if start <= log[0] and log[0] <= start + one_seconds - one_delta:
                cnt += 1
            elif log[0] <= start and start <= log[1]:
                cnt += 1
        if answer < cnt:
            answer = cnt
        start += one_delta
        
    return answer
