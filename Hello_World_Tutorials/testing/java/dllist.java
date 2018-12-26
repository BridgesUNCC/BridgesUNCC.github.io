import bridges.base.DLelement;
import bridges.connect.Bridges;

public class dllist {

	public static void main(String[] args) throws Exception {

		Bridges bridges = new Bridges(204, "YOUR_USER_ID", "YOUR_API_KEY");


		// load student info
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
				"purple",
				"green",
				12.0
			),
			new StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS", "g.serino@generated.com",
				"blue",
				"black",
				9.0
			),
			new StudentInfo("00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"cyan",
				15.0)
		};

		// insert the students in front of the list
		DLelement<StudentInfo> head = null;
		for (int i = 0; i < students.length; i++) {
			head = insertFront(head, new DLelement<StudentInfo>("", students[i]));
		}
		// add visual attributes
		DLelement<StudentInfo> curr = head, next;
		while (curr != null) {
			curr.setLabel(curr.getValue().getStudentLabel());
			curr.getVisualizer().setColor(curr.getValue().getFavoriteColor());

			DLelement<StudentInfo> n1, n2;
			if (curr.getNext() != null) {
				next = curr.getNext();
				curr.getLinkVisualizer(next).setColor(curr.getValue().getDislikeColor());
				next.getLinkVisualizer(curr).setColor(curr.getValue().getDislikeColor());
			}

			curr = curr.getNext();
		}

		bridges.setDataStructure(head);
		bridges.visualize();


	}

	public static DLelement<StudentInfo> insertFront(DLelement<StudentInfo> front,
		DLelement<StudentInfo> new_el) {
		if (front == null)
			return new_el;

		new_el.setNext(front);
		front.setPrev(new_el);

		return new_el;
	}
}
