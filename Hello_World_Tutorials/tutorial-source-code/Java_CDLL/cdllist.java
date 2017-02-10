package cdllist;

import bridges.base.CircDLelement;
import bridges.connect.Bridges;
import model.Student;

public class Main {

  public static void main(String[] args) throws , ParseException {

      Bridges<String, Student> bridge = new Bridges<String, Student>(6, "YOUR_API_KEY", "YOUR_USER_ID");

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
       * new CircDLelement<>(label, genericData)
       */
      //initializing all elements with empty labels, and with the student data. See Object model.Student.java
      CircDLelement<Student> el0 = null;
      for(int i = 0; i < students.length; i++) {
          if(i > 0) {
              el0 = insertFront(el0, new CircDLelement("",students[i]));
          }else{
              el0 = new CircDLelement("",students[i]);
          }
      }

      CircDLelement<Student> current = el0;
      do{
          current.setLabel(current.getValue().getStudentLabel());
          current.getVisualizer().setColor(current.getValue().getFavoriteColor());

          current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
          current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours()*.75);

          current.getLinkVisualizer(current.getPrev()).setColor(current.getValue().getDislikeColor());
          current.getLinkVisualizer(current.getPrev()).setThickness(current.getValue().getStudentCreditHours()*.75);

          current = current.getNext();
      }while(current.getIdentifier() != el0.getIdentifier());

      bridge.setDataStructure(el0);
      bridge.visualize();


  }


  public static CircDLelement insertFront(CircDLelement tailElement,
                                          CircDLelement newElement){
      CircDLelement tailNextElement = tailElement.getNext();

      newElement.setNext(tailNextElement);
      newElement.setPrev(tailElement);

      tailNextElement.setPrev(newElement);
      tailElement.setNext(newElement);
      return tailElement;
  }

}
