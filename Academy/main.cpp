#include <iostream>
using namespace std;





class Human {

protected:
	string last_name;
	string first_name;
	int age;

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const {

		return age;
	}

	void set_last_name(const std::string& last_name) {

		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name) {

		this->first_name = first_name;
	}
	void set_age(int age) {

		this->age = age;
	}

	Human(const std::string& last_name, const std::string& first_name, int age) {

		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Hconstructor\t" << this << endl;
	}
	~Human() 
	{
		cout << "Destructor\t" << this << endl;
	}
	void print() const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

class Student :public Human
{

	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const
	{
		return speciality;

	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance() const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//Constructors:

	Student(const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "Sconstructor\t" << this << endl;
	}
	~Student()
	{
		{
			cout << "S_Destructor\t" << this << endl;
		}
	}

	void print() const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

class Teacher : public Human
{
	std::string subject;
	int certificate_year_expired;
	double salary;
	int elective_qty;
	int rewards_qty;

public:

	const std::string& get_subject()const
	{
		return subject;
	}
	int get_certificate_year_expired() const
	{
		return certificate_year_expired;
	}
	double get_salary()const
	{
		return salary;
	}
	int get_elective_qty()const
	{
		return elective_qty;
	}
	int get_rewards_qty()const
	{
		return rewards_qty;
	}

	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_certificate_year_expired(int certificate_year_expired)
	{
		this->certificate_year_expired = certificate_year_expired;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	void set_elective_qty(int elective_qty)
	{
		this->elective_qty = elective_qty;
	}
	void set_rewards_qty(int rewards)
	{
		this->rewards_qty = rewards;
	}

	Teacher(const std::string& last_name, const std::string& first_name, int age, 
		const std::string& subject, int certificate_year_expired, double salary, int elective_qty, int rewards_qty
	) :Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_certificate_year_expired(certificate_year_expired);
		set_salary(salary);
		set_elective_qty(elective_qty);
		set_rewards_qty(rewards_qty);
		cout << "Tconstructor\t" << this << endl;
	}
	~Teacher()
	{
		{
			cout << "T_Destructor\t" << this << endl;
		}
	}

	void print() const
	{
		Human::print();
		cout << subject << " " << certificate_year_expired << " " << salary << " " << elective_qty << " " << rewards_qty << endl;
	}
};

class Graduated : public Student
{
	std::string diploma_numeration;
	int year_of_graduation;

public: 
	const std::string& get_diploma_numeration()const
	{
		return diploma_numeration;
	}
	int get_year_of_graduation()const
	{
		return year_of_graduation;
	}

	void set_diploma_numeration(const std::string& diploma_numeration)
	{
		this->diploma_numeration = diploma_numeration;
	}
	void set_year_of_graduation(int year_of_graduation)
	{
		this->year_of_graduation = year_of_graduation;
	}

	Graduated(const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance, 
		const std::string& diploma_numeration, int year_of_graduation
	) : Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_diploma_numeration(diploma_numeration);
		set_year_of_graduation(year_of_graduation);
		cout << "Gconstructor\t" << this << endl;
	}
	~Graduated()
	{
		{
			cout << "G_Destructor\t" << this << endl;
		}
	}

	void print() const
	{
		Student::print();
		cout << diploma_numeration << " " << year_of_graduation << endl;
	}
};



void main() {

	setlocale(LC_ALL, "");
	
	/*Human human("Montana", "Antonio", 30);
	human.print();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98);
	stud.print();*/

	Teacher ferras("Ferras", "Brian", 28, "Math", 2025, 98000.20, 2, 1);
	ferras.print();

	Graduated tasker("Tasker", "Steve", 19, "Chemistry", "WW_115", 93, 92, "AA_008798", 2022);
	tasker.print();



}
