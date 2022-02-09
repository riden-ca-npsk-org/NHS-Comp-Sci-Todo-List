# To-Do List  
Write a To-Do List program.  This program should have a command-line interface where the user can
- View current items on the List
- Add an item to the list 
- Mark an item as complete 
- Remove an item from the list 

## Suggested approach
There are two big ideas to this project.  

1. User interface: menus and user input
2. Maintaing a vector (or two)

Start by creating the menu and getting user input.  Then add the functionality once the prompt / input is working. 

Each item on the list should be stored in a vector.  You can maintain two vectors simultaneously to keep track of whether each task is complete or not.  

Here is one possible menu you could include in your interface:
```bash
     --- Welcome to To-Do List --- 
       Enter your choice: 
          1. Print To-Do list 
          2. Add item to list 
          3. Update item status 
          4. Remove item from list 
          5. Quit 
```

