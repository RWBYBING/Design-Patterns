+ **Intent:** Provide an interface for creating families of related or dependent objects without specifying their concrete classes.
+ **Purpose:** 
	+ Create objects that belong to a related family
	+ Ensure that the client code works with the correct family of objects.
	+ Decouple the client code from the specific families of objects it uses.
+ **How it Works:**
	+ An abstract factory interface defines methods for creating different types of related objects.
	+ Concrete factory classes implement the abstract factory interface and return instances of specific concrete product classes.
	+ Client code uses the abstract factory to create objects.

# Use Case

This part should be discuss with [[Factory Method]]

## When to Use the Factory Method

+ Only need to create a single type of object.
+ The specific implementation needs to be decided at runtime
+ When working with a class that cannot anticipate the class of objects it must create.

## When to Use the Abstract Factory

+ Create families of related or dependent objects.
+ Ensure that the client code works with the correct family of objects.
+ The system needs to support switching the entire product family.

## When to Use Neither

+ Object creation is simple and straightforward.
+ Don't need to defer object creation to subclasses


## Common Misunderstanding

+ Incorrect use of abstract factories: Using abstract factories when you only need to create a single product can lead to unnecessary complexity.
+ Ignoring product compatibility: Using multiple factory methods to implement scenarios that should use abstract factories may lead to incompatible product combinations.
+ Premature optimization: Premature introduction of abstract factories when requirements are unclear will increase maintenance costs.
+ Interface bloat: The abstract factory interface contains too many creation methods and should be considered for splitting.