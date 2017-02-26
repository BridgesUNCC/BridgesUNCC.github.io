package Java_DLL;

import bridges.base.DLelement;
import bridges.connect.Bridges;

public class dllist {

  public static void main(String[] args) throws Exception {

      final String YOUR_API_KEY = "";
      final String YOUR_USER_ID = "";
      Bridges<String, Student> bridge = new Bridges<String, Student>(4, YOUR_API_KEY, YOUR_USER_ID);

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
       * new DLelement<>(label, genericData)
       */
       //initializing all elements with empty labels, and with the student data. See Object model.Student.java
       DLelement<Student> el0 = null;

       for(int i = 0; i < students.length; i++){
           if(i > 1){
               el0 = insertFront(el0, new DLelement<>("",students[i]));
           }else if(i == 0){
               el0 = new DLelement<>("",students[0]);
               el0.setNext(new DLelement<>("",students[1]));
           }
       }

       DLelement<Student> current = el0;
       while(current != null){
           current.setLabel(current.getValue().getStudentLabel());
           current.getVisualizer().setColor(current.getValue().getFavoriteColor());

           if(current.getNext() != null)current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
           if(current.getPrev() != null)current.getLinkVisualizer(current.getPrev()).setColor(current.getValue().getDislikeColor());

           current = current.getNext();
       }

      bridge.setDataStructure(el0);
      bridge.visualize();


  }


  public static DLelement insertFront(DLelement tail,
                                      DLelement newElement){
      DLelement tailNext = tail.getNext();

      newElement.setNext(tailNext);
      newElement.setPrev(tail);

      tailNext.setPrev(newElement);
      tail.setNext(newElement);
      return tail;
  }

}
