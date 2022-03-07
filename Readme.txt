Nume: Carp Constantin
Grupa: 336CC

# Tema <2> ASC

Cerința: Să se implementeze operația ” A * B * Bt + At * A” unde A este o matrice superior
            triunghiulară, cu diverse optimizări și să se compare performanțele.

## Optimizările generale ale algoritmului de înmulțire
    Dat fiind faptul că matricea ”A” este superior triunghiulară indicii după care se efectuiază 
    parcurgerea sunt diferiți pentru a evita operații inutile precum înmulțirea cu ”0”. Aceste 
    optimizări au fost aplicate atât la varianta neoptimizată cât și optimizată.

### AB * Bt , At * A
    Pentru a evita operații inutile, nu avea sensul să facem transpusa lui ”B” și respectiv ”A”,
    este suficient să efectuăm o parcurgere pe linie a acestor matrici.


## Varianta neoptimizată
    Ține cont doar de faptul că matricea ”A” este superior triunghiulară.

-----------------------------------------
Run=./tema2_neopt: N=400: Time=1.133362
Run=./tema2_neopt: N=800: Time=8.917061
Run=./tema2_neopt: N=1000: Time=16.927197
Run=./tema2_neopt: N=1200: Time=29.462433
Run=./tema2_neopt: N=1600: Time=80.234795
-----------------------------------------

## Varianta optimizată
    Folosește registrii procesorului pentru a stoca suma și variabilele de iterație.

-----------------------------------------
Run=./tema2_opt_m: N=400: Time=0.449353
Run=./tema2_opt_m: N=800: Time=3.413280
Run=./tema2_opt_m: N=1000: Time=6.225014
Run=./tema2_opt_m: N=1200: Time=10.962348
Run=./tema2_opt_m: N=1600: Time=31.027210
<<< Bonus=0p >>>
-----------------------------------------

## Varianta blas
    Cea mai optimizată varianta cu cei mai buni timpi de execuție,
    datorită optimizărilor care le face în spate. Am folosit funcțiile dtrmm și dgemm 
    pentru înmulțirea cu o matrice superior triunghiulară și respectiv înmulțirea cu o matrice
    simplă și efectuarea sumei.

-----------------------------------------
Run=./tema2_blas: N=400: Time=0.058212
Run=./tema2_blas: N=800: Time=0.276183
Run=./tema2_blas: N=1000: Time=0.496470
Run=./tema2_blas: N=1200: Time=0.885098
Run=./tema2_blas: N=1600: Time=1.993602
-----------------------------------------

Ps: este o versiune performantă dar și mai dificilă de înțeles cu materialele puse
    la îndemână, luând în considerație că nu am făcut la laborator și nici pe internet nu prea
    există exemple, a fost cam dificil.

## Graficul
    A fost creat cu ajutorul unui tool online pe baza datelor optinule la rularea pe coadă ibm.
    https://www.onlinecharttool.com/graph?selected_graph=line


## Concluzii
    Analizând graficele este ușor vizibil creșterea rapidă a timpului de execuție
    pentru varianta neoptimzată, varianta optimizată având o creștere mai moderată,
    iar varianta blas menținând o creștere aproape liniară ceea ce este fascinant.

    Varianta opt_m este cu 62% mai rapida decat cea neoptimizată.
    Varianta blas este cu 97% mai rapida decat cea neoptimizată si cu 92% decat cea optimizată
    
## Cachegrind
    Prima parte a ieșirii cachegrind raportează informații despre memoria instrucțiunilor cache-ului de nivel L1.
    În toate exemplele, numărul de rate de instrucțiuni L1 ratate este nesemnificativ, rata de ratare este întotdeauna 0%.
    Înseamnă că toate programele se încadrează în memoria cache a instrucțiunilor cache-ului de nivel L1.

    Varianta cea mai "cache friendly/efficeint" este versiunea blas avand o rata de miss D1 ~ 1.9% mai mica.
    Dar si din punct de vedere ar numarului de accesare a memoriei care este considerabil mai mic decat a celorlalte versiuni
    blas ~ 3,926,049 <  restul ~ 131,736,755

## Resurse
    https://www.onlinecharttool.com/graph?selected_graph=line
    https://ocw.cs.pub.ro/courses/asc/teme/tema2
    https://matrixcalc.org/ro/
    https://www.gnu.org/software/gsl/doc/html/blas.html
    https://developer.apple.com/documentation/accelerate/1513282-cblas_dgemm?language=objc