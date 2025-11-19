#  C++ Software Testing – GoogleTest (T1–T5)
 - Ky projekt përmban detyrat T1–T5 të lëndës **Testim Softuerik**, të implementuara në C++ dhe të testuara duke përdorur **GoogleTest (GTest)**.
 - Projekti demonstron testim njësi (unit testing), teste të parametrizuara, teste me fixture dhe mbulim të rasteve pozitive, negative dhe kufitare.

##  Përmbajtja
 - Projekti është i organizuar në dy direktoriume kryesore:
###  MyFunctions/
 - Përmban implementimet e funksioneve:
    - T1 – IsValidEmail  
    - T2 – CalculateShipping  
    - T3 – ContainsBadWords  
    - T4 – PassedExam  
    - T5 – IsStrongPassword  
###  MyFunctionsTests/
 - Përmban testet për secilën detyrë duke përdorur:
    - `TEST()`  
    - `EXPECT_TRUE`, `EXPECT_FALSE`, `EXPECT_NEAR`  
    - `EXPECT_THROW`  
    - `TEST_F` (fixture tests)  
    - `TEST_P` dhe `INSTANTIATE_TEST_CASE_P` (parameterized tests)  

##  Detajet e Detyrave

###  **T1 – IsValidEmail**
 - Implementon kontrollimin e një email-i valid sipas kushteve:
    - duhet të përmbajë '@'
    - të ketë të paktën një karakter para '@'
    - të ketë një pikë '.' pas '@'
    - domain-i të jetë ≥ 2 karaktere  
 - Testet mbulojnë raste valide dhe invalide, përfshirë mungesë të '@', mungesë të domain-it dhe raste kufitare.

###  **T2 – CalculateShipping**
 - Funksioni llogarit çmimin e transportit sipas:
    - peshës (p.sh. small/medium/large)
    - opsionit express
    - parametrave të varur nga N (baseSmall, baseMedium, baseLarge, expressFactor)  
 - Testet përdorin `EXPECT_NEAR` për krahasime double dhe përfshijnë raste:
    - peshë zero
    - peshë e vogël/mesme/e madhe
    - express dhe jo-express
    - vlera negative (exception)  
 - Përfshin edhe **BONUS** – tabela me teste të parametrizuara (TEST_P).

###  **T3 – ContainsBadWords**
 - Funksioni kontrollon nëse teksti përmban fjalë të ndaluara:
    - "idiot"
    - "stupid"
    - një fjalë të tretë varësisht nga N (hate/noob/trash)  
 - Kontrolli është **case-insensitive**.  
 - Testet përfshijnë:
    - tekst pa fjalë të këqija
    - tekste me secilën fjalë të ndaluar
    - tekst bosh
    - raste me ndryshim shkronjash  
 - BONUS-i përdor **TEST_F fixture** për të ripërdorur tekstet në shumë teste.

###  **T4 – PassedExam**
 - Funksioni kontrollon nëse një student ka kaluar provimin.  
 - Rregullat:
    - pikët vlejnë vetëm në intervalin **[0,100]**
    - jashtë këtij intervali → `invalid_argument`
    - kufiri i kalimit është:  
     - nëse points > passLimit → kalon  
 - Testet përfshijnë:
    - pikë nën kufi  
    - pikë fiks në kufi  
    - pikë mbi kufi  
    - 0 dhe 100 pikë  
    - raste jashtë intervalit (exception)  
 - Përfshin edhe **BONUS TEST_P** me një tabelë pikësh.

###  **T5 – IsStrongPassword**
 - Kushtet varen nga N:
    - minLength = `6 + (N % 5)`  
    - nëse N është **tek**, kërkohet:
    - të paktën 1 shkronjë e madhe
    - të paktën 1 shifër
    - të paktën 1 karakter special (!@#$%)  
 - Testet mbulojnë:
    - password valid
    - shumë i shkurtër
    - mungon uppercase
    - mungon digit
    - mungon simboli special
    - kombinime me shumë kushte të thyera  
 - BONUS-i: **parameterized tests** me tabela passwords.

##  Tech Stack
  - C++17  
  - GoogleTest (GTest)  
  - Visual Studio 2022  
  - Git & GitHub  

##  Si të ekzekutohen testet
1. Hap projektin në Visual Studio  
2. Hyr te:
3. Ndërto projektin:
4. Ekzekuto të gjitha testet:
5. Rezultatet shfaqen në Test Explorer:
      - jeshile → testet kalojnë  
      - të kuqe → testet dështojnë  
      - exception → shfaq detajet e gabimit  

##  Autorja
- Studente: Elsa Krasniqi , N = 89
 - FIEK – Inxhinieri Kompjuterike dhe Softuerike  
 - Lënda: Testim Softueri
