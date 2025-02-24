The template method pattern is a behavioral design pattern that defines the skeleton of an algorithm in the super-class but lets sub-classes override specific steps of the algorithm without changing its structure.

+ **Intent:** Define the skeleton of an algorithm in an operation, deferring  some steps to sub-classes. Template method lets sub-classes redefine certain steps of an algorithm without changing the algorithm's structure.
+ **Purpose:**
	+ Avoid Code duplication by providing a common algorithm structure.
	+ Allow sub-classes to customize specific steps of an algorithm.
	+ Control the order of operations in an algorithm.
+ **How it Works:**
	+ The abstract class (the template class) defines the template method, which outlines the algorithm's structure.
	+ The template method calls abstract methods (or hook methods) that sub-classes must implement.
	+ Concrete sub-classes implement the abstract methods to provide specific implementations of the algorithm's steps.
	+ Hook methods are methods that can be optionally overridden by the sub-class.
	  
# When to Use the Template Method Pattern

+ **Common Algorithm Structure:** When you have a common algorithm structure that needs to be shared among sub-classes.
+ **Customizable Steps:** When you need to allow sub-classes to customize specific steps of an algorithm.
+ **Controlling Algorithm Order:** When you need to control the order of operations in an algorithm.
