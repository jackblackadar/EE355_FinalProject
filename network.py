class Network:
    def __init__(self):
        self.people = []

    def add_person(self, person):
        self.people.append(person)

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
        return [other for _, other in scores[:3]]  # top 3 recommendations
    
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

