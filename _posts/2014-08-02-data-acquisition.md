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

Currently, all three sources, Twitter, Movies, and Actors can be reached via one static method: Bridge.getAssociations.
getAssociations takes one parameter, but it has two parts. The first is the name of the provider
and the second is the name of the user or item. The results from getAssociations are of the same format. It seems awkward at first but it is relatively easy to use and will be helpful later.

{% highlight java %}
// Possible identifiers include: "twitter.com/Joey", "actor/Tom Hanks", and "movie/Top Gun"
// 10 is how many followers to retrieve at most
List<String> associations = Bridge.getAssociations("provider name/item name", 10);

// This allows convenient iteration as well:
for (String follower : Bridge.getAssociations("twitter.com/Joey")) {
    System.out.println(follower + "follows Joey");
}
{% endhighlight %}

## Twitter

You can also get a user's followers specifically. You still need to use the same identifiers, and it will return the same identifiers, for consistency. The only difference is a tiny reduction in delay and a different method name.

{% highlight java %}
for (String follower : Bridge.followers("twitter.com/Joey", 15)) {
    System.out.println(follower + "follows Joey");
}
{% endhighlight %}

The most major concern with the Twitter source, which exists whether it is called as "followers" or as "getAssociations", is the very small quota. You only get 15 queries every 15 minutes. The results are cached, so that repeated queries for the same users' followers do not count against your quota. This way, you will be able to get an ever-expandin graph.

## Actors and Movies

Actors' filmographies and Movies' casts go hand in hand. You can use them interchangably with getAssociations, which may be helpful in generating and using graphs based on them.

{% highlight java %}
List<String> cast = Bridge.actors("movie/Top Gun", 15);
List<String> filmography = Bridge.movies("movie/Tom Hanks", 3);
{% endhighlight %}
