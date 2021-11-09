# cs3113fa21-project1

Nima Shadaram

How I ran the project:

1.Use the command make all and type that into into the command line of the terminal. THe point of this is to compile to program to get it ready to be run
2. In order to run the program, I would then use the name of the file that was to be executed, in this case project1, and then follow it with a seperation and the name of my text file which was input.txt
3. I created a condition where if no file was read in from the terminal, it would then read in from stdin  so conditions could still be passed
4. Lastly, I would use the command make clean in order to remove any executable files that were created from running the process.


Bugs that I expected:
Some of the bugs that I expected was about figuring out how to get the proper location of the integers I needed in the array.
Another expected bug that I encountered was having the correct math behind each time. On some of the times I failed to understand the mathematics behind them and even how to calculate them. Some of these issues that I expected I definitely ran across during my program. One of the main ones I ran into however was getting the proper inputs for the array and being able to store the burst integers into their own array. This gave me problems because it determined the rest of the calculations. Problem reading the file in correctly, My nonvoluntary context switches were sometimes off. A big problem I never realized was that a lot of my variables were garbage values because they were never initialized to 0

People that helped me understand the timings:
Jonathan Leslie
Anthony Immensuch

Function descriptions:
In our main function, we use a file reader to determine if the variables will be read in from an open file or from stdin. After doing so I created two structs to store the variables in and ininitialized them to avoid garbage values. I then stored these variables in my arraystore array and used that to calculate the different neccesary positions of them. After assigning the base values, I declared them into their positions and called my next big function to do the calculations in.

In my getinfotimes method I used a variety of while loops and process counters to declare what positions would be added and where increments would be increased. I also inside of this loop figured out where my variables for like response time would be added in. This allowing all my calculations to be done in one simple space instead of spreading them all out. I then divided them by the numPIDs for each average that needed to be calculated to get the average times.

Lastly I had a method that calculated the amount of context switches using a for loop and the processIDs.


Sources that helped me with understanding:
https://www.guru99.com/fcfs-scheduling.html
https://www.8bitavenue.com/throughput-vs-turnaround-time-vs-waiting-time-vs-response-time/
https://www.studytonight.com/operating-system/first-come-first-serve
