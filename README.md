# online-median
Program służy do obliczania mediany aktualnie wczytanych liczb całkowitych (tj. typu *int*).

## tl;dr
Istotny kod implementacji jest umieszczony w folderze **./src**, wszystkie nagłówki są umieszone w **./include**.
Analiza złożoności zaimplementowanych algorytmów jest dostępna na dole poniższego readme.

## Kompilacja
Po ściągnięciu repozytorium powinno wystarczyć wejście do folderu **./build** i wydanie standardowych komend:
```
cmake ..
make
```

Wszystkie pliki wykonywalne powinny zostać umieszczone w folderze **./bin**
Budowanie było testowane na trzech komputerach z Linuksem, na wszystkich kompilowało się bez problemu. Mam nadzieję, że na Macach też będzie OK :)

## Używanie programu
Głównym plikiem wykonywalnym jest **median_calculator**. Ponieważ z treści zadania nie wywnioskowałem na 100% jak często należy podawać medianę, to program działa w dwóch wersjach. Pierwsza, domyślna, to wypisywanie mediany gdy na wejściu zamiast liczby pojawi się litera "m" (jakoś bardziej mi się to podobało, nie wiem czemu).
Druga wersja to zwracanie mediany po wczytaniu każdej nowej liczby. Program włącza się w tym trybie po dodaniu flagi *-e*.

Samo obliczanie mediany program może realizować na trzy sposoby:
- ArrayMedianCalculator - czyli posortowana tablica do której kolejne elementy dokładane są na odpowiednie miejsca. Uruchamia się go flagą *-a*.
- MagicFivesCalculator - czyli zwykła tablica, do której dopisujemy kolejne elementy na końcu, a kiedy dostajemy zapytanie o medianę uruchamiamy algorytm magicznych piątek (czyli tzw. medianę median). Tę wersję otrzymamy dodając flagę *-f*.
- HeapMedianCalculator - czyli dwa kopce, przechowujące odpowiednio elementy mniejsze i większe od aktualnej mediany. To jest domyślna wersja, nie trzeba dodawać żadnej flagi, ale żeby było symetrycznie możemy dodać flagę *-h*.

## Uruchamianie testów
W już zbudowanym projekcie wystarczy w folderze **./build** wydać polecenie
```
make check
```
by sprawdzić testy jednostkowe. Żeby uruchomić testy wydajnościowe należy w folderze **./bin** uruchomić skrypt:
```
./run_performance_tests.sh
```

