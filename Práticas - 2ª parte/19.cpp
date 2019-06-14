#include <string>

class SpreadsheetCell { // an "abstract class"
	public:
		SpreadsheetCell() {
		};
		virtual ~SpreadsheetCell() { };
		virtual void set(const std::string& inString) = 0;
		virtual std::string getString() const = 0;
};

class SpreadsheetCellString {

};

class SpreadsheetCellDouble {};