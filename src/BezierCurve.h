#ifndef _BEZIERCURVE_H
#define _BEZIERCURVE_H

#include "vector3.h"

class BezierCurve {
	public:
	std::vector<vector3d> p;

	BezierCurve(unsigned int numPoints) {
		p.resize(numPoints);
	}

	vector3d Eval(const double t) {
		int n_points = p.size();

		vector3d out(0.0);
		for (int i=0; i<n_points; i++) {
			double c = pow(1.0f-t, n_points-(i+1)) * pow(t,i) * BinomialCoeff(n_points-1, i);
			out += p[i] * c;
		}
		return out;
	}
	BezierCurve DerivativeOf() {
		int n_points = p.size()-1;
		BezierCurve out(n_points);
		for (int i=0; i<n_points; i++) {
			out.p[i] = (double)n_points * (p[i+1] - p[i]);
		}
		return out;
	}
	private:
	inline double Factorial(int n)
	{
		double r = 1.0;
		for (int i=2; i<=n; i++) {
			r *= (double)i;
		}
		return r;
	}
	inline double BinomialCoeff(int n, int m)
	{
		return Factorial(n)/(Factorial(m)*(Factorial(n-m)));
	}
};

#endif /* _BEZIERCURVE_H */