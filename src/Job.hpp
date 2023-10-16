#ifndef JOB_HPP
#define JOB_HPP

#include <string>
#include <vector>

enum JobType {
	FullTime,
	PartTime,
	Contract
};

enum Hierachical_position {
	Employee,
	Manager,
	Executive,
	CEO
};


struct Skill {
	const std::string name;
	uint64_t level;

	Skill(const Skill& skill) : name(skill.name), level(skill.level) {}
	Skill(std::string& name, uint64_t& level) : name(name), level(level) {}
	~Skill() {}
};

struct Hierarchy {
	Hierachical_position position;
	std::vector<Hierarchy*> subordinates;

	Hierarchy(const Hierarchy& hierarchy) : position(hierarchy.position), subordinates(hierarchy.subordinates) {}
	Hierarchy(Hierachical_position& position) : position(position) {}
	~Hierarchy() {}
};

__interface IJob {
public:
	virtual std::string get_name() const noexcept = 0;
	virtual std::string get_description() const noexcept = 0;
	virtual std::vector<Skill> get_skills() const noexcept = 0;
	virtual JobType get_type() const noexcept = 0;
	virtual Hierarchy get_hierarchy() const noexcept = 0;
	virtual uint64_t get_salary() const noexcept = 0;
	virtual uint64_t get_yoe() const noexcept = 0;
};

class Job : public IJob {
private:
	const std::string name;
	const std::string description;
	const JobType type;
	std::vector<Skill> r_skills;
	Hierarchy hierarchy;
	uint64_t salary;
	uint64_t years_of_experience;
public:
	static void isJobValid(const Job& job) {
		if (job.name.empty()) throw std::invalid_argument("Job name cannot be empty");
		if (job.description.empty()) throw std::invalid_argument("Job description cannot be empty");
		if (job.salary < 0) throw std::invalid_argument("Salary cannot be negative");
		if (job.years_of_experience < 0) throw std::invalid_argument("Years of experience cannot be negative");
		if (job.type != JobType::FullTime && job.type != JobType::PartTime && job.type != JobType::Contract) throw std::invalid_argument("Invalid job type");
		if (job.type == JobType::Contract && job.years_of_experience < 5) throw std::invalid_argument("Contract job requires at least 5 years of experience");
	}

	Job() = default;
	Job(const Job& job)
		:	name(job.name), description(job.description), r_skills(job.r_skills),
			type(job.type), hierarchy(job.hierarchy), salary(job.salary), 
			years_of_experience(job.years_of_experience) {
		try {
			isJobValid(*this);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	Job(const std::string& name, const std::string& description, std::vector<Skill>& r_skills, const JobType& type, Hierarchy& hierarchy, const uint64_t& salary, const uint64_t& years_of_experience)
		:	name(name), description(description), r_skills(r_skills),
			type(type), hierarchy(hierarchy), salary(salary),
			years_of_experience(years_of_experience) {
		try {
			isJobValid(*this);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
			
	}
	virtual ~Job() = default;

	virtual std::string get_name() const noexcept override { return this->name; }
	virtual std::string get_description() const noexcept override { return this->description; }
	virtual std::vector<Skill> get_skills() const noexcept override { return this->r_skills; }
	virtual JobType get_type() const noexcept override { return this->type; }
	virtual Hierarchy get_hierarchy() const noexcept override { return this->hierarchy; }
	virtual uint64_t get_salary() const noexcept override { return this->salary; }
	virtual uint64_t get_yoe() const noexcept override { return this->years_of_experience; }


	bool operator==(const Job& job) const noexcept {
		return this->name == job.name && this->description == job.description && this->r_skills == job.r_skills;
	}

	bool operator!=(const Job& job) const noexcept {
		return !operator==(job);
	}
};

#endif // !JOB_HPP