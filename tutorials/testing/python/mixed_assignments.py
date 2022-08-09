from bridges.bridges import *
from bridges.tree_element import *
from bridges.array2d import *
from bridges.circ_sl_element import *
from bridges.rectangle import *
from bridges.circle import *
from bridges.text import *
from bridges.polygon import *
from bridges.polyline import *
from bridges.color import *
from bridges.color_grid import *
from bridges.symbol_collection import *
import sys

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Mixed Assignments Test")

    # create tree nodes
    t0 = TreeElement(e="Root", label="Root")
    t1 = TreeElement(e="Child1", label="Child1")
    t2 = TreeElement(e="Child2", label='Child2')
    t3 = TreeElement(e="Child3", label='Child3')

    # add links to children
    t0.add_child(t1)
    t0.add_child(t2)
    t0.add_child(t3)

    # set some visual attributes
    t0.color = "red"
    t0.shape = "diamond"
    t0.opacity = 0.5
	
    # visualize
    bridges.set_data_structure(t0)
    bridges.visualize()

    #list
    head = CircSLelement(e="head", label="head");
    csl1 = CircSLelement(e="head", label="el1");
    csl2 = CircSLelement(e="head", label="el2");
    tail = CircSLelement(e="head", label="tail");

    # add links to list
    head.next = csl1;
    csl1.next = csl2;
    csl2.next = tail;
    tail.next = head;

    # set data structure and visualize
    bridges.set_title("A small circular singly linked list")
    bridges.set_data_structure(head);
    bridges.visualize();


    #2D array
    num_rows = 4
    num_cols = 4
    my_array = Array2D(rows = num_rows, cols = num_cols);

    # populate the array
    for row in range(num_rows):
        for col in range(num_cols):
            my_array[row, col].label = "El " + str(row * num_cols + col);

    # set a color
    my_array[0, 0].color = "purple";

    # set data structure and visualize
    bridges.set_title("A 2D Array");
    bridges.set_data_structure(my_array);
    bridges.visualize();

    #shape collection
    sc = SymbolCollection();

    r1 = Rectangle(w=25, h=25);
    r1.fill_color = "black"
    sc.add_symbol(r1);

    s1 = Circle(locx = 25.0, locy = 0.0, r = 10);
    s1.fill_color = "yellow"
    sc.add_symbol(s1);

    s2 = Circle(locx = -25.0, locy = 0.0, r = 10);
    s2.fill_color = "yellow";
    sc.add_symbol(s2);

    s3 = Circle(locx=0.0, locy=25.0, r = 10);
    s3.fill_color = "yellow";
    sc.add_symbol(s3);

    s4 = Circle(locx= 0.0, locy = -25.0, r = 10);
    s4.fill_color = "yellow"
    sc.add_symbol(s4);

    # set data structure and visualize
    bridges.title = "A Symbol Collection";
    bridges.set_data_structure(sc);
    bridges.visualize();

    #color grid
    rows = 30
    cols = 30
    purple = Color("purple");
    black = Color("black");

    cg = ColorGrid(rows, cols, purple);

    cg.set(12, 12, black);
    cg.set(12, 18, black);

    for i in range(10):
        cg.set(18, 10 + i, black);

    # set data structure and visualize
    bridges.title = "Color Grid Example";
    bridges.set_data_structure(cg);
    bridges.visualize();

if __name__ == "__main__":
    main()

