#include <string>

using namespace std;

class SpreadsheetCell { // an "abstract class"
	public:
		SpreadsheetCell() {};
		virtual ~SpreadsheetCell() {};
		virtual void set(const string& inString) = 0;
		virtual string getString() const = 0;
};

class SpreadsheetCellString : protected SpreadsheetCell {
	private:
		string cell_value;
};

class SpreadsheetCellDouble : protected SpreadsheetCell {
	private:
		double cell_value;
};