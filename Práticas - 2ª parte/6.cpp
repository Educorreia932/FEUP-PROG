#include <string>
#include <vector>

using namespace std;

class Product {
	public:
		Product(string description, int available_quantity);
		int getId() const;
		int getAvailableQuantity() const;
		void reduceAvailableQuantity();
	private:
		static int id;
		string description;
		int available_quantity;
};

int Product::id = 0;

Product::Product(string description, int available_quantity) {
	id++;
	this->description = description;
	this->available_quantity = available_quantity;
}

int Product::getId() const {
	return id;
}

int Product::getAvailableQuantity() const {
	return available_quantity;
}

void Product::reduceAvailableQuantity() {
	available_quantity--;
}

class Inventory {
	public:
		Inventory(vector <Product> products);
		void processOrder(int id);
		void processShipment(int id);
	private:
		vector <Product> products;
		vector <Product> backOrders;
};

Inventory::Inventory(vector <Product> products) {
	this->products = products;
}

void Inventory::processOrder (int id) {
	if (products[id].getAvailableQuantity() > 0)
		products[id].reduceAvailableQuantity;

	else
		backOrders.push_back(products[id]);
}

void Inventory::processShipment(int id) {
	for (int i = 0; i < size(backOrders); i++) {
		if (backOrders[i].getId == id)

	}
}