# All Graph Algorithms

## 🔹 **Graph Traversal Algorithms**

These are used to explore all nodes in a graph.

### 1️⃣ **Breadth-First Search (BFS)**

- **Purpose:** Shortest path in **unweighted** graphs, level-order traversal.
- **Graph Type:** Works on **both directed & undirected** graphs.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - Uses a **queue** (FIFO).
  - Start from a node, visit all its neighbors first, then move to their neighbors.
  - Good for **finding shortest paths** in **unweighted** graphs (like social networks, mazes).

### 2️⃣ **Depth-First Search (DFS)**

- **Purpose:** Cycle detection, topological sorting, connected components.
- **Graph Type:** Both directed & undirected.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - Uses **recursion** or an **explicit stack**.
  - Goes deep into a branch before backtracking.
  - Used in **cycle detection** and **finding articulation points**.

---

## 🔹 **Shortest Path Algorithms**

These are used to find the shortest distance from one node to another.

### 3️⃣ **Dijkstra’s Algorithm**

- **Purpose:** Finds the shortest path in a **weighted graph** with **non-negative** weights.
- **Graph Type:** Weighted, directed/undirected.
- **Complexity:**
  - **Without priority queue:** \(O(V^2)\)
  - **With priority queue (Binary Heap):** \(O((V+E) \log V)\)
- **Approach:**
  - Uses a **min-heap (priority queue)**.
  - Greedy algorithm: Always expands the shortest discovered path first.
  - **Fails on graphs with negative weights**.

### 4️⃣ **Bellman-Ford Algorithm**

- **Purpose:** Finds the shortest path, handles **negative weights** (detects negative cycles).
- **Graph Type:** Weighted, directed/undirected.
- **Complexity:** \(O(VE)\)
- **Approach:**
  - Iterates \(V-1\) times, relaxing all edges.
  - Can **detect negative-weight cycles**.
  - Works where Dijkstra **fails** (e.g., financial arbitrage).

### 5️⃣ **Floyd-Warshall Algorithm**

- **Purpose:** Finds all-pairs shortest paths.
- **Graph Type:** Weighted graphs, directed/undirected.
- **Complexity:** \(O(V^3)\)
- **Approach:**
  - Uses **dynamic programming**.
  - Iteratively updates distance matrix for shortest paths.
  - Good for small graphs (dense graphs).

### 6️⃣ **A\* Search Algorithm**

- **Purpose:** Heuristic-based shortest path search (used in **game AI, GPS routing**).
- **Graph Type:** Weighted graphs.
- **Complexity:** \(O(E)\) (depends on heuristic function)
- **Approach:**
  - Uses a **priority queue** with a heuristic function to estimate the shortest path.
  - Faster than Dijkstra for many real-world problems.

---

## 🔹 **Minimum Spanning Tree (MST) Algorithms**

These algorithms find a subset of edges forming a tree that connects all nodes with the **minimum cost**.

### 7️⃣ **Kruskal’s Algorithm**

- **Purpose:** Finds MST using a **greedy** approach.
- **Graph Type:** Weighted, undirected.
- **Complexity:** \(O(E \log E)\) (Sorting edges)
- **Approach:**
  - Sorts edges by weight.
  - Uses **Union-Find** to avoid cycles.
  - Picks the smallest edge that doesn’t form a cycle.

### 8️⃣ **Prim’s Algorithm**

- **Purpose:** Finds MST using **greedy** approach.
- **Graph Type:** Weighted, undirected.
- **Complexity:**
  - **Without priority queue:** \(O(V^2)\)
  - **With priority queue (Heap):** \(O(E \log V)\)
- **Approach:**
  - Uses a **min-heap** to always extend the MST with the smallest weight edge.
  - More efficient than Kruskal for **dense graphs**.

---

## 🔹 **Cycle Detection Algorithms**

Used to check if a graph has a cycle.

### 9️⃣ **Cycle Detection (Undirected Graph)**

- **Approach:** Use **DFS with parent tracking**.
- **Complexity:** \(O(V + E)\)

### 🔟 **Cycle Detection (Directed Graph)**

- **Approach:**
  - **DFS with recursion stack** (back edge detection).
  - **Kahn’s Algorithm (BFS)** (Topological sorting fails if cycle exists).
- **Complexity:** \(O(V + E)\)

---

## 🔹 **Topological Sorting (DAG Processing)**

Used to order nodes in **Directed Acyclic Graphs (DAGs)**.

### 1️⃣1️⃣ **Topological Sorting**

- **Purpose:** Scheduling tasks (dependency resolution).
- **Graph Type:** **Directed Acyclic Graph (DAG)**.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - **DFS-based**: Push nodes onto a stack after finishing recursion.
  - **Kahn’s Algorithm (BFS-based)**: Uses **in-degree** processing.

---

## 🔹 **Strongly Connected Components (SCC)**

Used to find strongly connected components in a **directed graph**.

### 1️⃣2️⃣ **Kosaraju’s Algorithm**

- **Purpose:** Finds SCCs.
- **Graph Type:** Directed graph.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - **DFS 1**: Store finish times.
  - **Transpose graph**.
  - **DFS 2** on transposed graph.

### 1️⃣3️⃣ **Tarjan’s Algorithm**

- **Purpose:** Finds SCCs in a **single DFS traversal**.
- **Graph Type:** Directed graph.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - Uses **low-link values** and **DFS timestamps**.

---

## 🔹 **Maximum Flow Algorithms**

Used for network flow problems.

### 1️⃣4️⃣ **Ford-Fulkerson Algorithm (Edmonds-Karp)**

- **Purpose:** Finds maximum flow in a network.
- **Graph Type:** Directed graph.
- **Complexity:** \(O(VE^2)\)
- **Approach:**
  - Uses **BFS (Edmonds-Karp)** or **DFS** for finding augmenting paths.
  - Uses **Residual Graph** to track available capacities.

### 1️⃣5️⃣ **Dinic’s Algorithm**

- **Purpose:** More efficient max flow algorithm.
- **Graph Type:** Directed graph.
- **Complexity:** \(O(V^2E)\)
- **Approach:**
  - Uses **BFS to find levels**.
  - Uses **DFS to send flow** along augmenting paths.

---

## 🔹 **Other Advanced Algorithms**

### 1️⃣6️⃣ **Eulerian Path/Circuit**

- **Purpose:** Find a path that visits every edge exactly once.
- **Graph Type:** Undirected or Directed.
- **Complexity:** \(O(V + E)\)
- **Approach:**
  - **Eulerian Circuit exists** if all vertices have **even degree**.
  - **Eulerian Path exists** if at most **two vertices have odd degree**.

### 1️⃣7️⃣ **Hamiltonian Path/Circuit (NP-Complete)**

- **Purpose:** Find a path that visits every node exactly once.
- **Graph Type:** Undirected/Directed.
- **Complexity:** \(O(N!)\) (Backtracking).
- **Approach:**
  - **No polynomial-time solution** exists (unless P = NP).
