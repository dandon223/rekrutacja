# rekrutacja

## zadanie 1

Rozwiązanie zadania 1 znajduje się w folderze zadanie1.
## zadanie 2

Algorytm zlicza wystąpienia zer dla każdego rzędu.
1) Jeżeli suma wystąpień zer jest większa od 1, to macierz B będzie miała wszędzie 0.
2) Jeżeli występuje tylko jedno zero, to macierz B będzie miała wszędzie 0 oprócz tam gdzie zero występuje w macierzy A.
3) Jeżeli w macierzy A nie występują żadne 0 wystarczy przemnożyć wszystkie elementy tylko raz. Następnie dla każdego elementu w macierzy B należy dzielić powstały wynik przez element w macierzy A.

Do użycia liczb dowolnej precyzji użyto biblioteki bignum znajdującej się pod adresem https://github.com/michaeljclark/bignum. 

Kompilacja programu:
  Należy uruchomić skrypt make.sh
  
  W folderze build pojawi się plik wykonywalnu zadanie2.
  Wysokość i szerokość macierzy podaje się w formie argumentów z linii polecen.
  Przykład:
  
  ./zadanie2 5 5
