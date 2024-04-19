package data;

import java.util.*;
import data.MyGraph;
import data.GraphNode;

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
}
