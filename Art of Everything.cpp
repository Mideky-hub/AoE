#include <iostream>
#include "src/Job.hpp"

int main(void)
{
	Job job = Job("Programmer", "Programs stuff", std::vector<Skill>{Skill("C++", 10), Skill("C#", 10), Skill("Java", 10)});
    return 0;
}