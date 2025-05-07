

1. Load and Save Network Data to a File
Files Used: networkDB.txt
On program start, it tries to load existing people from the file using load_from_file().
Each person's information is saved in a speficic format:
You can save the current network at any time (or automatically on exit) using save_to_file().

2. Add a New Person
Option 5 in the menu.
The user is prompted to enter the following information:
Name, Birthdate, Email, Phone
College, Major, State, Interest (extra_info)
This is added to the internal list and can be saved to file.

3. Remove a Person by Name
Option 6 in the menu.
Removes all entries matching the given name (case-insensitive).
This is useful for editing or maintaining the list over time.

4. Search by Any Info
Option 1 in the menu.
You can search by:
Name, Email, Phone, Birthdate
Any value in extra_info (e.g., “California” will match anyone from that state)
All matching people are printed out with their full info.

5. Show All People
Option 3 in the menu.
Displays the full list of people currently loaded in the network.

6. Recommend Connections
Option 2 in the menu.
Takes a user’s name and recommends top 3 people in the network who:
Have matching college, major, state
Or share the same email domain
The scoring is additive. For example, 2 matches = score of 2.

7. Mutual Connections
Option 4 in the menu.
For a given person, it checks their top 3 recommendations and compares them to each other's recommendations.
If there's a person who is recommended to both, it shows them as a mutual connection.

8. Exit (with Auto-Save)
Option 0 exits the program and automatically saves the current network to the file.

Connection class (from connection.py)
Represents a person in the network.
Stores
name, birthdate, email, phone
extra_info as a dictionary (e.g., college, major, etc.)
The __str__ method is likely implemented to neatly print out person details.
Network class (from network.py)
Stores all people as a list of Connection objects.
Supports adding, removing, saving, loading, searching, recommending, and finding mutuals.

The main() function loads the saved data and starts a loop with a user menu.
User actions are handled interactively via input.
Changes to the network are stored in memory until saved.
The design keeps logic modular — data representation in Connection, and network operations in Network.







