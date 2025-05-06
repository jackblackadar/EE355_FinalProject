===========================
PHASE 3 EXTRA CREDIT PROJECT
===========================

DESCRIPTION:
-------------
This is a Python-based social network extension project built for Phase 3 extra credit.
It is a standalone implementation and does not depend on the C++ code from Phase 1 or Phase 2.

The project simulates a user network, where each person has personal and academic data stored,
and provides advanced features like intelligent search, recommendation, and mutual connection analysis.

===========================
FILES INCLUDED:
===========================

1. main.py            - The main menu interface for running the program.
2. connection.py      - Contains the Connection class representing each user/person.
3. network.py         - Contains the Network class to manage all users and implement features.

===========================
HOW TO RUN:
===========================

1. Make sure you have Python 3 installed.
2. Open a terminal and navigate to the folder containing these files.
3. Run the program by typing:

   python main.py
   (or python3 main.py if needed)

===========================
FEATURES IMPLEMENTED:
===========================

1. EXPANDED DATABASE:
   Each Connection includes additional information beyond name, email, phone, and birthdate.
   Added fields include:
   - College
   - Major
   - State
   - Interest

   This information is stored in a flexible dictionary (`extra_info`) and used in searches and recommendations.

2. WISE SEARCH FUNCTION:
   Users can search for a person using ANY available field, not just name.
   The program checks name, email, phone, birthdate, and any value in the extra_info dictionary.

3. RECOMMENDATION SYSTEM:
   The system suggests top 3 potential connections for each person based on:
   - Same college (+1)
   - Same major (+1)
   - Same state (+1)
   - Same email provider (e.g., both @usc.edu) (+1)

   Recommendations are ranked by score and displayed in descending order.

4. MUTUAL CONNECTIONS FINDER (**NEW FEATURE**):
   This is a unique addition. For a selected person, the program shows their top 3 recommended connections,
   and for each, it finds and displays any mutual strong recommendations.
   This mimics social networking behavior like “You both may know...”

===========================
EXAMPLE USAGE:
===========================
- Run the program
- Choose from the menu:
  1: Search anyone by name/email/college/etc.
  2: Get your top 3 recommended connections
  3: View the full list of users
  4: Discover mutual connections with others
  0: Exit

===========================
DEPENDENCIES:
===========================
- Python 3.x
- No external libraries required

===========================
NOTES:
===========================
This project is designed for clarity and extensibility.
You can easily modify the scoring logic, add more features, or connect it to a real dataset.
