import datetime
def solution(lines):
    answer = 0
    logs = []
    one_second = datetime.timedelta(seconds = 1)
    one_millisecond = datetime.timedelta(milliseconds = 1)

    for line in lines:
        edt = datetime.datetime.strptime(line.rsplit(' ', 1)[0], '%Y-%m-%d %H:%M:%S.%f')
        if '.' in line.rsplit(' ', 1)[1]:
            dt = datetime.datetime.strptime(line.rsplit(' ', 1)[1][:-1], '%S.%f')
            delta = datetime.timedelta(seconds = dt.second, milliseconds = dt.microsecond / 1000)
        else:
            dt = datetime.datetime.strptime(line.rsplit(' ', 1)[1][:-1], '%S')
            delta = datetime.timedelta(seconds = dt.second)
        sdt = edt - delta + one_millisecond
        logs.append([sdt, edt])
    
    logs.sort(key=lambda x: x[0])

    for t in [log for two_logs in logs for log in two_logs]:
        cnt = 0
        for log in logs:
            if not (log[1] < t or t + one_second - one_millisecond < log[0]):
                cnt += 1
            if t + one_second - one_millisecond < log[0]:
                break
        answer = max(answer, cnt)

    return answer
