---
examples:
    - text: "A singly linked list using a reduced version of the IMDB actor/movie dataset."
      image: /img/list.png
      url: http://bridges-cs.herokuapp.com/assignments/1000/bridges_public
    - text: "Bacon Number and Path Computation using the IMDB actor/movie dataset. Example illustrates the path   between Kevin Bacon and Denzel Washington"
      image: /img/graph2.png
      url: http://bridges-cs.herokuapp.com/assignments/1002/bridges_public
    - text: "A binary search tree built using earthquake magnitudes; data from the USGIS earthquake feed  (periodically retrieved and stored on server, so as to always access the most recent quakes)."
      image: /img/tree.png
      url: http://bridges-cs.herokuapp.com/assignments/1001/bridges_public
    - text: "Graph of earthquake data, clustered by magnitude and colorcoded by quake magnitude."
      image: /img/graph-eq-magn.png
      url: http://bridges-cs.herokuapp.com/assignments/19/bridges_public
    - text: "Graph of IMDB actor/movie data, clustered by genre and colorcoded by movie ratings."
      image: /img/graph-imdb-genre.png
      url: http://bridges-cs.herokuapp.com/assignments/1004/bridges_public
    - text: "2D grid structure example that can form the basis for a variety of image processing operations."
      image: /img/color_fill.png
      url: http://bridges-clone.herokuapp.com/assignments/1003/bridges_public
---

<div class="row">
<div class="col-lg-7" markdown="1">

## About BRIDGES

BRIDGES(Bridging Real-world Infrastructure Designed to Goal-align, Engage, and Stimulate), an NSF TUES project, is focused on two primary goals:

1. Providing easy-to-use interfaces to exciting, engaging real-world data (social networks, scientific data, etc), to make it possible for their use in freshmen/sophomore level CS courses, and
2. make it easier to visualize the data structures that students create as part of their assignments in algorithms and data structures courses.

BRIDGES is carefully designed to augment the student experience in routine introductory courses in Computer Science.

The BRIDGES toolkit provides a set of classes (C++, Java, and Python are supported) that serve as building blocks to the common CS data structures, including lists (arrays, linked lists), tree structures (general trees, binary trees, binary search trees, AVL trees), graphs (adjacency list and adjacency matrix representations) used in freshmen/sophomore level computer science. BRIDGES handles the complex data and web interfaces, thereby letting students focus on the core course materials, while providing a more engaging means to view their output on the web (that can be shared)

## BRIDGES Status

Current version of BRIDGES is 2.3.3 (Released June 1, 2018).  

Version 2.3.3 includes additional datasets interfaced to BRIDGES (a dataset and BRIDGES API for Songs), a 2D Grid type that can be used for image related applications, numerous bug fixes and improvements to the base classes.

See [docs](http://bridgesuncc.github.io/bridges_doclinks.html) on latest changes to BRIDGES and its history of earlier changes. for more information.

## Looking for New BRIDGES Users

We are currently looking for 3-4 additional external users to adopt BRIDGES in their data structures/algorithms courses and provide feedback. Stipends are available for instructors who would like to partner with our team and collect student feedback as part of the BRIDGES evaluation.

## BRIDGES News

We have just released BRIDGES version 2.4.1 (Jan, 2019, in C++, Java and Python), which (in addition to numerous fixes/enhancements) adds a ColorGrid data type (see example visualization on the right), support for Spatial data Structures (Kd Tree), a shape collection structure, and a Song Lyrics dataset. In the works are extensions to using BRIDGES to build simple games (demo at SIGCSE 2019).

### BRIDGES Workshop - Feb. 27, 2019, SIGCSE 2019, Minneapolis, MN.

We will be conducting a BRIDGES workshop at ACM SIGCSE 2019, on Wednesday Feb. 27, 7-10pm (Hyatt Greenway E (2nd Floor). Please see [this link](https://whova.com/embedded/subsession/sigcs_201902/486899/497255/) for more information.

### BRIDGES Workshop - June 6, 2018, Temple University, Philadelphia

We plan to conduct a 1 day BRIDGES workshop on June 6, 2018, at Temple University. We encourage instructors to take advantage of this workshop if you are interested in using BRIDGES in your Data Structures/Algorithms courses. Limited travel support is available (can cover regional attendees).

For more information see the following links for the [workshop flyer](/workshops/2018/philadelphia/flyer.pdf) and [signup information](https://goo.gl/forms/s0cYQAYrhctVRzff1)

Contacts: [Kalpathi Subramanian,](mailto:krs@uncc.edu?subject=Bridges%20Workshop) [Jamie Payton,](mailto:payton@temple.edu?subject=Bridges%20Workshop) [Erik Saule](mailto:esaule@uncc.edu?subject=Bridges%20Workshop)

### Acknowledgements

The BRIDGES project is funded by a TUES/IUSE grant from the [National Science Foundation](www.nsf.gov).

</div>


<div class="col-lg-5">
<h2>Examples</h2>
{% for example in page.examples %}
<div class="card mb-4">
  <a href="{{example.url}}"><img class="card-img-top" src="{{example.image}}"></a>
  <div class="card-body">
    <p class="card-text">{{example.text}}</p>
    <a href="{{example.url}}" class="btn btn-primary">View</a>
  </div>
</div>
{% endfor %}

</div>
</div>