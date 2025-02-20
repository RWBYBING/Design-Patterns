The decorator pattern is a structural design pattern that allows you to dynamically add responsibilities to an object without altering its class. It provides a flexible alternative to subclassing for extending functionality.

+ **Intent:** Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.
+ **Purpose:**
	+ Add behavior to objects dynamically.
	+ Avoid “feature explosion" in subclasses.
	+ Provide a more flexible way to extend functionality than inheritance.
+ **How it Works:**
	+ The Decorator patter uses composition [[Composition is Better Than Inheritance]]. A decorator object contains a reference to the component it decorates.
	+ Decorators implement the same interface as the component.
	+ Decorators forward requests to the component and can add additional behavior before or after forwarding.
	+ Multiple decorators can be chained together to add multiple responsibilities.

# When to Use the Decorator Pattern

+ **Dynamic Behavior:** When you need to add responsibilities to objects dynamically.
+ **Feature Combinations:** When you have many possible combinations of features.
+ **Avoiding Subclassing:** When subclassing is impractical due to the number of combinations or when you want to add behavior that might not be known at compile time.