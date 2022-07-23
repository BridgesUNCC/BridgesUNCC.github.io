from bridges import *

def task1(bridges):
    lc = LineChart()
    lc.title = "Machine Performance Plots"
    lc.x_label = "n"
    lc.y_label = "Time in seconds"

    xdata = []
    ydata = []

    for i in range(1, 100000, 1000):
        t = (10000 * i) / (1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("10^4 n at 1MHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 100000, 1000):
        t = (5 * 10000 * i) / (1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("5.10^4 n at 1MHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 100000, 1000):
        t = (100 * i * i) / (100 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("10^2 n^2 at 100MHz", xdata.copy(), ydata.copy())

    #bridges.set_visualize_JSON(True)
    bridges.set_data_structure(lc)
    bridges.visualize()

def task2(bridges):
    lc = LineChart()
    lc.title = "Something"
    lc.x_label = "n"
    lc.y_label = "Time in seconds"

    xdata = []
    ydata = []

    for i in range(1, 10000, 300):
        t = float(10000 * i) / (1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("10^4 n at 1MHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 10000, 300):
        t = float(100 * i * i) / (100 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("100 n^2 at 100MHz", xdata.copy(), ydata.copy())    
    
    xdata.clear()
    ydata.clear()

    for i in range(1, 10000, 100):
        t = float(i * i * i * i) / (10 * 1000 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("n^4 at 10GHz", xdata.copy(), ydata.copy())    

    #bridges.set_visualize_JSON(True)
    bridges.set_data_structure(lc)
    bridges.visualize()

def task3(bridges):
    lc = LineChart()
    lc.title = "Something"
    lc.x_label = "n"
    lc.y_label = "Time in seconds"

    xdata = []
    ydata = []

    for i in range(1, 50, 3):
        t = float(10000 * i) / (1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("10^4 n at 1MHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 50, 3):
        t = float(100 * i * i) / (100 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("100 n^2 at 100MHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 50, 3):
        t = float(i * i * i * i) / (10 * 100 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("n^4 at 10GHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()

    for i in range(1, 50, 3):
        t = pow(2, i) / (1000 * 1000 * 1000 * 1000)
        xdata.append(float(i))
        ydata.append(t)

    lc.set_data_series("n^4 at 10GHz", xdata.copy(), ydata.copy())

    xdata.clear()
    ydata.clear()
    
    bridges.set_data_structure(lc)
    bridges.visualize()



def main():
    bridges = Bridges(228, "BRIDGES_USER_ID", "BRIDGES_API_KEY")

    bridges.set_title("Big Oh Matters")
    bridges.set_description("Plot Big Oh runtimes on a Bridges Line Chart.")

    task1(bridges)
    task2(bridges)
    task3(bridges)

if __name__ == '__main__':
    main()
