# Notes
## *Runtime Complexity*  
**Runtime Complexity** defines how performant is a code snippet. Under performant we mean how many steps an algorithm makes while completing a task. Runtime Complexity simply defines that with more inputs how much more steps we deal with.

---

It can be O(n), O(n^2), and many more.
O(n) means that if the input grows linearly the runtime also grows in a linear fashion.
O(n^2), also called quadratic complexity, means that if the input grows linearly the runtime grows quadratically. For an n = 2 the algorithm has 4 things to do for example.   

---

Other interesting complexities are the constant complexity - O(1) -, the logaritmic time - O(log(n)), we have this if doubling the number of elements you are iterating over doesn't double the amount of work, for example searching operations -, and quasilinear time - O(n * log(n)), for  example any sorting algorithm will have this complexity. Finally, the most grueling one is the exponential time - O(2^n), you have this in that case if you add a *single* element to a collection, and the processing power needed doubles.

---

## *Space Complexity*
How much memory do the algorithm needs to complete its task?

---