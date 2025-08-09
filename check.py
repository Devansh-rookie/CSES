def solve():
    def dfs(node, graph, visited):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor, graph, visited)

    def find_components(n, graph):
        visited = [False] * n
        components = []

        for i in range(n):
            if not visited[i]:
                component = []
                dfs_component(i, graph, visited, component)
                components.append(component)
        return components

    def dfs_component(node, graph, visited, component):
        visited[node] = True
        component.append(node)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs_component(neighbor, graph, visited, component)

    T = int(input())

    for _ in range(T):
        N, M = map(int, input().split())

        # Build adjacency list
        graph = [[] for _ in range(N)]
        for _ in range(M):
            A, B = map(int, input().split())
            graph[A].append(B)
            graph[B].append(A)

        C = int(input())  # Capital city

        # Check if all cities are reachable from capital
        visited = [False] * N
        dfs(C, graph, visited)

        if all(visited):
            print("Yes")
        else:
            # Find number of connected components
            components = find_components(N, graph)

            # Check which component contains the capital
            capital_component = -1
            for i, comp in enumerate(components):
                if C in comp:
                    capital_component = i
                    break

            # We need (total_components - 1) roads to connect all components
            roads_needed = len(components) - 1

            print("No")
            print(roads_needed)

solve()
