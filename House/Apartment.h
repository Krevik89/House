#pragma once
#include<iostream>
#include"Person.h"
using namespace std;

class Apartment
{
    int m_num;
    int m_capacity;
    Person* m_people;

public:
    Apartment(int num = 0, int capacity = 1) : m_num(num), m_capacity(capacity) {
        m_people = new Person[capacity];
    }

    Apartment(const Apartment& other) {
        m_num = other.m_num;
        m_capacity = other.m_capacity;
        m_people = new Person[m_capacity];
        for (int i = 0; i < m_capacity; ++i) {
            m_people[i] = other.m_people[i];
        }
    }

    /*~Apartment() {
        delete[] m_people;
    }*/

    int GetNum() const {
        return m_num;
    }

    int GetCapacity() const {
        return m_capacity;
    }

    void SetNum(int num) {
        m_num = num;
    }

    void SetCapacity(int capacity) {
        if (capacity <= m_capacity) {
            return;
        }

        Person* new_people = new Person[capacity];
        for (int i = 0; i < m_capacity; ++i) {
            new_people[i] = m_people[i];
        }
        delete[] m_people;
        m_people = new_people;
        m_capacity = capacity;
    }

    Person GetPerson(int index) const {
        return m_people[index];
    }

    void SetPerson(int index, Person person) {
        m_people[index] = person;
    }
};

