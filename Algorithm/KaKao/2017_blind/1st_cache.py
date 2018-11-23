from collections import deque

def solution(cacheSize, cities):
    answer = 0
    q = deque(maxlen=cacheSize)
    
    for city in cities:
        city = city.lower()
        if city in q:
            q.remove(city)
            q.append(city)
            answer += 1
        else:
            q.append(city)
            answer += 5
    return answer
