#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat Alice = Bureaucrat("Alice", 123);
		std::cout << Alice << std::endl;
		Alice.decrementGrade();
		std::cout << Alice << std::endl;
		Alice.incrementGrade();
		std::cout << Alice << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't create bureaucrat because because "<< '\n';
        std::cout << e.what() << std::endl;
	}
	return (0);
}