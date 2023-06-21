# Inventory

## WHAT PROGRAM DOES
This program would be used in a grocery store in order to update the stores stock after a customer checks out. If stock for an item runs out, it is added to a seperate list and removed from the stock. 

## HOW TO COMPILE
This program is compiled with CMake.
To do this, create a build folder in the project directory using "mkdir build" in the console then "cd build" then "cmake .." then "make". To run the program type "./myprogram".(do not include quotations for any of these)

## HOW TO USE
The user input for this program would be entered automatically when an items barcode is scanned meaning that user input should not be an issue(reason for not adding check to see if user input is formatted correctly). However, in this case, you will need to add items manually, so it needs to be formatted correctly. This is done by making a list of items with all lowercase letters that are seperated by only a comma(no spaces). The item must also be spelled the same way as in the Stock.txt file.
ex. apple, orange, banana, gum, etc.

When the same item is in the customer's cart more than once this will be reflected by adding the item however many times into the list.
ex. 4 apples and 1 coke could be: apple, coke, apple, apple, apple

If the customer buys the rest of an item, it will be added to a "toOrderList" text file. It is also important to note that there can never be more of an item in the input than in the Stock file(no negative stock).

Items in the stock text file are formatted by having the item first then the quantity(seperated by a comma and space). Each item gets its own line. Items can only be one word.
ex.
 - apple, 5
 - orange, 23
 - banana, 7

For testing, make sure to clear the toOrderList whenever the Stock file is edited. I have added items to the Stock file, but you can change them to test for different scenarios.
