---
layout: post
title: Datasets
redirect_from: /datasets.html
---

Most BRIDGES datasets are held in a Mongo database with BRIDGES API calls to access them, including on-demand streaming data; some of the older datasets that were held in files are included below in their original form. Currently ongoing effort to access [Corgis Datasets](http://think.cs.vt.edu/corgis/), via BRIDGES.

 - A small curated IMDB Actor/Movie Dataset(accessed via the BRIDGES API)
   - [Example Command to retrieve IMDB actor/movie data (1800+ pairs)](https://bridgesdata.herokuapp.com/api/imdb)
   - [Curated IMDB (Actor/Movie) \[Data File\]](/project_data/datasets/large_imdb.txt)
 - USGS Earthquake Twitter Feed Data (Accessed in a sane manner as a list of objects via the BRIDGES API)
   - [Example command to retrieve 100 most recent earthquake Tweets](http://earthquakes-uncc.herokuapp.com/eq/latest/100)
 - Video Game Review Data (extracted via BRIDGES API)
   - [Example query to retrieve Video Game Review Data](http://bridgesdata.herokuapp.com/api/games)
 - Shakespeare Books, Plays, Poems (Metadata only) (Accessed in a sane manner as a list of objects via the BRIDGES API)
   - [Example query to retrieve Video Game Review Data](http://bridgesdata.herokuapp.com/api/shakespeare/)
 - Books (Accessed in a sane manner as a list of objects via the BRIDGES API)
   - [Example query to retrieve Book Data](http://bridgesdata.herokuapp.com/api/books/)