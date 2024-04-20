package data;

import java.util.*;
import data.MyGraph;
import data.GraphNode;
import data.MapGraph;

public class Searches {
    // Function to return a list containing the DFS traversal of the graph.
    public static ArrayList<GraphNode> dfsOfGraph(MyGraph aGraph) {

        ArrayList<GraphNode> list = new ArrayList<GraphNode>();
        GraphNode node = aGraph.getNode(0);

        // dfs is recursion, start with "0 node" and scale through the first instance.
        dfsOfGraph(aGraph.size(), node, aGraph, list);

        return list;
    }

    public static ArrayList<GraphNode> dfsOfGraph(int vertexes, GraphNode currentNode, MyGraph aGraph,
            ArrayList<GraphNode> answers) {

        // we have the existing answers, we're looking for "current" in "adj"
        answers.add(currentNode);

        // loop over the current's adjacency list, skip over ones that are already here.
        for (GraphNode adj : currentNode.getAdjacents()) {
            if (!answers.contains(adj)) {

                // we don't have this in the answer array list, do dfs from the next item.
                answers = dfsOfGraph(vertexes, adj, aGraph, answers);
            }
        }

        return answers;
    }

    public static ArrayList<Integer> dfsOfGraph(MapGraph<Integer> aGraph) {
        ArrayList<Integer> list = new ArrayList<Integer>();

        Set<Integer> nodes = aGraph.getNodes();

        // dfs is recursion, start with "0 node" and scale through the first instance.
        for (Integer node : nodes) {
            dfsOfGraph(node, aGraph, list);
        }

        return list;
    }

    public static ArrayList<Integer> dfsOfGraph(Integer current, MapGraph<Integer> aGraph, ArrayList<Integer> answers) {

        // we have the existing answers, we're looking for "current" in "adj"
        if (!answers.contains(current)) {
            answers.add(current);
        }

        // loop over the current's adjacency list, skip over ones that are already here.
        for (Integer adj : aGraph.getAdjList(current)) {
            if (!answers.contains(adj)) {

                // we don't have this in the answer array list, do dfs from the next item.
                answers = dfsOfGraph(adj, aGraph, answers);
            }
        }

        return answers;
    }

    public static ArrayList<Integer> bfsOfGraph(MapGraph<Integer> aGraph) {

        ArrayList<Integer> list = new ArrayList<>();

        Set<Integer> nodes = aGraph.getNodes();

        for (Integer node : nodes) {
            bfsOfGraph(node, aGraph, list);
        }

        return list;
    }

    public static ArrayList<Integer> bfsOfGraph(Integer current, MapGraph<Integer> aGraph, ArrayList<Integer> answers) {

        //bfs is "exhaust adjacents, then dig", queue them basically
        if (!answers.contains(current)) {
            answers.add(current);
        }

        Queue<Integer> nodeQueue = new LinkedList<Integer>();

        for (Integer adj : aGraph.getAdjList(current)) {
            if (answers.contains(adj)) {
                continue;
            }

            answers.add(adj);
            nodeQueue.add(adj);
        }

        //then iterate over queue and remove until empty.
        while(!nodeQueue.isEmpty()) {
            Integer node = nodeQueue.remove();

            if (node != null)
            bfsOfGraph(node, aGraph, answers);
        }

        return answers;
    }
}
