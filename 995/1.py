def maximize_difference(n, a, b, i=0, m=0, s=0):
    # Base case: no more days to consider
    if i >= n:
        return m - s

    # Option 1: Monocarp skips this day
    skip = maximize_difference(n, a, b, i + 1, m, s)
    
    # Option 2: Monocarp trains on this day
    stereocarp_contrib = b[i + 1] if i + 1 < n else 0
    train = maximize_difference(n, a, b, i + 2, m + a[i], s + stereocarp_contrib)
    
    # Return the maximum of the two options
    return max(skip, train)

# Process multiple test cases
def solve():
    t = int(input())  # Number of test cases
    results = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        # Compute the result for the current test case
        results.append(maximize_difference(n, a, b))
    
    # Print all results
    for res in results:
        print(res)

# Example Input/Output
# Uncomment below lines to run locally
solve()
