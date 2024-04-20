package data;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.List;
import java.util.Set;

public class MapGraph<T> {

  private Map<T, List<T>> nodeMap = new HashMap<>();

  public MapGraph() {
    // I don't think I need to construct anything?
  }

  public void addNode(T node) {
    nodeMap.put(node, new LinkedList<T>());
  }

  public void addEdge(T source, T destination, boolean bidirectional) {

    if (!nodeMap.containsKey(source)) {
      this.addNode(source);
    }

    if (!nodeMap.containsKey(destination)) {
      this.addNode(destination);
    }

    // now that we know they both exist, add the thing to the nodemap
    //only add if contains, duplicates waste space.
    if (!this.containsEdge(source, destination, false)) {
      nodeMap.get(source).add(destination);
    }

    if (bidirectional == true && !this.containsEdge(source, destination, false)) {
      // also do dest to source
      nodeMap.get(destination).add(source);
    }
  }

  public void removeNode(T node) {
    // first remove itself, then go through each entry to see remove connections.
    nodeMap.remove(node);

    for (List<T> entry : nodeMap.values()) {
      entry.remove(node);
    }
  }

  public Set<T> getNodes() {
    return nodeMap.keySet();
  }

  public List<T> getAdjList(T node) {
    return nodeMap.get(node);
  }

  public void removeEdge(T src, T dest, boolean bidirection) {
    List<T> srcAdjList = nodeMap.get(src);
    if (srcAdjList != null)
      srcAdjList.remove(dest);

    if (bidirection) {
      List<T> destAdjList = nodeMap.get(dest);
      if (destAdjList != null)
        destAdjList.remove(src);
    }
  }

  public boolean containsNode(T node) {
    return nodeMap.containsKey(node);
  }

  public boolean containsEdge(T source, T dest, boolean bidirection) {
    List<T> sourceAdjList = nodeMap.get(source);
    if (!bidirection)
      return sourceAdjList != null && sourceAdjList.contains(dest);

    List<T> destAdjList = nodeMap.get(dest);

    return sourceAdjList != null && sourceAdjList.contains(dest) || destAdjList != null && destAdjList.contains(source);
  }

  public int size() {
    return nodeMap.keySet().size();
  }

  @Override
  public String toString() {
    // TODO Auto-generated method stub
    StringBuilder sb = new StringBuilder();

    for (T node : nodeMap.keySet()) {
      sb.append(node.toString() + "->[");
      List<T> adjs = nodeMap.get(node);
      for (T adjNode : adjs) {
        sb.append(adjNode.toString() + ",");
      }
      sb.append("]\n");
    }

    return sb.toString();
  }
}
