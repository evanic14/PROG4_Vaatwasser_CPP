# PROG4_Vaatwasser_CPP

Op deze pagina staat de code voor de PROG2 programmeer opdracht.
Verder kunt u hier de gebruiksaanwijzing vinden.

## Gebruiksaanwijzing

Er zijn een aantal mogelijke keuzes om door het programma heen te lopen. Om dit te visualizeren heb ik een stroom tabel gemaakt.

![keuzediagram vaatwasser](https://user-images.githubusercontent.com/44370997/212329582-61c9be80-fb3f-4a0f-b3db-4b7d4f86aaa1.jpg)

[stroom tabel vaatwasser programma](https://github.com/evanic14/PROG2_Vaatwasser/blob/master/Images/keuzediagram%20vaatwasser.jpg?raw=true)

### Het starten van een programma

In dit voorbeeld kies wil ik een glas programma starten.
Dit doe ik door op de *RUN* knop te drukken in de ontwikkel omgeving. Dit start de aplicatie.

Het programma loopt door de opstart cyclus heen. Door op *ENTER* te drukken wordt het volgende systeem gecheckt. Mocht er ergens een fout in het opstarten zitten dan sluit het systeem zichzelf af.

Als alle systemen opgestart zijn wordt er overgeschakeld naar het volgende scherm. Hier kan de gebruiker een programma kiezen door de volgende gegevens in te voeren.

| **In te voeren nummer:** | **Programma:** |
| :---                     | :---           |
| 1                        | Glass          |
| 2                        | Ceramic        |
| 3                        | Eco            |

Als de gebruiker een nummer ingevoerd heeft moet de gebruiker zijn keuze bevestigen door op de *ENTER* toets te drukken.

:exclamation:
Het kan natuurlijk zijn dat de gebruiker zijn keuze wilt wijzigen. Dit kan door in het menu op de *C* toets te drukken. Als de gebruiker vervolgens op de *ENTER* toets drukt wordt het programma keuzemenu opnieuw geladen.
:exclamation:

Als de gebruiker een programma keuze gemaakt heeft wordt het volgende scherm geladen. Het selectie scherm voor de tijd. De gebruiker heeft hier een aantal keuzes.

| **In te voeren nummmer:** | **Programma:**        |
| :---                      | :---                  |
| 1                         | 60 minuten            |
| 2                         | 10 minuten            |
| 3                         |  5 minuten            |
|                                                   |
| 4                         | 60 minuten + meer     |
| 5                         | 10 minuten + meer     |
| 6                         |  5 minuten + meer     |

De gebruiker heeft zes keuzes. Nummer 1 tot 3 laden het volgende programma. Nummer 4 tot 6 doen hetzelfde als nummer 1 tot 3 maar het tijd keuzemenu wordt opnieuw geladen, waardoor de gebruiker meer tijd kan toevoegen. Als de gewenste tijd is ingevoerd kan er op de *ENTER* toets gedrukt.

:exclamation:
Het kan natuurlijk zijn dat de gebruiker het programma om wat voor reden dan ook niet meer wilt starten. Hiervoor kan de *C* toets gevolgd door de op *ENTER* toets ingedrukt worden.
Het programma keuzemenu zal opnieuw geladen worden.
:exclamation:

Als de gewenste tijd geselecteerd is zal het programma starten. Dit krijgt de gebruiker ook op het display te zien. Iedere keer dat er een programma gestart wordt, wordt het waspoeder niveau met 10 verlaagd.

:exclamation:
Het standaard poederniveau is 100.
:exclamation:

Als het was poeder op is wordt powderErr op 1 gezet waarna het programma wordt afgesloten.

:exclamation:
De gebruiker moet op *ENTER* drukken om door het volgende tekstveld te laden.
:exclamation:
