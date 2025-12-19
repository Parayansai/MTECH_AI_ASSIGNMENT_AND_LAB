def myfun(name, age):
    print(f"My name is {name} and I am {age} yrs old.")

person1 = {
    'name': "Divi",
    'age': 22
}


class myModule:
    def __init__(self):
        self.name = "Divi"
        self.age = 22

    def getAttributes(self):
        return [self.name, self.age]