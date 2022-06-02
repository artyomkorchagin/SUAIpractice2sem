SUAI professional coding practice 5131 Korchagin Artyom 2022 |
-------------------------------------------------------------+

This program is designed to analyze and sort the desired cyrillic text from txt file in alphabetical order using the Comb Sorting Method.
Make sure that your txt file is in ANSI enoding and it is placed within the ConsoleApplication1/ConsoleApplication1 directory (my own testing files can be found there)
You may use file's path as well.

This one was a bit of a challenge since its pretty hard to operate strings in C++, but after doing a little bit of diggin'
I've found python-alike libraries (list, sstream) that made this whole process a lot easier.

Source.cpp consists of the 3 main functions that you really should look into.

The first one is string* SeparateWords(string text), which basically reads a string from the txt,
splits it into words and returns them into a dynamic array.
I've used a list variable because the program does not know how many words there are going to be,
And thats where the list comes in handy. Using ".push_back()" i was able to fill up the list without unnecessary cycles -> no memory loss
Also, i was able to store the amount of formed words using ".size()"

The second one I'd say is basic, nothing really interesting, just a comb sorting method
One thing I should point out is that it is required to 
