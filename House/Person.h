#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
	string m_name;
	int m_age;
public:
    Person(string name = "", int age = 0) : m_name(name), m_age(age) {}

    Person(const Person& other) {
        m_name = other.m_name;
        m_age = other.m_age;
    }

    ~Person() {}

    string GetName() const {
        return m_name;
    }

    int GetAge() const {
        return m_age;
    }

    void SetName(string name) {
        m_name = name;
    }

    void SetAge(int age) {
        m_age = age;
    }
};

