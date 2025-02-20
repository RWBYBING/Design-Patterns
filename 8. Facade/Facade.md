The facade pattern is a structural design pattern that provides a simplified interface to a complex system of classes, libraries or subsystems. It shields the client from the intricacies of underlying system, making it easier to use and understand.

+ **Intent:** Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.
+ **Purpose:**
	+ Simplify the use of a complex subsystem.
	+ Reduce coupling between the client and the subsystem.
	+ Provide a higher-level interface that is easier to understand and use.
+ **How it Works:**
	+ The Facade class provides a simple interface to the client.
	+ The Facade class interacts with the various classes in the subsystem to fulfill the client's requests.
	+ The client code only interacts with the Facade class, not the individual classes in the subsystem.
	  
# When to Use Facade Pattern

+ **Complex Subsystems:** When you have a complex system of classes or libraries.
+ **Simplified Interface:** When you want to provide a simplified interface to the subsystem.
+ **Reducing Coupling:** When you want to reduce the coupling between the client and the subsystem.