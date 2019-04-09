### Create a new .java file

### Imports

-   We need to include these Bridges files to give access to all the classes/methods needed to interact with Bridges
-   In your .java file, enter the following code snippets:

      import bridges.connect.Bridges;
      import bridges.base.GraphAdjList;


### Main Exception

-   By adding a throw exception we can forgo messy try/catch blocks in our code for our Bridges calls
-   In your .java file, add a throw exception to the main function so it looks like this:

public static void main(String\[\] args) throws Exception

### Inside our Main

-   First we need to create our Bridges object and initialize our Bridges Credentials

Bridges<String, String> bridges = new Bridges<>(5, "YOUR\_USER\_ID", "YOUR\_API\_KEY");

Note that you must replace the above strings with your BRIDGES credentials.-   Then we can create our GraphAdjList

GraphAdjList<String,String> g = new GraphAdjList<>();

-   Now add some verticies to the graph. In this example, vertex ids are strings

      g.addVertex("He","");
      g.addVertex("llo","");
      g.addVertex("Wo","");
      g.addVertex("rld","");


-   And add some edges to the graph

      g.addEdge("He","llo",1);
      g.addEdge("llo","Wo",1);
      g.addEdge("Wo","rld",1);
      g.addEdge("He","Wo",1);
      g.addEdge("He","rld",1);


-   Now we pass the graph object to BRIDGES

bridges.setDataStructure(g);

-   Finaly we call the visualize function

bridges.visualize();

#### **Code Summary:** Your .java file should look like this

    import bridges.connect.Bridges;
    import bridges.base.GraphAdjList;

    public class HelloWorld
    {
        public static void main(String\[\] args) throws Exception
        {
            //create the Bridges object
            Bridges<String, String> bridges = new Bridges<>(5, "YOUR\_API\_KEY", "YOUR\_USER\_ID");

            //create graph
            GraphAdjList<String,String> g = new GraphAdjList<>();

            //add nodes
            g.addVertex("He","");
            g.addVertex("llo","");
            g.addVertex("Wo","");
            g.addVertex("rld","");

            //add edges
            g.addEdge("He","llo",1);
            g.addEdge("llo","Wo",1);
            g.addEdge("Wo","rld",1);
            g.addEdge("He","Wo",1);
            g.addEdge("He","rld",1);

            //pass graph
            bridge.setDataStructure(g);

            //visualize data structure
            bridge.visualize();
        }
    }