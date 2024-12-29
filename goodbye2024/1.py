def solve():
    import sys
    # input = sys.stdin.read
    # data = input().splitlines()
    t = int(input())

    # t = int(data[0])  # Number of test cases
    results = []
    idx = 1

    for _ in range(t):
        n = int(input())  # Number of impressions in this test case
        idx += 1

        ranges = []
        for __ in range(n):
            l, r = map(int, data[idx].split())
            ranges.append((l, r))
            idx += 1

        # Initialize frequency array for coordinate compression
        max_val = 2 * n
        freq = [0] * (max_val + 2)

        # Process the ranges
        for l, r in ranges:
            freq[l] += 1
            freq[r + 1] -= 1

        # Calculate the prefix sum to get active frequencies
        active = [0] * (max_val + 1)
        for i in range(1, max_val + 1):
            active[i] = active[i - 1] + freq[i]

        # Check uniqueness for each impression
        result = []
        for l, r in ranges:
            unique = False
            for value in range(l, r + 1):
                if active[value] == 1:
                    unique = True
                    break
            result.append('1' if unique else '0')

        results.append(''.join(result))

    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()
