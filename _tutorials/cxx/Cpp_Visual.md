Note: For C++, Bridges represents colors with its own color class. The class supports, rgb, rgba, hex, and named color values

### Setup our DataStructure

-   To showcase both element and edge visualization changes we will use DLelements

      //See DLelement Guide
      DLelement<string> e0("","Original");
      DLelement<string> e1("","Changed");
      e0.setNext(e1);
      e1.setPrev(e0);


-   In this example we will keep e0 and e0's next edge default, while changing e1 and e1's prev edge.

### Element Visualization changing

-   Color can be changed like this:

e1.setColor(Color(0,0,255,128));

-   Size can be changed like this:

e1.setSize(20);

-   Shape can be changed like this:

e1.setShape(DIAMOND);

### Edge Visualization changing

-   Obtain the LinkVisualizer between the elements.

LinkVisualizer\* lv = e1.getLinkVisualizer(&e0);

-   Color can be changed like this:

lv->setColor(Color(255,0,0,128));

-   Thickness can be changed like this:

lv->setThickness(5);