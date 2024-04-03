
import data.GraphNode;
import data.MyGraph;

public class DSTest {


  public static void main(String[] args) {


    //instance a graph, compare with the Graph in other standard libaries
    MyGraph aGraph = new MyGraph();
    GraphNode node1 = new GraphNode(1);
    GraphNode node2 = new GraphNode(2);
    GraphNode node3 = new GraphNode(3);


    node1.addAdjacent(node2);
    node2.addAdjacent(node1);
    node2.addAdjacent(node3);
    node3.addAdjacent(node1);

    aGraph.addNode(node1);
    aGraph.addNode(node2);
    aGraph.addNode(node3);


    
    //graph find node with value 3.
      


  }
}
