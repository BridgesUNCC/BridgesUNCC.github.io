/**
 * 	Array implementation of List ADT
 */
public class AList<E> implements List<E> {
	
	  private static final int defaultSize = 10; 

	  private int maxSize;
	  private int listSize;
	  private int curr;
	  private E[] listArray;

	  /** Default Constructor */
	  AList() { 
		  this(defaultSize); 
	  }

	  /** Constructor with size parameter */ 
	  AList(int size) { 
	    maxSize = size;
	    listSize = curr = 0;
	    listArray = (E[])new Object[size];
	  }
	  
	  /** Clear the list */
	  public void clear() { 
		  listSize = curr = 0; 
	  }
	  
	  /** Move Pointer */
	  public void moveToStart() { curr = 0; }
	  public void moveToEnd() { curr = listSize-1; }
	  public void prev() { if (curr != 0) curr--; }
	  public void next() { if (curr < listSize) curr++; }
	  
	  /** Current List Length */
	  public int length() { return listSize; }
	  
	  /** Get current position */
	  public int currPos() { return curr; }
	  
	  /** Set current position */
	  public void moveToPos(int pos) {
		  if ((pos < 0) || (pos >= listSize)) {
			  System.out.println("Position out of range");
		      return;
		  }
		  curr = pos;
	  }

	  /** Get item at current position */
	  public E getValue() { 
		 if ((curr < 0) || (curr >= listSize)) {
			 System.out.println("No current element");
			 return null;
		 }
		 return listArray[curr];
	  }
	  
	  /** Insert item at current position */
	  public void insert(E it) {
	    if(listSize >= maxSize) {
	    	System.out.println("List capacity exceeded");
	    	return;
	    }
	    
	    for (int i=listSize; i>curr; i--)
	      listArray[i] = listArray[i-1];
	    listArray[curr] = it;
	    listSize++;
	  }
	  
	  /** Append item to end of list */
	  public void append(E it) { 
		  if(listSize >= maxSize) {
			  System.out.println("List capacity exceeded");
			  return;
		  }
		  listArray[listSize++] = it;
	  }
	  
	  /** Remove and return the current element */
	  public E remove() {
	    if ((curr < 0) || (curr >= listSize)) 
	      return null;
	    E it = listArray[curr];
	    for(int i=curr; i<listSize-1; i++)
	      listArray[i] = listArray[i+1];
	    listSize--;
	    return it;
	  }

}

	  
	  



