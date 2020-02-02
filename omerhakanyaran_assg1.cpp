#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/**
   The FeetInches class holds distances measured in
   inches.
*/

class FeetInches
{
  private:
   int total_inches;    // The number of inches
   
   /**
      This constructor assigns 0 to the
      inches field.
   */

 public:
   FeetInches()
   { 
      total_inches = 0;
   }

   /**
      This constructor accepts two arguments which
      are assigned to the total_inches field.
      @param f The value to assign to feet.
      @param i The value to assign to inches.
   */
     
   FeetInches(int f, int i)
   { 
      total_inches = i + 12*f;
   }


   /**
      The following is a copy constructor. It accepts a
      reference to another FeetInches object. The total_inches
	  field is set to the same values as
      those in the argument object.
      @param object2 The object to copy.
   */

   FeetInches (const FeetInches& object2)
   {
      total_inches = object2.total_inches;
   }

   /**
      The setFeet method assigns a value to 
      the total_inches field.
      @param f The value to assign to feet.
   */

   void setFeet(int f)
   {
      total_inches += 12*f; 
   }

   /**
      The setInches method assigns a value to 
      the total_inches field.
      @param i The value to assign to inches.
   */

   void setInches(int i)
   {
      total_inches += i;
   }

   /**
      getFeet method
      @return The value in the total_inches field.
   */

   int getFeet()
   {
      return total_inches/12;
   }

   /**
      getInches method
      @return The value in the total_inches field.
   */

   int getInches()
   {
      return total_inches%12;
   }

   /**
      print method
      prints the distance as feet/inches
   */  
   void print()
   {
    cout << total_inches/12 << " feet  " << total_inches%12 << " inches";
   }
  
   /**
      The add method returns a FeetInches object
      that holds the sum of this object and another
      FeetInches object.
      @param object2 The other FeetInches object.
      @return A reference to a FeetInches object.
   */

   FeetInches add(const FeetInches& object2)
   {
      int totalFeet,    // To hold the sum of feet
          totalInches;  // To hold the sum of inches

      totalFeet = total_inches/12 + object2.total_inches/12;
      totalInches = total_inches%12 + object2.total_inches%12;
      return FeetInches(totalFeet, totalInches);
   }

   FeetInches scale(int s)
   {
      return FeetInches(s*total_inches/12, s*total_inches%12);
   }

   /**
      The equals method compares this object to the
      argument object. If both have the same values, 
      the method returns true.
      @return true if the objects are equal, false
      otherwise.
   */

   bool equals(FeetInches object2)
   {
      return total_inches == object2.total_inches;
   }

};

int main()
{
	FeetInches f(0, 30), g;
	int ft, in;
	cout << "Length 1 = "; f.print(); cout << endl;
	cout << "\nEnter length 2 feet: "; cin >> ft;
	cout << "Enter length 2 inches: "; cin >> in;
	g.setFeet(ft);
	g.setInches(in);
	
	cout << "\nLength 2 = "; g.print(); cout << endl;
	if (f.equals(g))
		cout << "\nThe lengths are the same\n\n";
	else
		cout << "\nThe lengths are not the same\n\n";
	FeetInches h = f.add(g);
	cout << "Sum of length 1 and 2 = "; h.print(); cout << endl;
	cout << "2 * length 1 = "; f.scale(2).print(); cout << endl;
	cout << "3 * length 2 = "; g.scale(3).print(); cout << endl;
	//getchar();
	system("pause");
	return 0;
}

