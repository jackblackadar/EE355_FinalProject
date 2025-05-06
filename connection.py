class Connection:
    def __init__(self, name, birthdate, email, phone, extra_info=None):
        self.name = name
        self.birthdate = birthdate
        self.email = email
        self.phone = phone
        self.extra_info = extra_info if extra_info else {}

    def __str__(self):
        base = f"Name: {self.name}\nDOB: {self.birthdate}\nEmail: {self.email}\nPhone: {self.phone}"
        extra = "\n".join([f"{k}: {v}" for k, v in self.extra_info.items()])
        return base + "\n" + extra
