
It's a structural design pattern that provides a placeholder or surrogate for another object to control access to it, add functionality to it or both. Think of it as an intermediary or representative.

+ **Intent:** Provide a surrogate or placeholder for another object to control access to it.
+ **Purpose:**
	+ Control access to an object.
	+ Add functionality to an object without changing its class.
	+ Manage the lifecycle of an object.
+ **How it Works:**
	+ The proxy class implements the same interface as the real subject.
	+ The proxy class holds a reference to the real subject.
	+ When the client makes a request, the proxy class can perform some action before or after forwarding the request to the real subject.

# When to Use Proxy Pattern

+ **Resource Management:** When you have resource-intensive objects that should be loaded on demand.
+ **Security:** When you need to control access to sensitive objects.
+ **Remote Access:** When you're dealing with objects on remote servers.
+ **Logging/Caching:** When you want to add logging or caching behavior transparently.