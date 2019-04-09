Note: For Java, Bridges stores visualization properties in an ElementVisualizer class owned by each element. So, to get change each property we must retrieve the element's ElementVisualizer. Also Java handles opacity seperately from color.

### Setup our DataStructure

-   To showcase both element and edge visualization changes we will use DLelements

      //See DLelement Guide
      DLelement<String> e0 = new DLelement<>("","Original");
      DLelement<String> e1 = new DLelement<>("","Changed");
      e0.setNext(e1);
      e1.setPrev(e0);


-   In this example we will keep e0 and e0's next edge default, while changing e1 and e1's prev edge.

### Element Visualization changing

-   Color can be changed like this:

e1.getVisualizer().setColor("blue");

-   Opacity can be changed like this:

e1.getVisualizer().setOpacity(.5);

-   Size can be changed like this:

e1.getVisualizer().setSize(20);

-   Shape can be changed like this:

e1.getVisualizer().setShape("diamond");

### Edge Visualization changing

-   Color can be changed like this:

e1.getLinkVisualizer(e0).setColor("red");

-   Opacity can be changed like this:

e1.getLinkVisualizer(e0).setOpacity(.5);

-   Thickness can be changed like this:

e1.getLinkVisualizer(e0).setThickness(5);