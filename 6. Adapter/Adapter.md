The Adapter pattern is a structural design pattern that allows you to make incompatible interfaces work together. It acts as a bridge between two classes that wouldn't otherwise be able to communicate due to differing interfaces.

+ **Intent:** Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.
+ **Purpose:**
	+ Enable collaboration between classes with incompatible interfaces.
	+ Reuse existing classes that don't match the required interface.
	+ Simplify the integration of third-party libraries or legacy code.
+ **How it Works:**
	+ The adapter class implements the interface that the client expects.
	+ The adapter class holds a reference to an instance of the class with the incompatible interface (the "adaptee").
	+ The adapter class forwards requests from the client to the adaptee, translating them as needed.

# When to Use the Adapter Pattern

+ **Incompatible Interfaces:** When you have two classes that need to work together but have incompatible interfaces.
+ **Exsiting Code Reuse:** When you want to reuse existing code without modifying it.
+ **Third-Party Integration:** When you need to integrate third-party libraries or legacy code.