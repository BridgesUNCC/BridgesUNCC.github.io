package Java_CSLL;

import bridges.base.CircSLelement;
import bridges.connect.Bridges;

public class csllist {

  public static void main(String[] args) throws Exception {

      final String YOUR_API_KEY = "";
      final String YOUR_USER_ID = "";
      Bridges<String, Student> bridge = new Bridges<String, Student>(5, YOUR_API_KEY, YOUR_USER_ID);

      Student[] students = {
                      new Student(
                              "00000000000",
                              "Gretel Chaney",
                              "CS",
                              "g.chaney@generated.com",
                              "magenta",
                              "blue",
                              9.0,
                              "https://randomuser.me/api/portraits/med/women/45.jpg"
                      ),
                      new Student(
                              "00000000001",
                              "Karol Soderman",
                              "SIS",
                              "k.soderman@generated.com",
                              "magenta",
                              "red",
                              11.0,
                              "https://randomuser.me/api/portraits/med/women/46.jpg"
                      ),
                      new Student(
                              "00000000002",
                              "Lamont Kyler",
                              "BIO",
                              "l.kyler@generated.com",
                              "yellow",
                              "green",
                              12.0,
                              "https://randomuser.me/api/portraits/med/men/80.jpg"
                      ),
                      new Student(
                              "00000000003",
                              "Gladys Serino",
                              "CS","g.serino@generated.com",
                              "blue",
                              "magenta",
                              9.0,
                              "https://randomuser.me/api/portraits/med/women/2.jpg"
                      ),
                      new Student("00000000004",
                              "Starr Mcginn",
                              "CS",
                              "s.mcginn@generated.com",
                              "red",
                              "yellow",
                              15.0,
                              "https://randomuser.me/api/portraits/med/men/87.jpg")
      };

      /**
         * new CircSLelement<>(label, genericData)
         */
        CircSLelement<Student> el0 = new CircSLelement("",students[0]);
        CircSLelement<Student> current = el0;

        for(int i = 1; i < students.length; i++){
            current.setNext(new CircSLelement("", students[i]));

            //handles the last element
            if(i == students.length-1){
                //getting the last element
                current = current.getNext();

                //point the last element to the first element, so the list becomes circular.
                current.getNext().setNext(el0);
            }

            //set the current element to be the next element
            current = current.getNext();
        }


        current = el0;

        do{
            current.setLabel(current.getValue().getStudentLabel());
            current.getVisualizer().setColor(current.getValue().getFavoriteColor());

            current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
            current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours()*0.75);

            current = current.getNext();
        }while(current.getIdentifier() != el0.getIdentifier());

        bridge.setDataStructure(el0);
        bridge.visualize();

  }

}
