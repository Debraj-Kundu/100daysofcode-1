def revList(lst):
    if lst == []:
        return []
    restrev = revList(lst[1:])
    first = lst[0:1]

    res = restrev + first
    return res


print(revList([1, 2, 3, 4]))
