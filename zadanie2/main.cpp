#include <iostream>
#include <vector>
#include <random>
#include <chrono>

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

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,10);

    int M = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);

    std::vector<std::vector<int>> matrixA;
    std::vector<int> numberOfZeros;
    numberOfZeros.reserve(M);
    for(int i=0 ; i < M ; i++){
        std::vector<int> row;
        row.reserve(N);
        numberOfZeros.push_back(0);
        for(int j=0;j<N;j++){
            int value = dist(gen);
            row.push_back(value);
            if(value == 0 ){
                numberOfZeros[i] += 1;
            }
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
    std::cout<<"Number of zeros:\n";
    for(int numberOfZero : numberOfZeros){
        std::cout <<numberOfZero<<", ";
    }
    std::cout<<"\n";
    int sumOfZeros = 0;
    for(int numberOfZero : numberOfZeros){
        sumOfZeros += numberOfZero;
    }
    if(sumOfZeros > 1){
        std::cout<<"Matrix B:\n";
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                std::cout<<0<<", ";
            }
            std::cout<<"\n";
        }
    }
    else if(sumOfZeros == 1){
        int row = 0;
        for(int i =0 ; i < numberOfZeros.size(); i ++){
            if(numberOfZeros[i] == 1){
                row = i;
                break;
            }
        }
        for(int i=0 ; i < M ; i++){
            if(i != row){
                for(int j=0;j<N;j++){
                    std::cout<<0<<", ";
                }
            }else{
                for(int j=0;j<N;j++){
                    if(matrixA[i][j] != 0){
                        std::cout<<0<<", ";
                    }else{
                        std::cout<<getValue(matrixA,i,j,M,N)<<", ";
                    }
                }
            }
            std::cout<<"\n";
        }
    }else{
        int everyProduct = 1;
        for(int i=0 ; i < M ; i++){
            for(int j=0;j<N;j++){
                everyProduct *= matrixA[i][j];
            }
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                std::cout<<everyProduct/matrixA[i][j]<<", ";
            }
            std::cout<<"\n";
        }

    }
    return 0;
}
