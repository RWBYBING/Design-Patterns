Observer Pattern is a fundamental behavioral design pattern that establishes a one-to-many dependency between objects.

+ **Intent:** Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
+ **Purpose:** 
	+ Establish a notification mechanism between objects.
	+ Decouple the subject (the object being observed) from its observers (the objects that are notified).
	+ Implement distributed event handling systems.
+ **How it Works:**
	+ The subject maintains a list of observers.
	+ Observers register themselves with the subject.
	+ When the subject's state change, it notifies all registered observers.
	+ Observers then update themselves based on the notification.
	  
	  
# When to Use the Observer Pattern

+ **One-to-Many Dependencies:** When a change in one object requires changes in other objects.
+ **Decoupled Components:** When you want to decouple the subject from its observers.
+ **Event Handling:** When you need to implement event notification mechanisms.