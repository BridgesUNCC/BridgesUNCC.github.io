
#include "Bridges.h"
#include "DLelement.h"
#include "StudentInfo.h"

using namespace bridges;

									// helper function

DLelement&lt;StudentInfo&gt; *insertFront(DLelement&lt;StudentInfo&gt; *front,
				DLelement&lt;StudentInfo&gt; *new_el);
int main() {

	Bridges::initialize(4, "YOUR_USER_ID", "YOUR_API_KEY");

						// load student info
	int num_students = 5;
	StudentInfo students[] = {
				StudentInfo(
                      "00000000000",
                      "Gretel Chaney",
                      "CS",
                      "g.chaney@generated.com",
                      "magenta",
                      "blue",
                      9.0 
				),
				StudentInfo(
                      "00000000001",
                      "Karol Soderman",
                      "SIS",
                      "k.soderman@generated.com",
                      "magenta",
                      "red",
                      11.0
				),
				StudentInfo(
                      "00000000002",
                      "Lamont Kyler",
                      "BIO",
                      "l.kyler@generated.com",
                      "purple",
                      "green",
                      12.0
				),
				StudentInfo(
                      "00000000003",
                      "Gladys Serino",
                      "CS","g.serino@generated.com",
                      "blue",
                      "black",
                      9.0
				),
				StudentInfo("00000000004",
                      "Starr Mcginn",
                      "CS",
                      "s.mcginn@generated.com",
                      "red",
                      "cyan",
                      15.0)
			};

							// insert the students in front of the list
		DLelement&lt;StudentInfo&gt; *head = nullptr;
		for(int i = 0; i < num_students; i++){
			head = insertFront(head, new DLelement&lt;StudentInfo&gt;students[i], ""));
		}
							// add visual attributes 
		DLelement&lt;StudentInfo&gt; *curr = head, *next;
		while(curr != nullptr){
			curr->setLabel(curr->getValue().getStudentLabel());
			curr->getVisualizer()->setColor(curr->getValue().getFavoriteColor());

			DLelement&lt;StudentInfo&gt; n1, n2;
			if (curr->getNext() != nullptr) {
				next = curr->getNext();
				curr->getLinkVisualizer(next)->setColor(curr->getValue().getDislikeColor());
				next->getLinkVisualizer(curr)->setColor(curr->getValue().getDislikeColor());
			}
			curr = curr->getNext();
		}

		Bridges::setDataStructure(head);
		Bridges::visualize();

		return 0;
}

DLelement&lt;StudentInfo&gt; *insertFront(DLelement&lt;StudentInfo&gt; *front,
				DLelement&lt;StudentInfo&gt; *new_el){
	if (front == nullptr)
		return new_el;

	new_el->setNext(front);
	front->setPrev(new_el);
	
	return new_el;
}
