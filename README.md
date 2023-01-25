# COP3502-C
<p> Computer Science 1 | Fall 2021 </br>
Problem solving techniques, order analysis and notation, abstract data types, and recursion. </p>

------

### Project 1 | Dynamic Memory Allocation
<p>
Problem Description: Making Smoothies <br> A smoothie is a blended drink concoction, with several ingredients. Each different type of smoothie has a different ratio of its ingredients. This program will read in information about several smoothie recipes and several stores expected sales for the week, and determine what raw ingredients (and how much of each) each store should order.
<br>
Given  a  list  of  possible  smoothie  ingredients,  a  list  of  smoothie  recipes,  and lists of  sales  from  several  stores, determine how much of each ingredient each store must order. 
</p>

<br>

### Project 2 | Recursion
<p>
Problem Description: Tree House <br> There are several trees (an even number) with treehouses in your backyard and you have pitched the bright idea to your parents that it would be fun to connect pairs of tree tops with a rope ladder, so that friends in one tree house could get to friends in another tree house without going back to the ground. 

<br>
Assume that the length of a rope ladder built between treetops located at (xi, yi) and (xj, yj) is  

$\sqrt{(x_{i}-x_{j})^{2} + (y_{i}-y_{i})^{2}}$
 
<br>
Given the (x, y) positions of 2n treehouse, of all possible ways to create n pairs of distinct trees, find the minimum 
possible sum of distances between each tree in the pairs.  
</p>

<br>

### Project 3 | Queue & Linked Lists
<p>
Problem Description: Monster Kingdom <br> A Monster Kingdom has trapped G (G ≤ 10) groups of criminal monsters. They want to execute them. They found out a strategy so that the criminal monsters will kill each other and at the end one  monster  will  be  alive  and  he  will  be  released.  The  kingdom  has  10  execution  grounds  one after  another.  Each  ground  has  a  ground  number.  The  grounds  are  numbered  with  a  sequence  number  starting  from  1  to  10.  As  part  of  the  strategy,  each  group  is  placed  to  an  execution  ground. The groups are numbered based on the assigned execution ground number. 

<br>

In  Phase 1,  the  execution  happens  within  the  group  and  this  phase  of  execution  for  a  group  g<sub>i</sub> stops when the total number of monsters for the group reduced to a threshold thi (th<sub>i</sub> < n<sub>i</sub>). 
<br>

In phase 2, the execution will happen across the groups with the following strategy: 
The  highest  monster  sequence  number  across  all  the  fronts  of  the  groups  will  be  executed. If the same highest monster sequence number is standing in the fronts of multiple groups, the  monster  standing  on  the  smallest  execution  ground  number (same as  group number) will be executed first to break the tie. 
</p>

<br>

### Project 4 | Sorting
<p>
Problem Description: Scholarly Reader <br> Given a list of the number of pages in all the books in the school library, and a maximum limit of the number of pages you are willing to read, determine the maximum number of books you can fully read! 
</p>

<br>

### Project 5 | Binary Search Trees
<p>
Problem Description:Word Sorting, Searching <br> A program that reads in words, one by one and stores them in a binary search tree, organized in alphabetical order. You  will  have  one  node  per  each  unique  word,  and  in  that  node,  you’ll  store  the word  with  its  frequency. Create a binary search tree of structs, where each struct stores a string (can be statically allocated) and an integer (its frequency). Though each field of the struct will be statically allocated, the structs themselves should be dynamically allocated when needed. 
<br>

Part I: Building the Tree, Answering Queries

Part II: Building a Sorted List of Words 
</p>

<br>

### Project 6 | Binary Heap
<p>
Problem Description: Priotrity Hair Salon <br> The hair salon has several stylists (no more than 10 working at a time). Each customer arrives at a particular time and then gets placed in a line to wait for a stylist.
<br>
Write a program that takes in information about arriving customers in the order in  which  they  come  (each  one  will  come  at  a  distinct  minute  after  the  salon  opens  to  avoid  concurrency  issues),  and  prints  out a  log in  the  order  in  which the  haircuts  finish, summarizing  each cut. If two cuts end at the same exact time, then the log for the cut made by the stylist at the lower numbered hair cut station should be printed first. 
</p>
