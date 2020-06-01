#pragma once


class complex
{
private:
	double re, im;
public:
	complex() { 
		re = 0; 
		im = 0; 
	}
	complex(double r, double i) { 
		re = r; 
		im = i; 
	}
	complex(const complex &ob) { 
		re = ob.re; 
		im = ob.im; 
	};
	complex& operator = (complex);
	complex operator + (complex);
	complex operator - (complex);
	complex operator * (complex&);
	complex operator / (complex&);
	complex& operator += (complex);
	complex& operator -= (complex);
	complex& operator *= (complex);
	complex& operator /=(complex);
	friend std::istream& operator >> (std::istream&, complex&);
	friend std::ostream& operator << (std::ostream&, const complex&);
	bool operator == (complex& com);
	bool operator != (complex& com);
	bool operator > (complex& com);
	bool operator < (complex& com);

};

bool complex:: operator > (complex& com)
{
	if (this->re > com.re)
		return 1;
	else if (this->re == com.re && this->im > com.im)
		return 1;
	else
		return 0;
}

bool complex ::operator < (complex& com)
{
	if (this->re < com.re)
		return 1;
	else if (this->re == com.re && this->im < com.im)
		return 1;
	else
		return 0;

}

bool complex::operator != (complex& com)
{
	if (this->re != com.re || this->im != com.im)
		return 1;
	else
		return 0;
}

bool complex::operator==(complex& com)
{
	if (this->re == com.re && this->im == com.im)
		return 1;
	else
		return 0;
}



complex complex::operator*(complex &com)
{
	double i, j;
	i = re * com.re - im * com.im;
	j = re * com.im + com.re * im;
	re = i;
	im = j;
	return *this;
}

complex complex::operator/(complex &com)
{
	double i, j, k;
	k = re * re + com.im * com.im;
	i = (re * com.re + im * com.im) / k;
	j = (com.re * im - re * com.im) / k;
	re = i;
	im = j;
	return *this;
}

complex& complex::operator =(complex com)
{
	this->re = com.re;
	this->im = com.im;
	return *this;
}

complex complex::operator+(complex com)
{
	this->re = this->re + com.re;
	this->im = this->im + com.im;
	return *this;
}

complex complex::operator-(complex com)
{
	this->re = this->re - com.re;
	this->im = this->im - com.im;
	return *this;
}


std::ostream& operator << (std::ostream& out, const complex& com)
{
	if (com.im < 0)
		out << com.re << "+i(" << com.im << ")\n";
	else
		out << com.re << "+i" << com.im << "\n";
	return out;
}

std::istream& operator >> (std::istream& in, complex& com)
{
	std::cout << "Input real part of complex number: ";
	in >> com.re;
	std::cout << "Input imagine part of complex number: ";
	in >> com.im;
	return in;
}

complex& complex::operator+=(complex a)
{
	re += a.re;
	im += a.im;
	return *this;
}

complex& complex::operator-=(complex a)
{
	re -= a.re;
	im -= a.im;
	return *this;
}

complex& complex::operator*=(complex a)
{
	re *= a.re;
	im *= a.im;
	return *this;
}

complex& complex::operator/=(complex a)
{
	re /= a.re;
	im /= a.im;
	return *this;
}
