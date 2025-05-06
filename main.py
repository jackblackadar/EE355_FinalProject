from connection import Connection
from network import Network

def load_mock_data():
    n = Network()
    n.add_person(Connection("Aleena Iman", "2002-08-20", "aleenim@usc.edu", "1702181577", {
        "college": "USC", "major": "EE", "state": "CA", "interest": "hardware design"
    }))
    n.add_person(Connection("Zeyneba Oumar", "2004-06-20", "oumarza@usc.edu", "1341110229", {
        "college": "USC", "major": "INCO", "state": "OR", "interest": "cyber security"
    }))
    n.add_person(Connection("Punda Ba", "2003-11-29", "punba@usc.edu", "9889093357", {
        "college": "USC", "major": "Global Health", "state": "AZ", "interest": "health administration"
    }))
    n.add_person(Connection("Roda Hassun", "2004-11-13", "rihassun@usc.edu", "4958334365", {
        "college": "USC", "major": "CECS", "state": "MN", "interest": "renewable energy"
    }))
    n.add_person(Connection("Razan Elinam", "2002-10-02", "elimamru@usc.edu", "5893868362", {
        "college": "USC", "major": "RED", "state": "AZ", "interest": "real estate"
    }))
    n.add_person(Connection("Alice Smith", "1999-08-20", "alice@usc.edu", "2134567890", {
        "college": "USC", "major": "EE", "state": "CA", "interest": "robotics"
    }))
    n.add_person(Connection("Bob Johnson", "1998-04-10", "bob@gmail.com", "3101234567", {
        "college": "USC", "major": "CS", "state": "CA", "interest": "AI"
    }))
    n.add_person(Connection("Clara Lee", "2000-01-01", "clara@yahoo.com", "4088765432", {
        "college": "UCLA", "major": "EE", "state": "CA", "interest": "circuits"
    }))
    n.add_person(Connection("Zebah Mamuun", "2004-05-21", "zmamuun@usc.edu", "7591363753", {
        "college": "USC", "major": "CSBA", "state": "CA", "interest": "product management"
    }))
    n.add_person(Connection("Hiduya Rujput", "2003-03-11", "hrujput@usc.edu", "8518827302", {
        "college": "USC", "major": "BME", "state": "CA", "interest": "medicine"
    }))
    n.add_person(Connection("Magan Vance", "2005-05-13", "magv@usc.edu", "8518927302", {
        "college": "USC", "major": "BME", "state": "CA", "interest": "medical devices"
    }))
    n.add_person(Connection("Jaden Smith", "1999-08-20", "jade@usc.edu", "78921940", {
        "college": "USC", "major": "Global Health", "state": "CA", "interest": "robotics"
    }))
    n.add_person(Connection("Aqsa Januu", "2006-05-23", "ajanuu@usc.edu", "6811299885", {
        "college": "USC", "major": "CSBA", "state": "WA", "interest": "AI and entrepreneurship"
    }))
    n.add_person(Connection("Megan Guzman", "2003-10-14", "meg@usc.edu", "9449033357", {
        "college": "USC", "major": "Biology", "state": "OR", "interest": "health administration"
    }))
    return n

def main():
    network = load_mock_data()

    while True:
        print("\n--- Menu ---")
        print("1. Search by any info")
        print("2. Recommend connections")
        print("3. Show all")
        print("4. Find mutual connections")
        print("0. Exit")

        choice = input("Enter choice: ")
        if choice == "1":
            q = input("Enter search query: ")
            results = network.search_by_any(q)
            for r in results:
                print("\n" + str(r))
        elif choice == "2":
            name = input("Enter your name: ")
            matches = [p for p in network.people if p.name.lower() == name.lower()]
            if matches:
                recs = network.recommend(matches[0])
                print("Top Recommendations:")
                for r in recs:
                    print("\n" + str(r))
            else:
                print("Name not found.")
        elif choice == "3":
            for p in network.people:
                print("\n" + str(p))
        elif choice == "4":
            name = input("Enter your name: ")
            matches = [p for p in network.people if p.name.lower() == name.lower()]
            if matches:
                network.mutual_connections(matches[0])
            else:
                print("Name not found.")
        elif choice == "0":
            break

if __name__ == "__main__":
    main()
