#include <queue>
#include <iostream>
#include <vector>

//Comment

int search(int t_1, int t_2, int B, std::vector<std::vector<int>>& G);

int main(){

	int t_1, t_2, B;
	std::cout << "Input count vertex\n";
	std::cin >> t_1;
	std::cout << "\nInput start vertex\n";
	std::cin >> t_2;
	std::cout << "\nInput needed vertex\n";
	std::cin >> B;

	std::cout << std::endl;

	std::vector<std::vector<int>> G(t_1, std::vector<int>(t_1, 0));

	for (int i = 0; i < t_1; i++){

		for (int j = 0; j <= i; j++){

			if (i == j){

				G[i][j] = 0;
			}
			else{

				G[i][j] = int(rand() % 2);
				G[j][i] = G[i][j];
			}
		}
	}

	std::cout << "  ";
	for (int i = 1; i < t_1 + 1; i++){

		std::cout << ' ' << i;
	}

	for (int i = 0; i < t_1; i++){

		std::cout << "\n " << i + 1 << " ";
		for (int j = 0; j < t_1; j++){

			std::cout << G[i][j] << ' ';
		}
	}

	std::cout << std::endl;

	std::cout << "\nAnswer: " << search(t_1, t_2, B, G);

	return 0;
}

int search(int t_1, int t_2, int B, std::vector<std::vector<int>>& G) {

	std::queue<int>	q;
	std::vector<int> res(t_1, 0);
	std::vector<int> wasUsed(t_1, 0);
	int tmp;

	q.push(t_2);
	wasUsed[t_2 - 1] = 1;

	while (!q.empty()){

		tmp = q.front() - 1;
		q.pop();
		for (int i = 0; i < t_1; i++){

			if (G[tmp][i] == 1 && wasUsed[i] == 0){

				wasUsed[i] = 1;
				res[i] = 1 + res[tmp];
				q.push(i + 1);
			}
		}
	}

	return res[B - 1];
}