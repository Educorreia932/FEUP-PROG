#pragma once

class Coin {
	public:
		Coin(int v, char u);
		void showDescription() const; //mostra descrição da moeda (ex: 1E para um euro ou 2C para 2 cêntimos)
		double getValue() const; //NOTAR o double: retorna o valor da moeda em euros (ex: 0.01 para 1 cênt.)
	private:
		int value;
		char unit; // 'E' para 'euro' ou 'C' para 'cêntimo'
};