def solution(str1, str2):
    set1 = sorted([str1[i:i+2].lower() for i in range(len(str1)-1) if str1[i:i+2].isalpha()])
    set2 = sorted([str2[i:i+2].lower() for i in range(len(str2)-1) if str2[i:i+2].isalpha()])

    i = 0; j = 0; inter = 0; alls = 0;
    while i < len(set1) and j < len(set2):
        if set1[i] > set2[j]:
            j += 1
        elif set1[i] < set2[j]:
            i += 1
        else:
            inter += 1
            i +=1
            j += 1
        alls += 1
    alls += len(set1) - i + len(set2) - j
    if len(set1) == 0 and len(set2) == 0:
        answer = 65536
    else:
        answer = int(inter / alls * 65536)
    return answer
