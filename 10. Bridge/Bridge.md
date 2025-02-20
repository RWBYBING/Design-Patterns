The Bridge pattern is another powerful structural design pattern that decouples an abstraction from its implementation so that the two can vary independently. It's particularly useful when you have a class hierarchy that could be complicated by multiple possible variations.

**Bridge Pattern:**
+ **Intent:** Decouple an abstraction from its implementation so that the two can vary independently.
+ **Purpose:** 
	+ Avoid "class explosion" caused by multiple combinations of abstract and concrete classes.
	+ Allow the abstraction and implementation to evolve independently.
	+ Improve code organization and maintainability.
+ **How it Works:**
	+ The Bridge pattern uses compostion. The abstraction class contains a reference to an interface (the "implementor" interface)
	+ Concrete implementor classes implement the implementor interface.
	+ The abstraction class delegates requests to the implementor object.

# When to Use Bridge Pattern

+ **Multiple Implementation:** When you have multiple ways to implement an abstraction.
+ **Independant Evolution:** When you need to be able to change the implementation without affecting the abstraction or vice versa.
+ **Avoiding Class Explosion:** When inheritance could lead to a large number of classes due to the combinations of abstraction and implementation.