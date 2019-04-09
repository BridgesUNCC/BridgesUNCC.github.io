SLelement<E> is the basic element used to implement a _singly linked list_ in BRIDGES and is inherited from Element<E>

    ![](./images/slelement-cd.png)


    ## How does the SLelement<E> work?

    SLelement<E> stands for Singly Linked Element and is a type of container that has one link, pointing to another SLelement<E>. So an SLelement<E> "knows" who it is pointing at but it does not know who is pointing at it(if any).

    ![](./SLelement.png)

    In the above example, SLelement1 points to SLelement2. Calling getNext() on SLelement1 will return a link to SLelement2, and calling getNext() on SLelement2 will return a link to SLelement3. SLelement3 is not pointing to another SLelement so calling getNext() on SLelement3 will return NULL. This is desirable since you will know that you have reached the end of the singly linked list (as NULL is a unique value and not a legal memory address for an object).

    Also notice that there is no getPrev(). SLelement2 has no idea what element came before it. So, you CANNOT go backwards.

    - - -

    ## SLelement - An Example BRIDGES program

    [](./Java_SLL.html)[](./Cpp_SLL.html)[

    ### Bridges Visualization

    -   Once all your code is in order, run your file.
    -   Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
    -   Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
    -   It should look something like this:

    <p>Sorry, your browser doesn't seem to support iframes - <a href="/assignments/103/bridges_public" scrolling="no">Frame Link</a> </p>

    Well done! You’ve just created your Bridges Singly Linked List project!

    ](./Python_SLL.html)