/*

1. How to create a vector that takes n number of inputs and enter it into the vector using v[0],v[1] = value method,
rather than using push_back() func

2. Unordered_map / set - do they initialize all values to 0 in case of integer data type? In which part of the memory
segment is it stored?

3. Why is & used in vector while using pass by reference- how are the pointers working in that case?

4. Can't we use substrings like str[0:3] ?

5. 
 struct comp {
	template <typename T>

	// Comparator function
	bool operator()(const T& l,
					const T& r) const
	{
		if (l.second != r.second) {
			return l.second < r.second;
		}
		return l.first < r.first;
	}
};

What does this code mean? 
Its kinda confusing to see struct like this. I was searching to sort map in terms of their value

*/