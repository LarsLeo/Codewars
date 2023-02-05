def solution(data, n):
    amountDict = {}

    for id in data:
        if id in amountDict:
            amountDict[id] = amountDict[id] + 1
        else:
             amountDict[id] = 1

    return [id for id in data if amountDict[id] < n + 1]

print(solution([1, 2, 2, 3, 3, 3, 4, 5, 5], 1))