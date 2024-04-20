
import java.util.ArrayList;
import java.util.Random;
import java.util.List;

import data.GraphNode;
import data.MapGraph;
import data.MyGraph;
import data.Searches;

public class DSTest {
  public static final int RAND_INT_SIZE = 100;

  public static void main(String[] args) {

    // instance a graph, compare with the Graph in other standard libaries
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

    System.out.println(aGraph);

    // graph find node with value 3.
    System.out.println(aGraph.getNode(2).toString());

    // dfs the graph?
    ArrayList<GraphNode> dfsOfGraph = Searches.dfsOfGraph(aGraph);
    System.out.println(dfsOfGraph);


    //map graph dfs. this should be the one I like better.
    MapGraph<Integer> mapGraph = new MapGraph<Integer>();
    //make a set of random integers.
    
    List<Integer> ints = randomIntGen();
    //randomly link things to other ints when adding graph? how do I do that.
    
    for (Integer thing : ints) {
      Random r = new Random();
      for (int links = 0; links < 10; links++) {

        Integer randomInList = ints.get(r.nextInt(ints.size()));

        //don't link to yourself.
        if (randomInList == thing) continue;

        mapGraph.addEdge(thing, randomInList, true);
      }
    }

    System.out.println(mapGraph);
    System.out.println(Searches.dfsOfGraph(mapGraph));
  }

  /**
   * create a set of RAND_INT_SIZE unique integers for other things
   */
  public static List<Integer> randomIntGen() {

    Random rand = new Random();

    List<Integer> ints = new ArrayList<>();

    for (int i = 0; i < RAND_INT_SIZE; ) {
      Integer next = rand.nextInt(1000);

      if (!ints.contains(next)) {
        ints.add(next);
        i++;
      }
    }

    return ints;
  }


}
