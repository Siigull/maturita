#include <stdio.h>

#define maxRad 10

//načti ze vstupu stupeň a koeficienty polynomu, dále načti hodnotu x a vypočítej 
//Hornerovým schématem hodnotu polynomu v daném bodě
float horner(float polynom[maxRad], int n, int x){
    int res = polynom[0];
    for(int i=1; i<n; i++)
        res = res*x + polynom[i];
    return res;
}

void nactiPolynom(float polynom[maxRad], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &polynom[i]);
    }
    int x;
    scanf("%d", &x);
    float vysledek = horner(polynom, n, x);
}

//čti ze vstupu řadu číselných hodnot předem neznámé délky (až do konce vstupu
//– EOF) a vypiš posledních N hodnot, součet posledních N hodnot, vypiš po-
//sledních N hodnot v opačném pořadí
#define N 5
void radaCisel(){
    int c, pole[N];
    int i = 0;
    while (scanf("%d", &c)){
        pole[i] = c;
        i++; i%=N;
    }
    int soucet = pole[i];
    //postupne
    printf("%d ", pole[i]);
    for(int j=i+1; j!=i; j++){
        if(j==N) j = 0;
        soucet += pole[j];
        printf("%d ", pole[j]);
    }
    //součet
    printf("\n%d \n", soucet);
    //naopak
    for(int j=i-1; j!=i; j--){
        if(j==-1) j = N-1;
        printf("%d ", pole[j]);
    }
    printf("%d ", pole[i]);

}

//čti vstup neznámé délky po znacích a vrať pole reprezentující histogram, poté
//z něj vypiš absolutní četnosti malých znaků anglické abecedy (počty znaků na vstupu)
void histogram(){
    char c, vysledky[26];
    while (scanf("%c\n", &c)){
        c -= 97;
        if(c >= 0 && c < 26) vysledky[c]++;
    }
    for(int i=0; i<26; i++) printf("%d ", vysledky[i]);
}

//Vytvoř funkci realizující textovou nabídku, která bude vracet znaky A, B, K,
//X s významem A – Volba A, B – Volba B, K – Konec, X – Neznámá volba (bude to
//vracet při neočekávané volbě). Použij ji pro komunikaci s uživatelem dokud ne-
//zvolí ukončení programu.
void textovaNabidka(){
    char userInput;
    printf("Zadej volbu: ");
    while (1){
        userInput = getc(stdin);
        getc(stdin);
        switch(userInput){
            case 'A':
                printf("A");
                break;
            case 'B':
                printf("B");
                break;
            case 'X':
                printf("konec");
                return;
            default:
                printf("neznama volba");
                break;
        }
        printf("\nZadej volbu: ");
    }
}

int main(){
    textovaNabidka();
    return 0;
}