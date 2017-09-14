

#include <iostream>


size_t 
fibonacci__recurse__(const size_t N)
{
	if(N <= 1) 
		return 1;
	return fibonacci__recurse__(N-1) + fibonacci__recurse__(N-2);
}

size_t
fibonacci__iterative__(const size_t N)
{
	if(N <= 1) 
		return 1;

	size_t a = 1, b = 1, c{};

	for (size_t i = 2; i <= N; ++i) 
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
} 

size_t
factorial__recurse__(const size_t N) 
{
	if(N == 0) 
		return 1;
	return N * factorial__recurse__(N - 1);
}	

size_t
factorial__iterative__(const size_t N) 
{
	if(N == 0) 
		return 1;

	size_t accumulator = N; 
	for(size_t i = N-1; i >= 1; --i) 
	{	
		accumulator *= i;
	}

	return accumulator;
}


int 
main()
{
	std::cout << "\nfibonacci__recurse__:\n";
	for(size_t i = 0; i < 10; ++i)
		std::cout << i << ": " << fibonacci__recurse__(i) << '\n';

	std::cout << "\nfibonacci__iterative__:\n";
	for(size_t i = 0; i < 10; ++i)
		std::cout << i << ": " << fibonacci__iterative__(i) << '\n';

	std::cout << "\nfactorial__recurse__:\n";
	for(size_t i = 0; i < 10; ++i)
		std::cout << i << ": " << factorial__recurse__(i) << '\n';

	std::cout << "\nfactorial__iterative__:\n";
	for(size_t i = 0; i < 10; ++i)
		std::cout << i << ": " << factorial__iterative__(i) << '\n';

	return 0;
}