## Example Details

-   In this example, we will build and visualize a circular singly linked list with student information data, specified through the StudentInfo class, which will be part of the CircSLelement object, through its generic variable (CircSLelement<StudentInfo>).
-   The elements are linked, colored and the list is visualized.
-   The main difference from the normal singly linked list is that the last element is linked to the first element; iterating through a circular linked list will need to compare the link (that is iterated upon) to the beginning link of the list, in order to prevent an infinite loop.

### Here's the final code:

[](./testing/java/csllist.java.html)[](./testing/java/StudentInfo.java.html)