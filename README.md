# Farm tool

---

## Paper

### Objective
Create a tool for a farmer who needs to manage his farm and animals. The tool contains a list of animals in the farm. The farmer must be able to:<br>
1) Add an animal
2) Remove an animal
3) Search an animal
4) Modify an animal entry
5) List all entries

### Analysis
In order to list the animals in the farm we need an array with a variable lenght. C99 doesn't have such datatypes so we created them manually using `malloc()` and `realloc()`.<br>
Every time we add/remove an item to the list the array has to resize to the desired lenght (C will find a new suitable location in ram for the array [expand] or will reduce the amount of memory used [shrink]).

#### 0) "Quit" function
If the user sends a 0 when prompted for an input the program will quit.

#### 1) "Add" function
The program will ask for a code to be assigned to the animal. The code must be unique, to enforce that the program will scan the entire (loaded) array in search for a duplicate.<br>
If a duplicate is found the program will ask for a new code. If the code wasn't in use the program will continue and prompt the user for:
  1) Weight and animal type
  2) Date of birth
  3) Date when "the animal will be sold"

#### 2) "Remove" function
The program will ask for a query code. If the code is found the function returns the index and the program will then shift the array starting from the index up to the last element to the left effectively removing the query from the list. The program will then shrink the list to the new suitable size.

#### 3) "Search" function
After asking the user for a query code, if found inside the list the program will print the fields of the animal.

#### 4) "Replace" function
After asking the user for a query code, if found the program will let the user input the data for an animal again.

#### 5) "List" function
The program will print all the entries of the list.

### Tricks used
<strong>Animal races:</strong> instead of using `if` or `switch` statements or directly saving the race of the animal as a string we can have a constant array of strings containing all the possible races and save inside the animal the index of the string in the array. To print the name when can call the print function providing a string (`const c_string`) contained in the array with index [type].<br><br>
<strong>Resizing the array:</strong> to create a variable array we can resize them using `realloc` specifying a bigger or smaller size (`sizeof Type * amount`). `realloc` will expand the array or find a suitable location for a new one and carry over the already existing data.<br><br>
<strong>Empty array:</strong> if the array pointer is null it means there is no data and no allocated memory. When first resizing the array we need to call `malloc` to create an initial memory allocation.<br><br>
