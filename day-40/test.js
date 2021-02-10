class Graph {
  constructor(v) {
    this.edge = 0;
    this.vertice = v;
    this.adj = [];
    this.visited = new Map();
    for (let i = 0; i < v; i++) {
      this.adj[i] = [];
      this.adj[i].push('');
    }
  }
  add_edge(u, v) {
    this.adj[u].push(v);
  }

  dfsHelper(src, visited) {
    this.visited[src] = true;
    visited[src] = true;
    process.stdout.write(src + '');
    this.adj[src].forEach(item => {
      if (!visited[item] && !this.visited[item]) {
        this.dfsHelper(item, visited);
      }
    });
  }

  dfs(src) {
    for (let i = 0; i < this.vertice; i++) {
      this.visited.set(i, false);
    }
    this.dfsHelper(src, this.visited);
  }
}

let g = new Graph(5);
g.add_edge(1, 0);
g.add_edge(1, 2);
g.add_edge(1, 5);
g.add_edge(3, 5);
g.add_edge(4, 5);
g.add_edge(1, 3);
g.dfs(3);