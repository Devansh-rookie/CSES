def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = list(map(int, data[idx:idx + n]))
        idx += n
        
        # Identify `x` and calculate prefix sums for `1` and `-1` only
        prefix_sum = 0
        possible_sums = set()
        x = None
        x_pos = -1
        
        for i in range(n):
            if a[i] not in (-1, 1):
                x = a[i]
                x_pos = i
                continue
            
            # Update prefix sum for only `1` and `-1`
            prefix_sum += a[i]
            possible_sums.add(prefix_sum)
        
        # Include zero sum (empty subarray)
        possible_sums.add(0)
        
        # Handle the influence of `x`
        if x is not None:
            new_sums = set()
            for s in possible_sums:
                new_sums.add(s)  # Without `x`
                new_sums.add(s + x)  # Including `x`
            possible_sums = new_sums
        
        # Sort and prepare the result
        result = sorted(possible_sums)
        results.append(f"{len(result)}\n{' '.join(map(str, result))}")
    
    # Print all results at once
    sys.stdout.write("\n".join(results) + "\n")

solve()