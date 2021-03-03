import java.util.*;

class Graph {
    HashMap<Integer, LinkedList<Integer>> adj = new HashMap<Integer, LinkedList<Integer>>();

    void add_edge(Integer u, Integer v) {
        LinkedList<Integer> vertic = new LinkedList<Integer>();
        vertic.add(v);
        LinkedList<Integer> vertic2 = new LinkedList<Integer>();
        vertic2.add(u);
        adj.put(u, vertic);
        adj.put(v, vertic2);
    }
}

public class App {
    Graph g;

    void dfsHelper(Integer src, HashMap<Integer, Boolean> visited) {
        visited.put(src, true);
        System.out.println(src + " -> ");
        for (Integer nbr : g.adj.get(src)) {
            if (visited.get(nbr) == false) {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(Integer src) {
        HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();
        dfsHelper(src, visited);
    }

    public static void main(String[] args) throws Exception {
        App g1 = new App();
        g1.g = new Graph();
        g1.g.add_edge(1, 2);
        g1.g.add_edge(1, 3);
        g1.g.add_edge(2, 4);
        g1.g.add_edge(2, 5);
        g1.g.add_edge(3, 6);
        g1.g.add_edge(3, 7);
        g1.dfs(1);
    }
}
