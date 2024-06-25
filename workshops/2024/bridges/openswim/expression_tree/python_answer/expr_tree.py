from bridges.bridges import *
from bridges.tree_element import *

def main():
    # create the Bridges object, set credentials

    bridges = Bridges(20, "YOUR_USER_ID", "YOUR_API_KEY")


    # title, description
    bridges.set_title("An Expression Tree Example Using TreeElements")
    bridges.set_description("A manually constructed expression tree for sqrt(Ax^2 + By + c)")

    # create tree nodes
    a = TreeElement(e="a", label="a")
    x = TreeElement(e="x", label="x")
    x2 = TreeElement(e="x", label='x')
    b = TreeElement(e="b", label='b')
    y = TreeElement(e="y", label="y")
    c = TreeElement(e="c", label='c')
    z = TreeElement(e="z", label="z")
    times1 = TreeElement(e="*", label="*")
    times2 = TreeElement(e="*", label="*")
    times3 = TreeElement(e="*", label="*")
    times4 = TreeElement(e="*", label="*")
    plus1 = TreeElement(e="+", label="+")
    plus2 = TreeElement(e="+", label="+")
    plus3 = TreeElement(e="+", label="+")
    qrt = TreeElement(e="sqrt", label="sqrt")

    qrt.size = 49.0
    plus3.size = 30.0

    # add links to children
    times1.add_child(a)
    times1.add_child(x)

    times2.add_child(times1)
    times2.add_child(x2)

    times3.add_child(b)
    times3.add_child(y)

    plus1.add_child(times2)
    plus1.add_child(times3)

    times4.add_child(c)
    times4.add_child(z)

    plus2.add_child(times3)
    plus2.add_child(times4)

    plus3.add_child(plus1)
    plus3.add_child(times4)

    qrt.add_child(plus3)

    # set some visual attributes
    times1.color = "red"
    times2.color = "red"
    times3.color = "red"
    times4.color = "red"
    plus1.color = "red"
    plus2.color = "red"
    plus3.color = "red"
    qrt.color = "red"

    qrt.shape = "square"

    qrt.get_link_visualizer(plus3).color = "green"
    qrt.get_link_visualizer(plus3).thickness = 5.0
    plus3.get_link_visualizer(plus1).thickness = 3.0
    plus3.get_link_visualizer(times4).thickness = 3.0


    # set visualizer type
    bridges.set_data_structure(qrt)

    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()
