# CSE_302_Proj2

This Project utilizes both the AUList and Stack Abstract Data Types

This code take in a dataset from the superbowl.csv file and turns it into an AULIST.

The User then has 4 options:
1. To create a stack with the Winners of each SuperBowl from the first game of its name
2. To create a stack with the Losers of each SuperBowl from the first game of its name
3. To create a stack with the MVP winner of each SuperBowl from the first game of its name
4. The 4th option lets the user quit the program with a last second option to continue to quit or print the entire dataset line by line

Current Application:
- The CreateStack method from the AUList Class uses a tempory stack for the return method and loops through the contents of the List, pushing the specified item onto the chosen stack by the user.
- The printList method utilizes the same principles of the CreateStack method but uses every field available from the dataset and is specific only to the AUList.

Future Addition:
- The List prints backwards from most recent game to first of its name because of the the way the data is set up in the CSV file. The plan is the try and give users the option to print it the opposite way.
- The stack works properly because by principle the stack is a first in, last out ADT so I plan on giving the user the option to print the list in a way of their choosing.
