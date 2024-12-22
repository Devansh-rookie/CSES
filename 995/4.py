from bisect import bisect_left, bisect_right

def count_interesting_pairs(t, test_cases):
    results = []
    for case in test_cases:
        n, x, y, a = case
        S = sum(a)
        L, R = S - y, S - x
        a.sort()
        count = 0
        
        for i in range(n):
            low = L - a[i]
            high = R - a[i]
            j_left = bisect_left(a, low, i + 1)
            j_right = bisect_right(a, high, i + 1)
            count += j_right - j_left
        
        results.append(count)
    
    return results

t = int(input())
test_cases = []
for _ in range(t):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    test_cases.append((n, x, y, a))

results = count_interesting_pairs(t, test_cases)
print("\n".join(map(str, results)))
