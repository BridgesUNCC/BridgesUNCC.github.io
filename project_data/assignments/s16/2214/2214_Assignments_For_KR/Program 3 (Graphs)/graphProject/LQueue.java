package graphProject;

/** Source code example for "A Practical Introduction to Data
    Structures and Algorithm Analysis, 3rd Edition (Java)" 
    by Clifford A. Shaffer
    Copyright 2008-2011 by Clifford A. Shaffer
*/

// Linked queue implementation
class LQueue<E> implements Queue<E> {
  private Link<E> front;    // Pointer to front queue node
  private Link<E> rear;     // Pointer to rear queuenode
  int size;		    // Number of elements in queue

  // Constructors
  public LQueue() { init(); }
  public LQueue(int size) { init(); } // Ignore size

  private void init() {              // Initialize queue
    front = rear = new Link<E>(null);
    size = 0;
  }

  public void clear() { init(); }   // Reinitialize queue
  
  public void enqueue(E it) {  // Put element on rear
    rear.setNext(new Link<E>(it, null));
    rear = rear.next();
    size++;
  }

  public E dequeue() {         // remove element from front
    assert size != 0 : "Queue is empty";
    E it = front.next().element();  // Store dequeued value
    front.setNext(front.next().next());  // Advance front
    if (front.next() == null) rear = front; // Last Object
    size--;
    return it;                      // Return Object
  }

  public E frontValue() {       // Get front element
    assert size != 0 : "Queue is empty";
    return front.next().element();
  }

  public int length() { return size; } // Return length

// Extra stuff not printed in the book.

  /**
   * Generate a human-readable representation of this queue's contents
   * that looks something like this: < 1 2 3 >.
   * This method uses toString() on the individual elements.
   * @return The string representation of this queue
   */
  public String toString()
  {
    StringBuffer out = new StringBuffer((length() + 1) * 4);
    out.append("< ");
    for (Link<E> i = front.next(); i != null; i = i.next()) {
      out.append(i.element());
      out.append(" ");
    }
    out.append(">");
    return out.toString();
  }
}
