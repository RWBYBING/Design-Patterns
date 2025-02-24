The command pattern is a behavioral design pattern that encapsulates a request as an object, thereby letting you parameterize clients with queues, requests and operations. It also supports undoable operations.

+ **Intent:** Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests and support undoable operations.
+ **Purpose:**
	+ Decouple the object that invokes an operation from the one that knows how to perform it.
	+ Support undoable operations.
	+ Support queuing of requests.
	+ Support logging of requests.
+ **How it Works:**
	+ The Command interface declares an `execute()` method.
	+ Concrete command classes implement the Command interface and encapsulate a request.
	+ The Invoker class holds a command object and calls its `execute()` method.
	+ The Receiver class knows how to perform the operations associated with the request.
	+ The Client creates concrete command objects and sets their receivers.

# When to Use the Command Pattern

+ **Undoable Operations:** When you need to support undo/redo functionality.
+ **Queuing Requests:** When you need to queue requests for later execution.
+ **Parameterizing Requests:** When you need to parameterize requests with different operations.
+ **Decoupling Invokers and Receivers:** When you want to decouple the objects that invoke operations from the objects that perform them.
+ **Transcation Processing:** When you need to implement transaction processing.
