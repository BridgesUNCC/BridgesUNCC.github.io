### Create a new .cpp file

### Includes

-   We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges
-   In your .cpp file, enter the following code snippets:

      #include "TreeElement.h"
      #include "Bridges.h"


### Namespace

-   By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls
-   In your .cpp file, enter the following code snippet:

using namespace bridges;

### Inside our Main

-   First we need to initialize our Bridges Credentials

Bridges::initialize(3, "YOUR\_API\_KEY","YOUR\_USER\_ID");

Note that you must replace the two strings above with your BRIDGES credentials.

-   Then we can create our TreeElements

      TreeElement<int> e0(0,"");
      TreeElement<int> e1(0,"Hello");
      TreeElement<int> e2(0,"World");


-   Now link the TreeElements together

      e0.setLeft(&e1);
      e0.setRight(&e2);


-   Now we pass the root of the binary tree to BRIDGES

Bridges::setDataStructure(&e0);

-   Finnaly we call the visualize function

Bridges::visualize();

#### **Code Summary:** Your .cpp file should look like this

    #include "TreeElement.h"
    #include "Bridges.h"

    using namespace bridges;

    int main()
    {
        //create the Bridges object
        Bridges::initialize("YOUR\_API\_KEY","YOUR\_USER\_ID",3);

        //create elements
        TreeElement<int> e0(0,"");
        TreeElement<int> e1(0,"Hello");
        TreeElement<int> e2(0,"World");

        //link elements
        e0.setLeft(&e1);
        e0.setRight(&e2);

        //pass first element of data structure
        Bridges::setDataStructure(&e0);

        //visualize data structure
        Bridges::visualize();
    }