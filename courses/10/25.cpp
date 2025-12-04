#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;


class clsPerson{

	string _FullName = "";
public:
	class clsAddress {

		
	public:
		struct stAddress {
			string Country = "";
			string City = "";
			string Dist = "";
			string Street = "";
		};


		stAddress Address;

		clsAddress(string Country, string City, string Dist, string Street) {
			Address = { Country,  City,  Dist,  Street };
		}

		string Country() {
			return Address.Country;
		}
		string City() {
			return Address.City;
		}
		string Dist() {
			return Address.Dist;
		}
		string Street() {
			return Address.Street;
		}

		void Print() {
			Printl("Address Details");
			Printl(RepeatString(30, "="));
			Printl("Country : " + Address.Country);
			Printl("City : " + Address.City);
			Printl("Dist : " + Address.Dist);
			Printl("Street : " + Address.Street);
		}

	};
	
	clsAddress Address = clsAddress("","","","");
	clsPerson(string FullName,string Country, string City, string Dist, string Street) {
		
		_FullName = FullName;
		Address = { Country,  City,  Dist,  Street };
	}

	string FullName() {
		return _FullName;
	}

	void setFullName(string FullName) {
		 _FullName = FullName;
	}

};






int main() {
	clsPerson Person("Abdulhakim Alshanqiti","Saudi Arabia","Madinah", "Random Dist", "Random Street");

	Person.Address.Print();



	return 0;
}