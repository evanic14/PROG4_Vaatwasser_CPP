# PROG4_Vaatwasser_CPP

Op deze pagina staat de code voor de PROG4 programmeer opdracht.
Verder kunt u hier de gebruiksaanwijzing vinden.

## Gebruiksaanwijzing
In dit kopje zal een gebruiksaanwijzing van het gemaakte programma te vinden zijn.
Hier wordt beschreven hoe de gebruiker het programma moet gebruiken. 

### Het starten van een programma

In dit voorbeeld kies wil ik een glas programma starten.
Dit doe ik door op de *RUN* knop te drukken in de ontwikkelomgeving. Dit start de applicatie.

Het programma loopt door de opstart cyclus heen.

Als alle systemen opgestart zijn wordt er automatisch overgeschakeld naar het volgende scherm. Hier kan de gebruiker een programma kiezen. 
De selectiebox heeft het *Select Program* programma standaard geselecteerd.
Dit programma heeft geen uitvoerende taak. Als de gebruiker deze optie kiest, zal hij teruggeleid worden naar het selectiemenu zonder dat er een taak uitgevoerd wordt.
De gebruiker kan uit drie programma's kiezen. Deze zijn:

| **Nummer:** | **Programma:** |
| :---        | :---           |
| 1           | Glass          |
| 2           | Ceramic        |
| 3           | Eco            |

Als de gebruiker een programma geselecteerd heeft moet de gebruiker zijn keuze bevestigen door op de *Ok* knop te drukken.

:exclamation:
Het kan natuurlijk zijn dat de gebruiker zijn keuze wilt wijzigen. Dit kan door in het menu op de *Return* knop te drukken.
:exclamation:

Als de gebruiker een programma keuze gemaakt heeft wordt het volgende programma tijd selectie menu geladen. De gebruiker heeft hier een aantal keuzes:

| **Nummmer:** | **Tijd:**             |
| :---         | :---                  |
| 1            | 60 minutes            |
| 2            | 10 minutes            |
| 3            |  5 minutes            |

De gebruiker heeft de keuze uit drie knoppen. Iedere keer dat de gebruiker op een knop drukt, zal de tijd die bij de desbetreffende knop hoort bij de programmatijd (standaard 0 minuten) worden opgeteld. 
De actuele programmatijd wordt op het LCD-display weergeven. 

Als de gebruiker de gewenste tijd heeft geselecteerd, kan hij het programma starten door op de *Ok* knop te drukken.
Het programma zal dan net zo lang als de ingevoerde tijd duren (ingevoerde tijd * 100 = wachttijd in ms).  

:exclamation:
Het kan natuurlijk zijn dat de gebruiker het programma niet meer wilt starten omdat bijvoorbeeld de ingevoerde tijd niet juist is.
Hiervoor kan de gebruiker de *Return* knop indrukken.
Het programma keuzemenu zal opnieuw geladen worden.
:exclamation:

Als de gewenste tijd geselecteerd is zal het programma starten.
Dit krijgt de gebruiker ook op het display te zien.
Iedere keer dat er een programma gestart wordt, wordt het waspoeder niveau met 10 verlaagd.

:exclamation:
Het standaard poederniveau is 100.
:exclamation:

Als het was poeder op is wordt powderErr op 1 gezet waarna het programma wordt afgesloten.

## Debugging
Alle acties die het systeem uitvoert worden in een *debug.txt* bestand opgeslagen met de bijhorende tijd.
Dit bestand kan in de build map van de code gevonden worden. 
