package com.kdill;

import java.util.*;

class Searches {
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int vertexes, ArrayList<ArrayList<Integer>> adj) {

        ArrayList<Integer> list = new ArrayList<Integer>(vertexes);

        // dfs is recursion, start with "0 node" and scale through the first instance.
        dfsOfGraph(vertexes, 0, adj, list);

        return list;
    }

    public ArrayList<Integer> dfsOfGraph(int vertexes, int current, ArrayList<ArrayList<Integer>> adj,
            ArrayList<Integer> answers) {

        // we have the existing answers, we're looking for "current" in "adj"

        answers.add(current);

        // loop over the current's adjacency list, skip over ones that are already here.
        ArrayList<Integer> currentAdj = adj.get(current);
        for (Integer item : currentAdj) {

            if (!answers.contains(item)) {

                // we don't have this in the answer array list, do dfs from the next item.
                answers = dfsOfGraph(vertexes, item, adj, answers);
            }
        }

        return answers;
    }

}
