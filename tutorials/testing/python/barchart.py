from bridges.bridges import *
from bridges.bar_chart import *
import sys


def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("BarChart Tutorial")
    bridges.set_description("BarCharts are cool!")

    bc = BarChart()
    bc.title = "Hello World BarChart!"
    bc.subtitle = "woah!"
    bc.categories_label = "Continents"
    bc.value_label = "Population (in millions)"
    bc.orientation = "horizontal"
    bc.tooltip_suffix = " millions"

    bc.categories = ["Africa", "America", "Asia", "Europe"]

    bc.add_data_series ("year 1", [10, 100, 40, 23])
    bc.add_data_series ("year 2", [100, 10, 80, 232])
    
    # set visualizer type
    bridges.set_data_structure(bc)
    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

