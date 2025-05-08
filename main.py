from connection import Connection
from network import Network
import google.generativeai as genai
import pygame


genai.configure(api_key="AIzaSyAcK1OxBZStaq11Myeyd7VQ4HLfi0gw--4")  
model = genai.GenerativeModel(model_name="gemini-1.5-flash")  # or "gemini-1.5-pro"
pygame.mixer.init()

print("\n\n\n")
response = model.generate_content("Come up with a welcome greeting to a new user of a social network. The greeting should be friendly and welcoming, and it should encourage the user to explore the features of the network. The greeting should also include a brief overview of the network's purpose and how it can help users connect with others.")

print(response.text)
sound = pygame.mixer.Sound("fanfare.wav")
sound.play()

def input_person():
    name = input("Name: ")
    birthdate = input("Birthdate (YYYY-MM-DD): ")
    email = input("Email: ")
    phone = input("Phone: ")
    college = input("College: ")
    major = input("Major: ")
    state = input("State: ")
    interest = input("Interest: ")
    return Connection(name, birthdate, email, phone, {
        "college": college, "major": major, "state": state, "interest": interest
    })

def main():
    network = Network()
    filename = "networkDB.txt"
    network.load_from_file(filename)

    while True:
        print("\n--- Menu ---")
        print("1. Search by any info")
        print("2. Recommend connections")
        print("3. Show all")
        print("4. Find mutual connections")
        print("5. Add a person")
        print("6. Remove a person")
        print("7. Save to file")
        print("0. Exit")

        choice = input("Enter choice: ")
        sound = pygame.mixer.Sound("btn_click.wav")
        sound.play()
        if choice == "1":
            q = input("Enter search query: ")
            results = network.search_by_any(q)
            if results:
                for r in results:
                    print("\n" + str(r))
            else:
                print("No matching results found.")
        elif choice == "2":
            name = input("Enter your name: ")
            matches = [p for p in network.people if p.name.lower() == name.lower()]
            if matches:
                recs = network.recommend(matches[0])
                if recs:
                    print("Top Recommendations:")
                    for r in recs:
                        print("\n" + str(r))
                else:
                    print("No recommendations found.")
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
        elif choice == "5":
            person = input_person()
            network.add_person(person)
        elif choice == "6":
            name = input("Enter name to remove: ")
            network.remove_person_by_name(name)
        elif choice == "7":
            network.save_to_file(filename)
            print("Network saved.")
        elif choice == "0":
            network.save_to_file(filename)
            break

if __name__ == "__main__":
    main()

