#ifndef CPROCESSING_PVECTOR_
#define CPROCESSING_PVECTOR_


using namespace cprocessing;

namespace cprocessing {   
    /// Represents a vector (or, sometimes, a point) in 3D
	class PVector {
	public:
		double x, y, z; ///< The coordinates
		/// Constructor
		PVector (double thex = 0, double they = 0, double thez = 0) : x(thex), y(they), z(thez) {}

		/// Assignment from coordinates
		void set (double thex = 0, double they = 0, double thez = 0) { x=thex; y=they; z=thez; }

		/// Assignment from another PVector
		void set (const PVector& other) { *this = other; }

		/// Assignment from an array of doubles
		void set (const double other[]) { x = other[0]; y = other[1]; z = other[2]; }

		/// Copy of the vector
		PVector get() { return *this; }

		/// Add
		PVector operator+(const PVector& other) const { return PVector(x+other.x, y+other.y, z+other.z); }
		PVector add (const PVector& other) {
			x += other.x;
			y += other.y;
			z += other.y; 
			return *this;
		}
		static PVector add (const PVector& a, const PVector& b) { return a+b; }

		/// Subtract
		PVector operator-(const PVector& other) const { return PVector(x-other.x, y-other.y, z-other.z); }
		PVector sub (const PVector& other) const { return *this-other; }
		static PVector sub (const PVector& a, const PVector& b) { return a-b; }

		/// Multiply by scalar
		PVector operator*(double s) const { return PVector(s*x, s*y, s*z); }
		PVector mult(double s) const { return *this*s; }
		static PVector mult(const PVector& v, double s)  { return v*s; }

		/// Divide by scalar
		PVector operator/(double s) const { return *this * (1/s); }
		PVector div(double s) const { return *this/s; }
		static PVector div(const PVector& v, double s)  { return v/s; }

		/// Dot product
		double dot (const PVector& other) const { return x*other.x + y*other.y + z*other.z; }
		static double dot (const PVector& a, const PVector& b) { return a.dot(b); }

		/// Cross product
		static PVector cross (const PVector& v1, const PVector& v2) {
			return PVector(v1.y * v2.z - v2.y * v1.z,
						v1.z * v2.x - v2.z * v1.x,
						v1.x * v2.y - v2.x * v1.y);
		}
		PVector cross (const PVector& other) const { return PVector::cross(*this,other); }

		/// Magnitude
		double mag () const { return sqrt(this->dot(*this)); }

		/// Distance between two points
		double dist (const PVector& other) const { return (this->sub(other)).mag(); }
		static double dist (const PVector& a, const PVector& b) { return a.dist(b); }

		/// Normalize (make unit length)
		void normalize() {
			double len = mag();
			if (len>1e-10)
			*this = *this / len;
		}

		/// Angle between two vectors
		static double angleBetween (const PVector& a, const PVector& b) {
			PVector acopy = a; acopy.normalize();
			PVector bcopy = b; bcopy.normalize();
			return acos(acopy.dot(bcopy));
		}

		/// Limit the magnitude of this vector to the value used for the max parameter
		void limit (double max) {
			double sz = this->mag();
			if (sz>max) *this = *this * (max / sz);
		}

		/// Returns vector coordinates as an array
		double* array() { return (double*) this; /* I KNOW this is unsafe! */ }
	};
}

#endif