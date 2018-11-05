



	class Complex
	{
	public:
		Complex(const double r_ = 0, const double i_ = 0);
		Complex(Complex &c);

		

		friend std::ostream& operator<<(std::ostream&, const Complex&);
		friend std::istream& operator>>(std::istream&, Complex&); // (a,bi) format

		friend bool operator==(const Complex, const Complex);
		friend bool operator!=(const Complex, const Complex);

		friend Complex operator+(const Complex);
		friend Complex operator-(const Complex);

		int modul(const Complex);

		friend Complex operator+(const Complex, const Complex);
		friend Complex operator-(const Complex, const Complex);
		friend Complex operator*(const Complex, const Complex);
		friend Complex operator/(const Complex, const Complex);
		friend Complex operator^(const Complex, const Complex);

		Complex& operator=(const Complex);
		Complex& operator+=(const Complex);
		Complex& operator-=(const Complex);
		Complex& operator*=(const Complex);
		Complex& operator/=(const Complex);
 

		double GetR()const;
		double GetI()const;

		void SetR(const double);
		void SetI(const double);

	private:
		double m_r;
		double m_i;
	};


