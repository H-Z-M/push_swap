#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <vector>

typedef struct s_array
{
	std::vector<int> original_array;
	std::vector<int> sorted_array;
}		t_array;

bool is_overlap(std::vector<int> arr, int len)
{
	for (int i = 0;  i < len; i++)
	{
		for (int j = i + 1;  j < len; j++)
		{
			if (arr[i] == arr[j])
				return true;
		}
	}
	return false;
}

t_array parse_args(int argc, char **argv)
{
	t_array arr;

	try
	{
		for (int i = 0; i < argc - 1; i++)
			arr.original_array.push_back( std::stoi(argv[i + 1]) );
	}
	catch (const std::invalid_argument &e) {
		std::cout << "invalid argument" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch (const std::out_of_range &e) {
		std::cout << "out of range" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (std::is_sorted(arr.original_array.begin(), arr.original_array.end()))
		std::exit(EXIT_FAILURE);

	for (int i = 0; i < argc - 1; i++)
		arr.sorted_array.push_back( arr.original_array[i] );
	std::sort(arr.sorted_array.begin(), arr.sorted_array.end());
	if (is_overlap(arr.sorted_array, argc - 1))
		std::exit(EXIT_FAILURE);

	return arr;
}

void set_index(std::deque<int> &stack_a, t_array &arr, int len)
{
	for (int i = 0;  i < len; i++)
	{
		for (int j = 0;  j < len; j++)
		{
			if (arr.sorted_array[i] == stack_a.at(j))
			{
				stack_a.at(j) = i;
			}
		}
	}
}

void push_stack(std::deque<int> &lhs, std::deque<int> &rhs)
{
	if (lhs.empty())
		return ;
	if (lhs == rhs)
	{
		std::cout << "push_stack error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	rhs.push_front(lhs.at(0));
	lhs.pop_front();
}

void swap_stack(std::deque<int> &stack)
{
	if (stack.empty())
		return ;
	int tmp = stack.at(0);
	stack.at(0) = stack.at(1);
	stack.at(1) = tmp;
}

void rotate_stack(std::deque<int> &stack)
{
	if (stack.empty())
		return ;
	stack.push_back(*stack.begin());
	stack.pop_front();
}

void reverse_rotate_stack(std::deque<int> &stack)
{
	if (stack.empty())
		return ;
	stack.push_front(*stack.end());
	stack.pop_back();
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::exit(EXIT_FAILURE);
	t_array arr = parse_args(argc, argv);
	std::deque<int> stack_a(argc - 1);
	std::deque<int> stack_b;

	for (int i = 0; i < argc - 1; i++)
		stack_a.at(i) = arr.original_array.at(i);
	set_index(stack_a, arr, argc - 1);

	push_stack(stack_a, stack_b);
	// push_stack(stack_a, stack_b);
	// push_stack(stack_a, stack_b);
	// rotate_stack(stack_a);
	rotate_stack(stack_b);
	// swap_stack(stack_a);

	for (std::deque<int>::iterator i = stack_a.begin(); i != stack_a.end(); i++)
		std::cout << *i << " ";
	std::cout << "\n";
	for (std::deque<int>::iterator i = stack_b.begin(); i != stack_b.end(); i++)
		std::cout << *i << " ";
	std::cout << "\n";
	return 0;
}
