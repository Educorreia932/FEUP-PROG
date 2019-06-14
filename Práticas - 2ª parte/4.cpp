#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Client {
	public:
		Client();
		Client(string name, string address);
		string getName() const;
		string getAddress() const;
	private:
		string name;
		string address;
};

Client::Client() {
	name = "";
	address == "";
}

Client::Client(string name, string address) {
	this->name = name;
	this->address = address;
}

string Client::getName() const {
	return name;
}

string Client::getAddress() const {
	return address;
}

class Product {
	public:
		Product();
		Product(string description, float price);
		string getDescription();
		float getPrice();
	private:
		string description;
		float price;
};

Product::Product() {
	this->description = "";
	this->price = 0;
}

Product::Product(string description, float price) {
	this->description = description;
	this->price = price;
}

string Product::getDescription() {
	return description;
}

float Product::getPrice() {
	return price;
}

class Item {
	public:
		Item(Product Product, unsigned int quantity) {
			this->Product = Product;
			this->quantity = quantity;
			total_price = Product.getPrice() * quantity;
		}
		Product getProduct();
		unsigned int getQuantity();
		float getTotalPrice();
	private:
		Product Product;
		unsigned int quantity;
		float total_price;
};

unsigned int Item::getQuantity() {
	return quantity;
}

float Item::getTotalPrice() {
	return total_price;
}

Product Item::getProduct() {
	return Product;
}

class Invoice {
	public:
		Invoice(Client Client, vector <Item> items) {
			this->Client = Client;
			this->items = items;
			amount_due = 0;
			
			for (int i = 0; i < size(items); i++)
				amount_due += items[i].getTotalPrice();
		}
		void showLine(int itemNumber);
		void show();
	private:
		Client Client;
		vector <Item> items;
		float amount_due;
};

void Invoice::showLine(int itemNumber) {
	cout << setw(20) << left << items[itemNumber].getProduct().getDescription()  << " "
		 << setw(6) << left <<items[itemNumber].getProduct().getPrice() << " "
		 << setw(4) << right << items[itemNumber].getQuantity() << " "
		 << setw(8) << right << items[itemNumber].getTotalPrice() << endl;
}

void Invoice::show() {
	cout << Client.getName() << endl 
		 << Client.getAddress() << endl
		 << setw(20) << left << "Description" << " " << setw(6) << left << "Price" << " " << setw(4) << left << "Qty" << " " << left << setw(8) << "Total"  << endl
		 << "-------------------- ------ ---- --------" << endl;
	
	for (int i = 0; i < size(items); i++)
		showLine(i);

	cout << endl << "Amount due: " << amount_due << " euro";
}

int main() {
	Client Client("DEI- FEUP ", "Rua Dr. Roberto Frias, s/n \n4200 - 465 Porto \n");
	Product Product1("Computer", 999.90);
	Product Product2("Printer", 149.90);
	Item Item1(Product1, 10);
	Item Item2(Product2, 1);
	Invoice Invoice(Client, { Item1,Item2 });

	Invoice.show();

	return 0;
}