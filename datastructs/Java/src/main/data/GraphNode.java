package data;

import java.util.*;

public class GraphNode {

  static long idCounter = 0;
  private long nodeId;
  
  //the node class just has the adjacency list and "data" will come later.
  private LinkedList<GraphNode> adjacentNodes;
  private Object data;

  public GraphNode() {

    this(null);
  }

  public GraphNode(Object data) {

    this(data, null);
  }

  public GraphNode(Object data, LinkedList<GraphNode> adjacentNodes) {

    this.data = data;
    //if adjacent nodes null, make it.
    if (adjacentNodes == null) {
      adjacentNodes = new LinkedList<GraphNode>();
    }
    this.adjacentNodes = adjacentNodes;
    this.nodeId = idCounter++;
  }


  public void addAdjacent(GraphNode node) {
    adjacentNodes.add(node);
  }

  public void removeAdjacent(GraphNode node) {
    //scale the list, find equal id, remove.
    for (GraphNode aNode : this.adjacentNodes) {
      if (node.getNodeId() == aNode.getNodeId()) {
        adjacentNodes.remove(aNode);
        break;
      }
    }
  }

  public Object getData() { return data; }


  public long getNodeId() { return nodeId; }
  public LinkedList<GraphNode> getAdjacents() { return adjacentNodes; }


  @Override
  public String toString() {

    StringBuilder sb = new StringBuilder();
    sb.append(nodeId);
    sb.append("(" + data.toString() + ")");
    sb.append("->");

    ArrayList<Long> adjNodeIdxList = new ArrayList<Long>();
    for (GraphNode adj : adjacentNodes) {
      adjNodeIdxList.add(adj.getNodeId());
    }
    sb.append(adjNodeIdxList);

    return sb.toString();
  }
}
