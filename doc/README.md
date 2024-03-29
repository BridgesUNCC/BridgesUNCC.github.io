Documentation
=============

The documentations of bridges client apis are not written manually.
The documentations are extracted automatically from the code of the
clients apis using doxygen and doxypy.

There is a script called ./make_doc.sh that takes 3 parameters, the local path to the git repositories of the three clienst. For instance, I run:

```
./make_doc.sh ~/work/bridges/bridges-cxx/ ~/work/bridges/bridges-java/ ~/work/bridges/bridges-python/
```

Note that there are protections in place to prevent running things passing the wrong repository.

The documentation is generated automatically with a version number
extracted from the git repositories. This is done by git-describe that
generate a string with a proper version number from tags such as
"3.1.1" if there is a tag on the most recent commit or
"3.1.0-22-gceb9977" if the most recent commit is not tagged. This
actually help us making sure we have a good mapping of documentation
to precise version of the codes rather than version numbering that
could be inconsistent.

The script does not change the content of the git index. That is to
say that you still need to git add the directories that have
changed. The "current" documentation pointers also do not get updates
automatically. These two "inconvenience" are on purpose to make sure
we do not publish/update documentations if we are just testing things.

Also, the ``make_doc.sh`` script updates the list of old
documentations. That list is generated by looking at the content of
the git repository. That means that add documentations after running
``make_doc.sh``, they won't appear in the list of past
documentation. This probably is not a problem since they will be added
the next time the documentation is generated (so when they become
old). But if for some reason it is necessary to recreate the list of
old documentation, one can run:

```
./generate_old_doc.sh > old_docs.html
```

