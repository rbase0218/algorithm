S = input()
P = input()

is_valid = all([1 if P.count(p) == 1 and p in S else 0 for p in P])
count = 0

if is_valid:
    S_length = len(S)
    P_length = len(P)
    D = S_length - P_length

    count += 1

    multiply_list = [d for d in range(D, 0, -1)]
    index_range = 1

    for i in range(2, D + 2):
        temp = 1
        
        for j in range(index_range):
            temp *= multiply_list[j]

        count += temp * i
        index_range += 1

print(count)