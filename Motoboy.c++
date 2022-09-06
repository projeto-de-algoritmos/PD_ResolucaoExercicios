#include <bits/stdc++.h>
using namespace std;

#define MAX_PIZZAS 40
#define MAX_PEDIDOS 30
#define MAX_TEMPO 100

int Qnt_pizzas[MAX_PIZZAS];
int tempo_total[MAX_PEDIDOS];

int memo[MAX_TEMPO][MAX_TEMPO];

int knapsack(int pedidos, int pizzas)
{

    if (pedidos < 0 || pizzas <= 0)
        return 0;

    if (memo[pedidos][pizzas] != -1)
        return memo[pedidos][pizzas];

    if (Qnt_pizzas[pedidos] > pizzas)
        return memo[pedidos][pizzas] = knapsack(pedidos - 1, pizzas);

    return memo[pedidos][pizzas] = max(knapsack(pedidos - 1, pizzas), knapsack(pedidos - 1, pizzas - Qnt_pizzas[pedidos]) + tempo_total[pedidos]);
}

int main()
{

    ios::sync_with_stdio(0);
    
    int numero_de_pedidos;
    while (cin >> numero_de_pedidos)
    {
        if (!numero_de_pedidos)
            return 0;
        // Inicialização da matriz de memoização com -1
        memset(memo, -1, sizeof memo);
        int maximo_pizzas;
        cin >> maximo_pizzas;

        for (int i = 0; i < numero_de_pedidos; ++i)
        {
            cin >> tempo_total[i] >> Qnt_pizzas[i];
        }
        cout << knapsack(numero_de_pedidos - 1, maximo_pizzas) << " min.\n";

    }

    return 0;
}
