# Web Browser Tab Simulator

### This project was done for an University assignment.
### It's supposed to _simulate_ how tabs work in a web browser. It's not supposed to be a useful tool or anything, more like practice, but I felt like making this README a little bit more fancy.

#### Possible Commands are:

- 1. Adding a website.
- 2. Changing a website's tab position.
- 3. Sorting the tabs based on the input time they were given.
- 4. Show current tabs.
- 5. Free all allocated memory, clear all tabs and exit program.

#### How inputs work:

##### 1. Adding a website:
  - To add a website, first off give the program the command "1". After that, give it the tab's title, URL a date and an hour (please note that the time-stamp is not the american standard but rather the european standard.) 
  
##### 2. Changing its position:
  - To change a tab's position, first give the program the command "2", proceeded by the title of the tab that you want to be changed and finally by the new position you want it to be in, here's some further explanation: 
  - if the position given is equal to or greater than the amount of tabs in the "list", the tab will be placed at the last position
  - if the position given is less than the amount of tabs in the "list", for a given position i, the list is 1-based hence the tab will be positioned before the i-th tab.
  - if there are multiple tabs with the same name, the one that's the leftmost will be changed.
  - if such tab doesn't exist, the program will ignore the command and await for the next one.

##### 3. Sorting:
  - Sorting is simple. Just give the program the command "3" and it will sort it based on the following preference: date comes first (first month then day) and time comes second (hours then minutes). The implemented ordering algorithm was the Radix sort (Bucket sort as the "subroutine").
  
##### 4. Showing what you got :sunglasses: :
  - This one's straight-forward. Simply give the program the command "4" and it will show you the current open tabs in the following format:
    - [title] [url] [dd/mm] [hh:mm]\n
    
      ...
      
      [title] [url] [dd/mm] [hh:mm]\n\n
      
##### 5. Ending it all :weary: :
  - The most basic command. No console feedback. Just type in the command "5" and it will do you the job of closing it all.
  
~~That's all folks. :`)~~
