# Software Design Principles

+ In software development, these principles guide the creation of maintainable, flexible and robust code. A prominent set is the **SOLID** principles:
	+ **Single Responsibility Principle (SRP)**
		+ A class should have only one reason to change.
	+ **Open/Closed Principle (OCP)**
		+ Software entities should be open for extension but closed for modification.
	+ **Liskov Substitution Principle (LSP)**
		+ Subtypes must be substitutable for their base types.
	+ **Interface Segregation Principle (ISP)**
		+ Clients should not be forced to depend on interfaces they do not use.
	+ **Dependency Inversion Principle (DIP)**
		+ High-level modules should not be forced to depend on low-level modules, both should depend on abstractions.

# The Relationship with Design Patterns

+ Design patterns are practical implementations of these software design principles. They provide reusable solutions to common software design problems.
+ By employing design patterns, we aim to achieve:
	+ **Maintainability:** Easier code modifications and updates.
	+ **Flexibility:** Adaptability to changing requirements.
	+ **Reusability:** Application of proven solutions in various contexts.

**Practical Considerations:**

- **"Keep it simple":** Don't overengineer your code. Only use design patterns when they solve a real problem.
- **Start simple and refactor:** If you're unsure whether you need a factory pattern, start with simple object creation and refactor later if necessary.
- **Consider the trade-offs:** Factory patterns add complexity to your code. Weigh the benefits of flexibility and maintainability against the added complexity.

# Design Patterns

+ **Creational Patterns:** 
	+ Singleton 
		+ [[Singleton]]
	+ Factory Method and Abstract Factory (for flexible object creation)
		+ [[Factory Method]]
		+ [[Abstract Factory]]
	+ Builder (for complex object construction)

+ **Structural Patterns:**
	+ Adapter (for adapting interfaces)
	+ Decorator (for adding responsibilities dynamically)
	+ Facade (for simplifying complex subsystems)
	+ Proxy (for controlling access to objects)

+ **Behavioral Patterns:**
	+ Observer (for event handling)
	+ Strategy (for algorithm selection)
	+ Command (for encapsulating requests)
	+ State (for changing object behavior based on internal state)
	+ Template Method (for defining the skeleton of an algorithm)