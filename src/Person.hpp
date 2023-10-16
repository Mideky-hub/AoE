#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include "Time.hpp"
#include "Job.hpp"

class Person {
private:
	std::string name;
	std::string family_name;
	Date date_of_birth;
	int age;
	std::vector<Job*> jobs;
};

#endif // !PERSON_HPP
