  package provider;

  import model.Student;

  /**
   * Created by Lucas Estrella on 2/2/2017.
   */
  public class StudentProvider {

      /**
       * @param index
       * @return student at index
       */
      public static Student getStudentAt(int index){
          if(index >= students.length){
              throw new NullPointerException();
          }
          return students[index];
      }

      /**
       * @return all students
       */
      public static Student[] getStudents(){
          return students;
      }

      private static Student[] students = {
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
  }
