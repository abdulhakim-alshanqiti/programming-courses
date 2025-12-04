#include <iostream>
#include "../../../Libs/MyLib.h"
#include "../../../Libs/Date.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsCalculator {
private:

	int _Result = 0;

	enum enOperation {None,Cancel,Adding,Subtracting,Multiplying,Dividing};
	struct _LastOp {
		int Number = 0;
		enOperation Op = None;
		int Result= 0;
	};
	_LastOp _LastOperation;

	string _OpToStr(enOperation Operation) {
		switch (Operation) {
		case Adding: return "Adding";
		case Subtracting: return "Subtracting by";
		case Multiplying: return "Multiplying by";
		case Dividing: return "Dividing by";
		case Cancel:  return "Canceling Last Operation";
		default :return "There is No Operation";
		}

	}
public:

	void Clear() {
		_LastOperation.Number= 0;
		_LastOperation.Op = None;
		_LastOperation.Result = 0;

		_Result = 0;
	}
	void Add(int Number) {
		_LastOperation.Op = Adding;
		_LastOperation.Number = Number;
		_LastOperation.Result = _Result;

		_Result += Number;
	}
	void Subtract(int Number) {

		_LastOperation.Op = Subtracting;
		_LastOperation.Number = Number;
		_LastOperation.Result = _Result;

		_Result -= Number;
	}
	void Multiply(int Number) {
		_LastOperation.Op = Multiplying;
		_LastOperation.Number = Number;
		_LastOperation.Result = _Result;


		_Result *= Number;
	}
	void Divide(int Number) {
		_LastOperation.Op = Dividing;
		_LastOperation.Number = Number;
		_LastOperation.Result = _Result;

		_Result /= (Number == 0) ? 1 : Number;


	}
	void CancelLastOperation() {

		_Result = _LastOperation.Result;

		_LastOperation.Number = 0;
		_LastOperation.Op = Cancel;
		_LastOperation.Result = 0;
	
	}
	void PrintResult() {
		switch (_LastOperation.Op) {
			case Cancel:
				 	printf("Result After Cancelling Last Operation = %d \n", _Result);
			break;

			case None:
				printf("There Is No Operation To Show The Result is = %d \n", _Result);
			break;

			default: 
				printf("Result After %s %d = %d \n", _OpToStr(_LastOperation.Op).c_str(), _LastOperation.Number, _Result);
			break;
		}

	}

	int FinalResult() {
		return _Result;
	}


};
int main() {


	clsCalculator Calculator1;
	Calculator1.Clear();
	Calculator1.PrintResult();

	Calculator1.Add(20);
	Calculator1.PrintResult();

	Calculator1.Add(2);
	Calculator1.PrintResult();

	Calculator1.CancelLastOperation();
	Calculator1.PrintResult();

	Calculator1.Subtract(8);
	Calculator1.PrintResult();

	Calculator1.Multiply(3);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();

	Calculator1.Divide(2);
	Calculator1.PrintResult();

	printf("Final Result = %d ", Calculator1.FinalResult() );

	return 0;
}