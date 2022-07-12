from bridges.bridges import *
from bridges.color import *
from bridges.data_src_dependent import data_source
import sys
import os

def main():

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    reddit_obj = data_source.reddit_data("askscience")
    
    for reddit_post in reddit_obj:
        print(f"Title: {reddit_post.title}")
        print(f"Author: {reddit_post.author}")
        print(f"Score: {reddit_post.score}")
        print(f"Vote Ratio: {reddit_post.vote_ratio}")
        print(f"Comment Count: {reddit_post.comment_count}")
        print(f"Subreddit: {reddit_post.subreddit}")
        print(f"PostTime: {reddit_post.post_time}")
        print(f"URL: {reddit_post.url}")
        print(f"Text: {reddit_post.text}")
        print("")


if __name__ == "__main__":
    main()
