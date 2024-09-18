
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Reddit.h"

using namespace bridges;

// This program fragment illustrates how to access and read the Reddit Post data 
int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// create data source object
	DataSource ds (&bridges);

	vector<Reddit> reddit_list = ds.getRedditData("askscience");
	std::cout<<""<<reddit_list.size()<<" post returned"<<"\n";
	std::cout<<"Printing at most 10\n";
	int count = 0;
	for (auto post : reddit_list) {
	  ++count;
	  if (count >10)
	    break;
	  std::cout<<"ID: "<<post.getID()<<"\n";
	  std::cout<<"Title: "<<post.getTitle()<<"\n";
	  std::cout<<"Author: "<<post.getAuthor()<<"\n";
	  std::cout<<"Score: "<<post.getScore()<<"\n";
	  std::cout<<"VoteRatio: "<<post.getVoteRatio()<<"\n";
	  std::cout<<"CommentCount: "<<post.getCommentCount()<<"\n";
	  std::cout<<"Subreddit: "<<post.getSubreddit()<<"\n";
	  std::cout<<"PostTime: "<<post.getPostTime()<<"\n";
	  std::cout<<"URL: "<<post.getURL()<<"\n";
	  std::cout<<"Text: "<<post.getText()<<"\n";
	  std::cout<<"\n";
	}
	
	
	return 0;
}

