#include <iostream>
#include <vector>
#include <random>

int getValue(const std::vector<std::vector<int>>& matrixA, int row, int column, int M , int N){
    int result = 1;
    for(int i=0 ; i < M ; i++){
        for(int j=0;j<N;j++){
            if(i != row || j != column){
                result *= matrixA[i][j];
            }
        }
    }
    return result;
}
int main(int argc, char *argv[]) {

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,10);

    int M = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);

    std::vector<std::vector<int>> matrixA;
    for(int i=0 ; i < M ; i++){
        std::vector<int> row;
        row.reserve(N);
        for(int j=0;j<N;j++){
            row.push_back(dist(rng));
        }
        matrixA.push_back(row);
    }
    std::cout<<"Matrix A:\n";
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            std::cout<<matrixA[i][j]<<", ";
        }
        std::cout<<"\n";
    }


    std::vector<std::vector<int>> matrixB;
    for(int i=0 ; i < M ; i++){
        std::vector<int> row;
        row.reserve(N);
        for(int j=0;j<N;j++){
            row.push_back(getValue(matrixA,i,j,M,N));
        }
        matrixB.push_back(row);
    }

    std::cout<<"Matrix B:\n";
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            std::cout<<matrixB[i][j]<<", ";
        }
        std::cout<<"\n";
    }

    return 0;
}
