import datetime
def solution(lines):
    answer = 0
    logs = []
    param = ["year", "month", "day", "hour", "minute", "second", "microsecond"]
    start_day = datetime.datetime(year = 2016, month = 9, day = 15)
    end_day = datetime.datetime(year = 2016, month = 9, day = 15, hour = 23, minute = 59, second = 59, microsecond = 999 * 1000)
    one_second = datetime.timedelta(seconds = 1)
    one_millisecond = datetime.timedelta(milliseconds = 1)
    
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

        sdt = edt - delta + one_millisecond
        logs.append([sdt, edt])
    
    start = logs[0][0]
    end = logs[-1][1]

    
    for candidate in logs:
        start = candidate[0] - one_second + one_millisecond
        end = candidate[1] + one_second - one_millisecond
        
        if start < start_day:
            start = start_day
        if end > end_day:
            end = end_day
        
        while start <= end:
            cnt = 0
            for log in logs:
                if start <= log[0] and log[0] <= start + one_second - one_millisecond:
                    cnt += 1
                elif log[0] <= start and start <= log[1]:
                    cnt += 1
            if answer < cnt:
                answer = cnt
            start += one_millisecond
            
    return answer
