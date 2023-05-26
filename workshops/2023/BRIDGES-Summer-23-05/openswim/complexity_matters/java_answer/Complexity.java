import bridges.connect.Bridges;
import bridges.base.LineChart;
import java.util.ArrayList;
import java.lang.Math;


class Complexity {

  public static void task1(Bridges bridges) throws Exception {
    LineChart lc = new LineChart();
    lc.setTitle("Task 1");
    lc.setXLabel("n");
    lc.setYLabel("Time in seconds");
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 100000; i = i + 1000) {
        double n = (double) i;
        double t = (double) (5 * 10000.*i) / (1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("5.10^4 n at 1MHz", xdata, ydata);
    }

    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 100000; i = i + 1000) {
        double n = (double) i;
        double t = (double) 10000.*i / (1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("10^4 n at 1MHz", xdata, ydata);
    }

    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 100000; i = i + 1000) {
        double n = (double) i;
        double t = (double) 1000.*i*i / (486. * 1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("10^3 n^2 on a GameCube (486Mhz)", xdata, ydata);
    }


    
    bridges.setDataStructure(lc);
    bridges.visualize();
  }

  public static void task2(Bridges bridges) throws Exception {
    LineChart lc = new LineChart();
    lc.setTitle("Something");
    lc.setXLabel("n");
    lc.setYLabel("Time in seconds");
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 10000; i = i + 300) {
        double n = (double) i;
        double t = (double) 10000.*i / (1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("10^4 n at 1MHz", xdata, ydata);
    }
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 10000; i = i + 300) {
        double n = (double) i;
        double t = (double) (100.*i * i) / (100. * 1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("100 n^2 at 100MHz", xdata, ydata);
    }
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 10000; i = i + 100) {
        double n = (double) i;
        double t = ((double) i * i * i * i) / (10. * 1000.*1000.*1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("n^4 at 10GHz", xdata, ydata);
    }


    bridges.setDataStructure(lc);
    bridges.visualize();
  }

  public static void task3(Bridges bridges) throws Exception {
    LineChart lc = new LineChart();
    lc.setTitle("Something");
    lc.setXLabel("n");
    lc.setYLabel("Time in seconds");
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 50; i = i + 3) {
        double n = (double) i;
        double t = (double) 10000.*i / (1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("10^4 n at 1MHz", xdata, ydata);
    }
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 50; i = i + 3) {
        double n = (double) i;
        double t = (double) (100.*i * i) / (100. * 1000. * 1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("100 n^2 at 100MHz", xdata, ydata);
    }
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 50; i = i + 3) {
        double n = (double) i;
        double t = ((double) i * i * i * i) / (10. * 1000.*1000.*1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("n^4 at 10GHz", xdata, ydata);
    }
    {
      ArrayList<Double> xdata = new ArrayList<Double>();
      ArrayList<Double> ydata = new ArrayList<Double>();
      for (int i = 1; i < 50; i = i + 3) {
        double n = (double) i;
        double t = ((double) Math.pow(2, n)) / (1000. * 1000.*1000.*1000.);
        xdata.add(n);
        ydata.add(t);
      }
      lc.setDataSeries("2^n at 1PHz", xdata, ydata);
    }

    bridges.setDataStructure(lc);
    bridges.visualize();
  }


  public static void main(String args[]) throws Exception {
    Bridges bridges = new Bridges(28, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

    bridges.setTitle("Complexity Matters");
    bridges.setDescription("Plotting the complexity of different function on different machines");
		     
    
    task1(bridges);
    task2(bridges);
    task3(bridges);
  }
}
