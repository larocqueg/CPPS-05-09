#include <string>
#include <iostream>
#include <exception>

#define RED	 "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN	"\033[36m"
#define RESET   "\033[0m"

class Bureaucrat
{
  private:
	  unsigned int _grade;
	  const std::string _name;

  public:
  	Bureaucrat();
	  Bureaucrat(std::string& name, unsigned int grade);
	  Bureaucrat(const Bureaucrat& original);
	  Bureaucrat& operator=(const Bureaucrat& original);
	  ~Bureaucrat();

	  void incrementGrade();
	  void decrementGrade();
	  std::string getName() const;
	  unsigned int getGrade() const;

	  class gradeTooHighException : public std::exception
	  {
	    public:
		    const char* what() const throw() {
			    return  "Grade too high!";
		  }
	  };

	  class gradeTooLowException : public std::exception
	  {
	    public:
		    const char* what() const throw() {
			    return "Grade too low!";
		  }
	  };

	  class cannotIncrementException : public std::exception
	  {
	    public:
		    const char* what() const throw() {
			    return  "Grade cannot be higher than 1!";
		  }
	  };

	  class cannotDecrementException : public std::exception
	  {
	    public:
		    const char* what() const throw() {
			    return  "Grade cannot be lower than 150!";
		  }
	  };
};
