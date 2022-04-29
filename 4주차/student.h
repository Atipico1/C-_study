/*Studnet는 공부를 하거나 논다. hp(health point)와 sp(smart point)라는 속성을 가진다.
Student는 UnderGradStudent과 GradStudent이라는 자식 클래스를 가진다.*/

class Student {
    public:
    Student(void);
    virtual void Study(int hr);
    virtual void HangOut(int hr);
    void Status(void);

    protected: //자식 클래스에서는 접근 가능
    int hp;  //health point
    int sp;  //smart point
};

/*Student class의 자식 클래스*/

class UnderGradStudent : public Student{
    public:
    UnderGradStudent(void):Student(){}
    void Study(int hr);
    void HangOut(int hr);
};

class GradStudent : public Student{
    public:
    GradStudent(void):Student(){}
    void Study(int hr);
    void HangOut(int hr);
};