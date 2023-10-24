/* You are developing a ticket management system for a popular theater. The system uses a Queue data structure to handle the ticketing process efficiently. Your task is to implement a program that simulates the ticket management system using an array-based queue.



The program should provide a user-friendly interface for theater staff to perform queue operations. 



They should be able to insert a ticket into the queue, delete a ticket from the queue, and display the tickets in the queue.
The queue has a maximum capacity of 5 tickets. If the queue is full and an insertion is attempted, the program should display a message saying "Queue is full."
If the queue is empty and a deletion is attempted, the program should display a message saying "Queue is empty." 


The program should handle these conditions appropriately and ensure that the queue operations are performed correctly.

Input format :
The input consists of an integer option representing the action to be performed:

Option 1: Insert an element into the queue. The next line contains an integer representing the element to be inserted.

Option 2: Delete an element from the queue.

Option 3: Display the elements in the queue.

Output format :
For each operation, the program should provide the appropriate output messages:

If option 1 is chosen, display a message indicating that the element is inserted in the queue.

If the maximum capacity of the queue is reached, and insertion is attempted, print "Queue is full."

If option 2 is chosen, display the deleted number.

If option 2 is chosen and if the queue is empty, and no elements can be deleted, print "Queue is empty."

If option 3 is chosen, display the elements in the queue.

If any other option other than 1, 2, or 3 is given, print "Invalid option."



Refer to the sample output for the exact text and format.

Code constraints :
The maximum size of the queue is defined as max = 5.

The queue can store integer values.

Sample test cases :
Input 1 :
1
10
3
5
Output 1 :
10 is inserted in the queue.
Elements in the queue are: 10 
Invalid option.
Input 2 :
1
30
1
40
2
3
Output 2 :
30 is inserted in the queue.
40 is inserted in the queue.
Deleted number is: 30
Elements in the queue are: 40 
Input 3 :
1
97
2
3
Output 3 :
97 is inserted in the queue.
Deleted number is: 97
Queue is empty.
Input 4 :
1
12
1
23
1
34
1
45
1
56
1
32
Output 4 :
12 is inserted in the queue.
23 is inserted in the queue.
34 is inserted in the queue.
45 is inserted in the queue.
56 is inserted in the queue.
Queue is full. */

