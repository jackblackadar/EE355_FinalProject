from connection import Connection

class Network:
    def __init__(self):
        self.people = []

    def add_person(self, person):
        self.people.append(person)

    def remove_person_by_name(self, name):
        self.people = [p for p in self.people if p.name.lower() != name.lower()]

    def save_to_file(self, filename):
        with open(filename, 'w') as f:
            for p in self.people:
                extras = ",".join([f"{k}={v}" for k, v in p.extra_info.items()])
                f.write(f"{p.name}|{p.birthdate}|{p.email}|{p.phone}|{extras}\n")

    def load_from_file(self, filename):
        self.people.clear()
        try:
            with open(filename, 'r') as f:
                for line in f:
                    parts = line.strip().split("|")
                    if len(parts) != 5:
                        continue
                    name, dob, email, phone, extras_str = parts
                    extras = dict(e.split("=") for e in extras_str.split(",") if "=" in e)
                    self.add_person(Connection(name, dob, email, phone, extras))
        except FileNotFoundError:
            print(f"File '{filename}' not found. Starting with empty network.")

    def search_by_any(self, query):
        results = []
        for person in self.people:
            if query.lower() in person.name.lower() or \
               query.lower() in person.email.lower() or \
               query.lower() in person.phone.lower() or \
               query.lower() in person.birthdate.lower() or \
               any(query.lower() in str(val).lower() for val in person.extra_info.values()):
                results.append(person)
        return results

    def recommend(self, person):
        scores = []
        for other in self.people:
            if other == person:
                continue
            score = 0
            if person.extra_info.get("college") == other.extra_info.get("college"):
                score += 1
            if person.extra_info.get("major") == other.extra_info.get("major"):
                score += 1
            if person.extra_info.get("state") == other.extra_info.get("state"):
                score += 1
            if person.email.split("@")[-1] == other.email.split("@")[-1]:
                score += 1
            scores.append((score, other))
        scores.sort(reverse=True, key=lambda x: x[0])
        return [other for _, other in scores[:3]]

    def mutual_connections(self, person):
        print(f"\nMutual Connections for {person.name}:")
        primary_recs = self.recommend(person)
        for rec in primary_recs:
            mutuals = []
            for p in self.people:
                if p == person or p == rec:
                    continue
                if p in self.recommend(person) and p in self.recommend(rec):
                    mutuals.append(p)
            print(f"\n→ With {rec.name}:")
            if mutuals:
                for m in mutuals:
                    print(f"  - You both may like: {m.name}")
            else:
                print("  No mutual strong connections found.")
