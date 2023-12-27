import random

def generate_test_data(n_max=250, m_max=250, q_max=100000):
    n = random.randint(n_max-10, n_max)
    m = random.randint(1, min(m_max, n * n - 2))  # Leave at least two positions for the balls
    q = random.randint(q_max-10, q_max)

    # Generate unique obstacle positions
    obstacles = set()
    while len(obstacles) < m:
        x = random.randint(1, n)
        y = random.randint(1, n)
        obstacles.add((x, y))

    # Generate q queries with unique start positions for the balls
    queries = []
    for _ in range(q):
        while True:
            a, b = random.randint(1, n), random.randint(1, n)
            c, d = random.randint(1, n), random.randint(1, n)
            if (a, b) not in obstacles and (c, d) not in obstacles and (a, b) != (c, d):
                break
        queries.append((a, b, c, d))

    return n, m, q, list(obstacles), queries

def format_test_data(n, m, q, obstacles, queries):
    formatted_data = []

    # Format the header with n, m, q
    formatted_data.append(f"{n} {m} {q}")

    # Format the obstacles
    for obstacle in obstacles:
        formatted_data.append(f"{obstacle[0]} {obstacle[1]}")

    # Format the queries
    for query in queries:
        formatted_data.append(f"{query[0]} {query[1]} {query[2]} {query[3]}")

    return "\n".join(formatted_data)

# Generate and format the test data
n, m, q, obstacles, queries = generate_test_data()
formatted_test_data = format_test_data(n, m, q, obstacles, queries)

# Output the formatted test data
# print(formatted_test_data)
with open("in.in","w") as f:
    f.write(formatted_test_data)