#pragma once
#include <iostream>
#include "Apartment.h"
using namespace std;

class House
{
	int m_num_apartments;
	int m_capacity_apartments;
	Apartment* m_apartments;
public:
    House(int num_apartments = 1, int capacity_apartments = 1) : m_num_apartments(num_apartments), m_capacity_apartments(capacity_apartments) {
        m_apartments = new Apartment[m_capacity_apartments];
        for (int i = 0; i < m_num_apartments; i++) {
            m_apartments[i] = Apartment(i);
        }
    }

    House(const House& other) {
        m_num_apartments = other.m_num_apartments;
        m_capacity_apartments = other.m_capacity_apartments;
        m_apartments = new Apartment[m_capacity_apartments];
        for (int i = 0; i < m_num_apartments; i++) {
            m_apartments[i] = other.m_apartments[i];
        }
    }

   /* ~House() {
        delete[] m_apartments;
    }*/

    int GetNumApartments() const {
        return m_num_apartments;
    }

    int GetCapacityApartments() const {
        return m_capacity_apartments;
    }

    void SetNumApartments(int num_apartments) {
        if (num_apartments <= m_num_apartments) {
            return;
        }

        Apartment* new_apartments = new Apartment[num_apartments];
        for (int i = 0; i < m_num_apartments; ++i) {
            new_apartments[i] = m_apartments[i];
        }
        delete[] m_apartments;
        m_apartments = new_apartments;
        m_num_apartments = num_apartments;
        for (int i = m_num_apartments - 1; i >= m_num_apartments - (num_apartments - m_num_apartments); --i) {
            m_apartments[i] = Apartment(i);
        }
    }

    void SetCapacityApartments(int capacity_apartments) {
        for (int i = 0; i < m_num_apartments; ++i) {
            m_apartments[i].SetCapacity(capacity_apartments);
        }
        m_capacity_apartments = capacity_apartments;
    }

    Apartment GetApartment(int index) const {
        return m_apartments[index];
    }

    void SetApartment(int index, Apartment apartment) {
        m_apartments[index] = apartment;
    }
};

