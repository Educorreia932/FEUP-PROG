#include "3.h"

Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const { //Exercise 3.b)
	Image Result(nLins, nCols, 0);

	for (int y = 0; y < nCols; y++)
		for (int x = 0; x < nLins; y++)
			Result.setPixel(y, x, img[lin][col]);

	return Result;
}

int main() { //Exercise 3.d)
	map<Date, vector<Image>> data;
	Date UserDate;
	string filename;
	vector<Image> images;

	cin >> UserDate;

	while (cin >> filename && filename != "") {
		Image Image;

		Image.read(filename);
		images.push_back(Image);
	}

	data.insert(pair<Date, vector<Image>>(UserDate, images));

	return 0;
}