# Quick Links
[Project 3 Reflection](#project-3---reflection)

[CS230 Project Software Design Template Reflection](#cs230-project-software-design-template---reflection)
# Project 3 - Reflection
------------------------
## Summarize the project and what problem it was solving:
  The purpose of this project was to create a piece of software integrating both C++ and Python that analyzes a text document containing a record of each item sold by an imaginary corner grocher for a single day. 
  The functional requirments of the program were to 
     1: Produce a list of all items purchased in a given day along with the number of times each item was purchased
     2: Produce a number respresenting how many times a specific item was purchased in a given day.
     3: Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.
     
## What did you do particularly well?
  I believe that I handled the creation of functions in python to analyze the text document particularly well. I beleive that my code was efficiant, and succinct and made sure 
  to separate reusable code into an internal function to be called by the functions that are utilized in the C++ file.
  
## Where could you enhance your code? How could these improvements make your code more efficient, secure, and so on?
  I think that I could enhance my code by providing more extensive data validation and making it more portable. The code relies on the input text file being correctly formatted
  with each item being on an individual line. If the user were to supply a text file that did not meet these requirments the program would fail to execute properly.
  The functions I created are also not portable without some tweaking as the file names are hard-coded into the program. A better approach if I was going to turn this into
  a deployable product for a client would be to have the program accept a file path to the text file the user would like to supply and pass that as an argument to the function 
  that reads from the file.
  
## What pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  There wasn't any one particular piece of the code that I found challenging to write on it's own, however there was some python syntax and functions that I did not remember
  how to properly use so I had to use some internet searching to remind myself how to properly code what I had intended to. One resource I am adding to my support network due
  to this is Python's programming documentaion located at https://docs.python.org/3/. 
  

## What skills from this project will be particularly transferable to other projects or course work?
  I beleive that the skill of integrating multiple programming languages together in one piece of software will be transferable to other projects and course work in my future. 
  Being able to use the right programming language for the specific aspect of the problem I am tackling is sure to be of great use to me throughout my career as a computer
  scientst.
  
## How did you make this program maintainable, readable, and adaptable? 
  I made this program maintainable by making sure that my code was well documented by comments explaining my code and the reasoning for its inclusion.
  The program is readable due to the use of white spacing to separate blocks of logic and by having function, variable, and argument names that are recognizable and
  understanable in the context of the program. The code has areas were it's adaptablility could improve, however it remains adatable in it's current state due to the seperation
  of processes into distinct functions that can be reused in other programs. 

-----------------------------------------------------

# CS230 Project Software Design Template - Reflection
-----------------------------------------------------
## Briefly summarize The Gaming Room client and their software requirements. Who was the client? What type of software did they want you to design?
The Gaming Room is an established development team with an exisiting Android app titled Draw it or Lose it who tasked us with developing a web-based version of thier existing application in order to reach a wider audience.

They requested the following software requirments:
- A game will have the ability to have one or more teams involved.
- Each team will have multiple players assigned to it.
- Game and team names must be unique to allow users to check whether a name is in use when choosing a team name.
- Only one instance of the game can exist in memory at any given time. This can be accomplished by creating unique identifiers for each instance of a game, team, or player.

## What did you do particularly well in developing this documentation?
I believe that I excelled at describing the design constraints and domain model for the project.

## What about the process of working through a design document did you find helpful when developing the code?
I found that working through the design document helped me gain a better understanding of the project and the enviornment in which it would be hosted which in turn helped me organize my code and make it best suited for it's enviornment. 

## If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?
If I was to revise a part of this doucment I would choose to revise the reccomendations section as I feel like it was a little too breif and did not fully discuss the reasons for my reccomendations. I would improve it by doing better research into the different platforms available in order to have a deeper understanding of them and better describe the advantages that my reccomendations offered. 

## How did you interpret the user’s needs and implement them into your software design? Why is it so important to consider the user’s needs when designing?
In order to interpret the user's needs and implemnt them into my software design I examined the functionality of the currently exisiting Android app and ensured that I modularized them and implemented them into the project so that it's functionality would remain the same. It's important to consider the user's needs when designing so that you do not end up needing to redesign your application if you end up not meeting the users needs.

## How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?
I approached desinging the software by researching the different design patterns that exist and comparing them to the softwazre requriements in order to best choose how the different parts of the application would be designed and fit together. In the future I would do more research into the different design patterns and look at working examples of them in order to get a better understanding of how they fit into a project to help me design a similar software application. 
