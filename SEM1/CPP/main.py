from myModule import myfun, person1, myModule

import sys

print(sys.api_version)
print(sys.argv)

if __name__ == "__main__":
    
    myfun(person1["name"], person1["age"])
    person = myModule()

    print(person.getAttributes())
    print("Name of this module is ", __name__)
