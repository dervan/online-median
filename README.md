# online-median
Program służy do obliczania mediany aktualnie wczytanych liczb naturalnych (tj. typu *int*).

## tl;dr
Istotny kod implementacji jest w folderach **./src** i **./include**.
Analiza złożoności algorytmów umieszona jest na dole poniższego readme.

## Kompilacja
Po ściągnięciu repozytorium powinno wystarczyć wejście do folderu ./build i wydanie standardowych komend:
```
cmake ..
make
```

Wszystkie pliki wykonywalne powinny zostać umieszczone w folderze ./bin
Budowanie było testowane na trzech komputerach z Linuksem, na wszystkich kompilowało się bez problemu. Mam nadzieję, że na Macach też będzie OK :)

## Używanie programu
Głównym plikiem wykonywalnym jest median_calculator. Ponieważ z treści zadania nie wywnioskowałem na 100% jak często należy podawać medianę to program działa w dwóch wersjach. Pierwsza, domyślna, to podawanie mediany gdy na wejściu zamiast liczby pojawi się litera "m".
Druga to podawanie mediany po wczytaniu każdej nowej liczby. Program włącza się w tym trybie po dodaniu flagi *-e*

Samo obliczanie mediany program może realizować na trzy sposoby:
- ArrayMedianCalculator - czyli posortowana tablica do której kolejne elementy dokładane są na odpowiednie miejsca. Uruchamia się go flagą *-a*
- MagicFivesCalculator - czyli zwykła tablica do której dopisujemy kolejne elementy na końcu, a kiedy otrzymujemy zapytanie o medianę uruchamiamy algorytm magicznych piątek (czyli tzw. medianę median). Tą wersję otrzymamy dodając flagę *-f*
- HeapMedianCalculator - czyli dwa kopce, przechowujące odpowiednio elementy mniejsze i większe od aktualnej mediany. To jest domyślna wersja, nie trzeba dodawać żadnej opcji, ale żeby było symetrycznie możemy dodać flagę *-h*


## Uruchamianie testów
W już zbudowanym projekcie wystarczy wydać polecenie
```
make check
```
by sprawdzić testy jednostkowe. Żeby uruchomić testy wydajnościowe należy w folderze ./bin uruchomić skrypt:
```
./run_performance_tests.sh
```

## Generowanie własnych testów
Program ./test_generator pozwala na generowanie dowolnych, dużych testów dla programów. Po odpaleniu wczytuje on trzy liczby:
- *n* liczbę generowanych wartości
- *m* docelową medianę
- *s* połowę odległości między górną i dolną medianą (tj, w wynikowym ciągu będą liczby [-max_int;m-s] i [m+s;max_int]
- *c* ilość zapytań o medianę (tj literek m w teście). Jeśli c>0 to zawsze m jest na końcu ciągu, pozostałe c-1 jest rozłożone losowo w ciąggu wartości.
Przykładowe użycie:
```
echo "1000000000 42 17231 30" | ./test_generator >./testcase_0
```

## Analiza złożoności algorytmów
Każdy z przedstawionych algorytmów ma swoje zalety i jest dobry do pewnych zastosowań. Przedstawię więc czemu dokładnie wybrałem takie trzy implementacje.

### ArrayMedianCalculator
Jest to najprostsze rozwiązanie, istny brute-force. Wstawienie każdej nowej liczby może zająć nawet O(n) operacji, także jest absolutnie beznadziejny dla dużych wartości n. Niemniej jednak jest prosty w implementacji i nie zawiera nic bardziej skomplikowanego niż wyszukiwanie binarne.
Podawanie mediany dla posortowanej tablicy odbywa się w czasie O(1), sumaryczna złożoność dla n elementów i k zapytań wynosi:

*O(n² + k)*

### MagicFivesCalculator
Klasyczny algorytm do obliczania mediany. Niestety trudno jest go dostosować do wykorzystwania poprzednich obliczeń, także w tym programie zaimplementowany jest w klasyczny sposób. Jego plusem jest dokładanie elementów w czasie O(1) - minusem obliczanie mediany w czasie O(n). Dlatego sumaryczna złożoność:

*O(n + n\*k)*

sprawia, że jest interesujący tylko gdy bardzo mało razy zapytujemy o medianę.

### HeapMedianCalculator
Chyba najciekawszy z zaimplementowanych tu algorytmów. Zauważamy, że tak naprawdę nie musimy znać kolejności wszystkich liczb by umieć podawać medianę, wystarczy śledzić po której stronie aktualnej mediany dokładamy nową liczbę i ewentualnie przerzucać liczby z jednej części do drugiej gdy mediana się "przesuwa". Szczęśliwie to da się zrealizować dużo szybciej za pomocą kolejek priorytetowych. Takie właśnie rozwiązanie, oparte na kolejkach priorytetowych w postaci kopców binarnych jest zaimplementowane w HeapMedianCalculator. Podanie mediany odbywa się w czasie stałym, natomiast dodanie każdego nowego elementu może zajmować O(log(n)). Ostateczna złożoność przybiera więc postać:

*O(n\*log(n)+k)*