## Generowanie własnych testów
Do kompletu w repozytorium załączyłem program **test_generator**, który pozwala na generowanie różnych ciekawych testów dla programu. Po uruchomieniu wczytuje on cztery liczby:
- *n* - liczbę generowanych wartości
- *m* - docelową medianę
- *s* - połowę odległości między górną i dolną medianą, jeśli *n* jest parzyste (tj, w wynikowym ciągu będą liczby [min_int;m-s] i [m+s;max_int]. Dla *n* nieparzystego wartość ta jest ignorowana.
- *c* - liczba zapytań o medianę (tj. liczba literek m w teście). Jeśli *c*>0 to zawsze jedna litera m jest na końcu ciągu, pozostałe *c*-1 jest rozłożone losowo w ciągu wartości.
Przykładowe użycie:
```
echo "1000000000 42 17231 30" | ./test_generator >./testcase_0
```

## Analiza złożoności algorytmów
Każdy z przedstawionych algorytmów ma swoje zalety i jest dobry do pewnych zastosowań. Przedstawię więc czemu dokładnie wybrałem takie trzy implementacje.

### ArrayMedianCalculator
Jest to najprostsze rozwiązanie, istny brute-force. Wstawienie każdej nowej liczby może zająć nawet O(n) operacji, także jest absolutnie beznadziejny dla dużych wartości n. Niemniej jednak jest prosty w implementacji i nie zawiera nic bardziej skomplikowanego niż wyszukiwanie binarne.
Obliczenie mediany dla posortowanej tablicy odbywa się w czasie O(1), sumaryczna złożoność dla n elementów i k zapytań wynosi:

*O(n² + k)*

### MagicFivesCalculator
Klasyczny algorytm do obliczania mediany. Niestety dosyć trudno jest go dostosować do wykorzystwania poprzednich obliczeń, także w tym programie zaimplementowany jest w standardowy sposób. Jego plusem jest dokładanie elementów w czasie O(1) - minusem natomiast obliczanie mediany w czasie O(n). Dlatego sumaryczna złożoność:

*O(n + n\*k)*

sprawia, że jest atrakcyjny tylko wtedy, gdy bardzo mało razy zapytujemy o medianę.

### HeapMedianCalculator
Chyba najciekawszy z zaimplementowanych tu algorytmów. Zauważamy, że tak naprawdę nie musimy znać kolejności wszystkich liczb by umieć podawać medianę, wystarczy śledzić po której stronie aktualnej mediany dokładamy nową liczbę i ewentualnie przerzucać liczby z jednej części do drugiej gdy mediana się "przesuwa". Szczęśliwie da się to zrealizować szybko za pomocą kolejek priorytetowych. Takie właśnie rozwiązanie, oparte na kopcach binarnych jest zaimplementowane w HeapMedianCalculator. Obliczenie mediany odbywa się w czasie stałym, natomiast dodanie każdego nowego elementu może zajmuje *O(log(n))*. Ostateczna złożoność przybiera więc postać:

*O(n\*log(n)+k)*

## Praktyczne testy
Implementacje zostały też poddane praktycznym testom w celu porównania ich wydajności. Otrzymałem następujące wyniki:

### Tryb ciągły podawania mediany
Tu oczywiście MagicFives wypadają fatalnie, bo chociaż mają teoretycznie tą samą złożoność asymptotyczną co wersja z posortowaną tablicą (O(n²)) to stała jest wielokrotnie większa, dodatkowo żonglerka alokacjami pamięci jest ostatecznym gwoździem do jej trumny. Kopce natomiast radzą sobie świetnie i mają najlepsze wyniki we wszystkich testach.
n  | 1.000 | 10.000 | 100.000
---| -----| ------ |
MagicFives | 0,051s | 0m2,425s | 3m57,328s
Array | 0m0,008s | 0m0,063s | 0m0,604s
Heap  | 0m0,008s | 0m0,059s | 0m0,339s

### Tryb pojedynczej mediany
Magiczne piątki odbijają sobie test ciągły i są najszybsze we wszystkich trzech testach.  Po implementacji tablicowej widać, że złożoność kwadratowa i istotnie gorsza od pozostałych dwóch algorytmów.
n  | 1.000 | 100.000| 1.000.000
---| -----| ------ | ---------
MagicFives | 0m0,002s | 0m0,069s | 0m0,496s
Array | 0m0,003s | 0m0,414s | 0m41,086s
Heap | 0m0,003s | 0m0,113s | 0m0,672s

### Tryb wielokrotnej mediany (42 mediany) z dużymi wejściami
Tak jak można się było spodziewać, implementacja kopcowa wypada tu najlepiej. Co ciekawe widać, że magiczne piątki rzeczywiście rosną liniowo dla stałej liczby zapytań o medianę a kopcowa implementacja rośnie nieco szybciej niż liniowo.
n  | 1.000.000 | 10.000.000 | 100.000.000
---| -----| ------
MagicFives | 0m1,443s | 0m12,245s | 2m14,039s
Heap  | 0m0,734s | 0m7,224s | 1m16,121s

### Tryb pojedynczej mediany z dużymi wejściami
Tutaj też bez zaskoczeń, magiczne piątki działają szybciej i ich czas rośnie odrobinę wolniej niż implementacji opartej na kopcach.
n  | 10M | 100M| 1000M
---| -----| ------ | ---------
MagicFives | 0m4,337s | 0m43,492s | 7m15,426s
Heap |  0m7,313s |  1m26,654s | 13m37,211s
