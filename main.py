from connection import Connection
from network import Network

def load_mock_data():
    n = Network()
    n.add_person(Connection("Aleena Imran", "2003-08-20", "aleenaim@usc.edu", "1707181777", {
        "college": "USC", "major": "EE", "state": "CA", "interest": "hardware design"
    }))
    n.add_person(Connection("Zeynuba Oumar", "2004-06-17", "oumar@usc.edu", "1355110229", {
        "college": "USC", "major": "INCO", "state": "OR", "interest": "cyber security"
    }))
    n.add_person(Connection("Penda Ba", "2003-11-19", "pba@usc.edu", "9885093357", {
        "college": "USC", "major": "Global Health", "state": "AZ", "interest": "health administration"
    }))
    n.add_person(Connection("Roda Hassan", "2004-10-13", "rihassan@usc.edu", "4958323365", {
        "college": "USC", "major": "CECS", "state": "MN", "interest": "renewable energy"
    }))
    n.add_person(Connection("Razan Elimam", "2002-11-02", "elimam@usc.edu", "5713868362", {
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
    n.add_person(Connection("Zebah Mamoon", "2005-05-21", "zmamoon@usc.edu", "7521363753", {
        "college": "USC", "major": "CSBA", "state": "CA", "interest": "product management"
    }))
    n.add_person(Connection("Hidaya Rajput", "2005-04-11", "hrajput@usc.edu", "8519927302", {
        "college": "USC", "major": "BME", "state": "CA", "interest": "medicine"
    }))
    n.add_person(Connection("Magan Vance", "2005-05-13", "magv@usc.edu", "8518927302", {
        "college": "USC", "major": "BME", "state": "CA", "interest": "medical devices"
    }))
    n.add_person(Connection("Jaden Smith", "1999-08-20", "jade@usc.edu", "78921940", {
        "college": "USC", "major": "Global Health", "state": "CA", "interest": "robotics"
    }))
    n.add_person(Connection("Aqsa Janoo", "2006-06-27", "ajanoo@usc.edu", "6811291885", {
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
