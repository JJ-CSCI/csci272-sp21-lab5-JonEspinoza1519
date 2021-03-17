//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
protected:
  double real;

public:
  Real(double input=0){
    real = input;
  }
    double GetReal()const { return real; }
    Real operator+(const double& other) {
      Real returnReal{real + other};
      return returnReal;
    }
};

class Complex: public Real{
protected:
  double complex;

public:
  Complex(double inputA=0, double inputB=0){
    real = inputA;
    complex = inputB;
  }
  double GetImaginary()const { return complex; }
  Complex operator+(const double& other){
    Complex returnComplex{real + other, complex + other};
    return returnComplex;
  }
};
class Surreal: public Complex{
  double surreal;

public:
  Surreal(double inputA, double inputB, double inputC){
    real = inputA;
    complex = inputB;
    surreal = inputC;
  }
  double GetSurreal()const { return surreal; }
  Surreal operator+(const double& other){
    Surreal returnSurreal{real + other, complex + other, surreal + other};
    return returnSurreal;
  }
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
