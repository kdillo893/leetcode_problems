package data;

import java.util.*;
import data.GraphNode;

public class MyGraph {
  
  //graph will have nodes and edges. each node contains an adjacency list.
  //adjacency list is a linked list of nodes that the node is adjacent to.
  
  private List<GraphNode> theNodes;

  public MyGraph() {
    theNodes = new ArrayList<GraphNode>();
  }




  public GraphNode getNode(int nodeIdx) {
    return theNodes.get(nodeIdx);
  }

  public void addNode(GraphNode node) {

    theNodes.add(node);
  }

  public void removeNode(GraphNode node) {

  }
}
