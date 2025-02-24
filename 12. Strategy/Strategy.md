The strategy pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each one and makes them interchangeable. It lets the algorithm vary independent;y from clients that use it.

**Strategy Pattern:**
+ **Intent:** Define a family of algorithms, encapsulate each one and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
+ **Purpose:**
	+ Allow an object to alter its behavior when its internal state changes.
	+ Eliminate long conditional statements.
	+ Provide a way to choose algorithms at runtime.
	+ Improve code flexibility and maintainability.
+ **How it Works:**
	+ The Strategy pattern defines an interface for all concrete strategies.
	+ Concrete strategy classes implement the strategy interface and provide specific implementations of the algorithm.
	+ The context class holds a reference to a strategy object.
	+ The context class delegates the algorithm execution to the strategy object.

# When to Use the Strategy Pattern

+ **Multiple Algorithms:** When you have multiple algorithms for the same task.
+ **Runtime Algorithm Selection:** When you need to choose an algorithm at runtime.
+ **Avoiding Conditional Logic:** When you want to avoid complex conditional logic.