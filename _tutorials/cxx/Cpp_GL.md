### Create a new .cpp file

### Includes

-   We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges
-   In your .cpp file, enter the following code snippets:

      #include "GraphAdjList.h"
      #include "Bridges.h"


### Namespace

-   By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls
-   In your .cpp file, enter the following code snippet:

using namespace bridges;

### Inside our Main

-   First we need to initialize our Bridges Credentials

Bridges::initialize(5, "YOUR\_USER\_ID", "YOUR\_API\_KEY");

Note that you must replace the above 2 strings with your BRIDGES credentials-   Then we can create our GraphAdjList

GraphAdjList<string,int> g;

-   Now add some verticies to the graph. We use strings as vertex ids in this example

      g.addVertex("He",0);
      g.addVertex("llo",0);
      g.addVertex("Wo",0);
      g.addVertex("rld",0);


-   Now add some edges between these vertices to the graph

      g.addEdge("He","llo",1);
      g.addEdge("llo","Wo",1);
      g.addEdge("Wo","rld",1);
      g.addEdge("He","Wo",1);
      g.addEdge("He","rld",1);


-   Now we pass the graph object to BRIDGES

Bridges::setDataStructure(&g);

-   Finaly we visualize the graph

Bridges::visualize();

#### **Code Summary:** Your .cpp file should look like this

    #include "GraphAdjList.h"
    #include "Bridges.h"

    using namespace bridges;

    int main()
    {
        //create the Bridges object
        Bridges::initialize("YOUR\_API\_KEY","YOUR\_USER\_ID",5);

        //create graph
        GraphAdjList<string,int> g;

        //add nodes
        g.addVertex("He",0);
        g.addVertex("llo",0);
        g.addVertex("Wo",0);
        g.addVertex("rld",0);

        //add edges
        g.addEdge("He","llo",1);
        g.addEdge("llo","Wo",1);
        g.addEdge("Wo","rld",1);
        g.addEdge("He","Wo",1);
        g.addEdge("He","rld",1);

        //pass graph
        Bridges::setDataStructure(&g);

        //visualize data structure
        Bridges::visualize();
    }