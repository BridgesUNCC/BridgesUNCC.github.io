---
layout: post
title: Data Acquisition
categories: [data]
---

# Overview

Since data structures filled with random or consecutive integers can be boring
and in some cases insufficiently general, Bridges gives you access to a few data
sources you might find thought provoking. Currently, you can choose from:

* Twitter followers
* Actors' filmography
* Movies' cast

Many others are planned as well.

* Latest Earthquakes [from USGS](http://earthquake.usgs.gov/earthquakes/feed/v1.0/)
* Current Weather [from Wunderground](http://www.wunderground.com/weather/api/)
* Wildlife Strike Database [from the FAA](http://wildlife.faa.gov/)
* General Transit Feed Specification [from Google](https://developers.google.com/transit/gtfs/reference)
* Airline On-Time Statistics [from the Bureau of Transportation Statistics](http://www.transtats.bts.gov/ot_delay/ot_delaycause1.asp)


# Reference

## Twitter

You can retrieve the followers of a Twitter user via a simple static method and the Follower type. You have a choice between the Twitter-specific alias "followers" and an overloaded method "getAssociations". In either case, you provide two arguments, the Twitter user whose followers you want to know, and the maximum number of Followers to retrieve (up to 200).

{% highlight java %}
Follower root = new Follower("Joey");
for (Follower follower : Bridge.followers(root, 15)) {
    System.out.println(follower + " follows " + root);
}
{% endhighlight %}

The most major concern with the Twitter source, which exists whether it is called as "followers" or as "getAssociations", is the very small quota. You only get 15 queries every 15 minutes. The results are cached, so that repeated queries for the same users' followers do not count against your quota. This way, you will be able to get an ever-expanding graph.

## Actors and Movies

Actors' filmographies and Movies' casts go hand in hand. You can query each, perhaps to find the degrees of Kevin Bacon or something similar. Note that Actors and Movies are distinct types even though the queries are similar, so as to prevent confusion.

{% highlight java %}
List<Actor> cast = Bridge.actors(new Movie("Top Gun"), 15);
List<Movie> filmography = Bridge.movies(new Actor("Tom Hanks"), 3);
{% endhighlight %}
