from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title, description
    bridges.set_title("Test of US Map with State Boundaries")

    #pass no parameters for the whole map
    state_info = get_map(['iowa', 'california', 'north carolina'])

    bridges.set_coord_system_type('albersusa')
    bridges.set_map_overlay(True)
    bridges.set_map(state_info)
    bridges.set_json_flag(True)

    #placeholder for assigning a viz type to BRIDGES
    el0 = DLelement()

    #visualizes iowa and california with counties
    bridges.set_data_structure(el0)
    bridges.visualize()

    #hides all counties and only shows state outline
    for i in range(len(state_info)):
        state_info[i].view_counties = False

    bridges.visualize()

    #colors states red
    for i in range(len(state_info)):
        state_info[i].fill_color = 'red'

    bridges.visualize()

    #show counties and make color green, stroke black, and width 1.0
    for i in range(len(state_info)):
        state_info[i].view_counties = True
        for j in range(len(state_info[i].counties)):
            state_info[i].counties[j].fill_color = 'green'
            state_info[i].counties[j].stroke_color = 'black'
            state_info[i].counties[j].width = 1.0

    bridges.visualize()



if __name__ == '__main__':
    main()
