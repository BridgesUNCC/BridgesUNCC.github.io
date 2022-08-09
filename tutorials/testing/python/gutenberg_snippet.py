from bridges.bridges import *
from bridges.data_src_dependent import data_source
import sys


def main():
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # Retrieve the book metadata given its id (2701 is MOby Dick)
    meta = data_source.get_a_gutenberg_book_metadata (2701)
    print(f"Id: {meta.id}")
    print(f"Title: {meta.title}")
    print(f"Date: {meta.date}")
    print(f"Author: {meta.authors}")
    print(f"Genres: {meta.genres}")
    print(f"language: {meta.lang}")
    print(f"library of congress: {meta.loc}")


    # you can search the gutenberg database by supplying a search parameters,
    #   a term and a category type (title, date, genre, language, author)

    print("\nGet book by title: Pride and Prejudice\n")
    meta_data = data_source.get_gutenberg_book_metadata("Pride and Prejudice", "title")
    for i in range(len(meta_data)):
        print(meta_data[i].title) #this is the title of book
        print(meta_data[i].id) #this is the id of book
        print(meta_data[i].date) #this is the date
        if i == 2: 
           break

    #  search for books in a particular language

    print("\nGet book by language: English\n")
    meta_data = data_source.get_gutenberg_book_metadata("en", "language")
    for i in range(len(meta_data)):
        print(meta_data[i].title) #this is the title of book
        print(meta_data[i].id) #this is the id of book
        print(meta_data[i].date) #this is the date
        if i == 2: 
           break

    #If you already have the ID of a book you want, you can do two retrievals
    #This is a text retieval given the ID of a book
    #Print the characters between 100-200 of the book text given its ID

    print("\nGet text of Moby Dick (id: 2701)\n")
    text = data_source.gutenberg_book_text(2701)

    print("\nPrinting the first 300  characters..")
    print(text[0:300])




if __name__ == "__main__":
    main()
