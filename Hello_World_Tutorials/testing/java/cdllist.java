import bridges.base.CircDLelement;
import bridges.connect.Bridges;

public class cdllist {

	public static void main(String[] args) throws Exception{

//		Bridges bridges = new Bridges(6, "486749122386", "kalpathi60");
		Bridges bridges = new Bridges(6, "997924677918", "bridges_public");

		StudentInfo[] students = {
			new StudentInfo(
					"00000000000",
					"Gretel Chaney",
					"CS",
					"g.chaney@generated.com",
					"magenta",
					"blue",
					9.0
			),
			new StudentInfo(
					"00000000001",
					"Karol Soderman",
					"SIS",
					"k.soderman@generated.com",
					"magenta",
					"red",
					11.0
			),
			new StudentInfo(
					"00000000002",
					"Lamont Kyler",
					"BIO",
					"l.kyler@generated.com",
					"yellow",
					"green",
					12.0
			),
			new StudentInfo(
					"00000000003",
					"Gladys Serino",
					"CS","g.serino@generated.com",
					"blue",
					"magenta",
					9.0
			),
			new StudentInfo("00000000004",
					"Starr Mcginn",
					"CS",
					"s.mcginn@generated.com",
					"red",
					"yellow",
					15.0)
			};

      					//initializing all student elements 
		CircDLelement<StudentInfo> head = null;

		for(int i = 0; i < students.length; i++) {
			if (i > 0)
				head = insertFront(head, new CircDLelement<StudentInfo>("",students[i]));
			else
				head = new CircDLelement<StudentInfo>("",students[i]);
      	}

      	CircDLelement<StudentInfo> current = head;
						// add visual attributes
		do {
			current.setLabel(current.getValue().getStudentLabel());
			current.getVisualizer().setColor(current.getValue().getFavoriteColor());
		
			current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours()*.75);

			current.getLinkVisualizer(current.getPrev()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getPrev()).setThickness(current.getValue().getStudentCreditHours()*.75);

			current = current.getNext();
		}	while (current != head);

		bridges.setDataStructure(head);

		bridges.visualize();
	}

	public static CircDLelement<StudentInfo> insertFront(
				CircDLelement<StudentInfo> tailElement,
				CircDLelement<StudentInfo> newElement) {
		CircDLelement<StudentInfo> tailNextElement = tailElement.getNext();

		newElement.setNext(tailNextElement);
		newElement.setPrev(tailElement);

		tailNextElement.setPrev(newElement);
		tailElement.setNext(newElement);

		return tailElement;
	}
}
