The Factory Method and Abstract Factory patterns are powerful creational patterns that promote flexibility and extensibility in object creation. [[Abstract Factory]]

# Factory Method Pattern

+ **Intent:** Define an interface for creating an object, but let subclasses decide which class to instantiate. The Factory Method lets a class defer instantiation to subclasses.
+ **Purpose:** 
	+ Decouple the client code from the concrete classes it needs to instantiate.
	+ Provide a way to create objects without specifying their exact classes.
	+ Allow subclasses to customize the object creation process.
+ **How it Works:**
	+ A "creator" class defines an abstract factory method.
	+ Subclasses of the creator class override the factory method to return instances of specific concrete classes.