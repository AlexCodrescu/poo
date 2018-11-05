#include <iostream>
#include <cassert>
#include "complex.h"
#include "string.h"





	// ---------- global funcs ----------

	bool operator==(const Complex a_, const Complex b_)
	{
		return (a_.GetR() == b_.GetR() && a_.GetI() == b_.GetI());
	}

	bool operator!=(const Complex a_, const Complex b_)
	{
		return (a_.GetR() != b_.GetR() && a_.GetI() != b_.GetI());
	}

	Complex operator+(const Complex a_, const Complex b_)
	{
		Complex ret(a_.GetR() + b_.GetR(), a_.GetI() + b_.GetI());
		return ret;
	}

	Complex operator-(const Complex a_, const Complex b_)
	{
		Complex ret(a_.GetR() - b_.GetR(), a_.GetI() - b_.GetI());
		return ret;
	}

	Complex operator*(const Complex a_, const Complex b_)
	{
		double a = a_.GetR(), b = a_.GetI();
		double c = b_.GetR(), d = b_.GetI();

		Complex ret(a*c - b * d, b*c + a * d);

		return ret;
	}

	Complex operator/(const Complex a_, const Complex b_)
	{
		double a = a_.GetR(), b = a_.GetI();
		double c = b_.GetR(), d = b_.GetI();
		assert(c || d);

		Complex ret((a*c + b * d) / (c*c + d * d), (b*c - a * d) / (c*c + d * d));

		return ret;
	}

	Complex operator*(const Complex a_, const Complex b_)
	{
		int a = a_.GetR(), b = a_.GetI();
		int c = b_.GetR(), d = b_.GetI();

		Complex ret(a^c - b ^ d, b^c + a ^ d);

		return ret;
	}



	std::ostream& operator<<(std::ostream& os_, const Complex& comp_)
	{
		return os_ << '(' << comp_.GetR() << ',' << comp_.GetI() << "i)";
	}

	std::istream& operator>>(std::istream& is_, Complex& comp_) //  (a,bi) format
	{
		char ch = 0;
		double r = 0;
		double i = 0;

		is_ >> ch >> r >> ch >> i >> ch >> ch;

		comp_.SetR(r);
		comp_.SetI(i);

		return is_;
	}

	Complex operator+(const Complex a_)
	{
		Complex ret(a_.GetR() , a_.GetI() );
		return ret;
	}

	Complex operator-(const Complex a_, const Complex b_)
	{
		Complex ret(a_.GetR() , -a_.GetI());
		return ret;
	}

	int modul(const Complex a_)
	{
		int ret = sqrt(a_.GetR() * a_.GetR() + a_.GetI() * a_.GetI());
		return ret;
	}


	Complex::Complex(const double r_, const double i_) : m_r(r_), m_i(i_)
	{}

	Complex::Complex(Complex &c)
	{
		this->m_r = c.m_r;
		this->m_i = c.m_i;
	}

	Complex& Complex::operator+=(const Complex o_)
	{
		m_r += o_.m_r;
		m_i += o_.m_i;

		return *this;
	}

	Complex& Complex::operator=(const Complex o_)
	{
		m_r = o_.m_r;
		m_i = o_.m_i;

		return *this;
	}

	Complex& Complex::operator-=(const Complex o_)
	{
		m_r -= o_.m_r;
		m_i -= o_.m_i;

		return *this;
	}

	Complex& Complex::operator*=(const Complex o_)
	{
		double a = m_r, b = m_i, c = o_.m_r, d = o_.m_i;
		m_r = a * c - b * d;
		m_i = b * c + a * d;

		return *this;
	}

	Complex& Complex::operator/=(const Complex o_)
	{
		assert(o_.m_r || o_.m_i);
		double a = m_r, b = o_.m_r, c = m_i, d = o_.m_i;
		m_r = (a*c + b * d) / (c*c + d * d);
		m_i = (b*c - a * d) / (c*c + d * d);

		return *this;
	}


	double Complex::GetR()const
	{
		return m_r;
	}

	double Complex::GetI()const
	{
		return m_i;
	}

	void Complex::SetR(const double r_)
	{
		m_r = r_;
	}

	void Complex::SetI(const double i_)
	{
		m_i = i_;
	}


