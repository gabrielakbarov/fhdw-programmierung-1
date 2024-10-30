#include <stdio.h>
#include <string.h>

void replaceCharInString(char st[], char a, char b)
{
    for(int i = 0; st[i] != '\0'; i++)
    {
        if(st[i] == a)
            st[i] = b;
    }
}

void copyString(char von[], char nach[])
{
    for(int i = 0; von[i] != '\0'; i++)
    {
        nach[i] = von[i];
    }
    nach[strlen(von)] = '\0';
}

void swapString(char a[], char b[])
{
    char temp;
    for(int i = 0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int isPalindrom(char st[])
{
    int length = strlen(st);
    for(int i = 0; i < length / 2; i++)
    {
        if(st[i] != st[length - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

struct product
{
    char name[100];
    int id;
    int amount;
    int price;
};

void setName(struct product* prod, char st[])
{
    copyString(prod->name, st);
    prod->name[sizeof(prod->name) - 1] = '\0';
}

void setId(struct product* prod, int pId)
{
    prod->id = pId;
}

void setAmount(struct product* prod, int pAmount)
{
    prod->amount = pAmount;
}

void setPrice(struct product* prod, int pPrice)
{
    prod->price = pPrice;
}

char* getName(struct product* prod)
{
    return prod->name;
}

int getId(struct product* prod)
{
    return prod->id;
}

int getAmount(struct product* prod)
{
    return prod->amount;
}

int getPrice(struct product* prod)
{
    return prod->price;
}

void display(struct product* prod)
{
    printf("-----------------------------\n");
    printf("Produktdetails:\n");
    printf("Name   : %s\n", prod->name);
    printf("ID     : %d\n", prod->id);
    printf("Amount : %d\n", prod->amount);
    printf("Price  : %d\n", prod->price);
    printf("-----------------------------\n\n");
}

void copyProduct(struct product* dest, struct product* src)
{
    setName(dest, src->name);
    setId(dest, src->id);
    setAmount(dest, src->amount);
    setPrice(dest, src->price);
}

void swapProduct(struct product* a, struct product* b)
{
    struct product temp = *a;
    *a = *b;
    *b = temp;
}

struct product prod1, prod2, prod3, prod4, prod5;
struct product* prods[] = {&prod1, &prod2, &prod3, &prod4, &prod5};

void setThreeProds()
{
    for(int i = 0; i < 3; i++)
    {
        setName(prods[i], "Produkt");
        setId(prods[i], i + 1);
        setAmount(prods[i], i + 1);
        setPrice(prods[i], (i + 1) * 10);
        display(prods[i]);
    }
}

void displayProds()
{
    printf("Alle Produkte:\n\n");
    for(int i = 0; i < 5; i++)
    {
        display(prods[i]);
    }
}

void moveProds()
{
    struct product* temp = prods[4];
    for(int i = 4; i > 0; i--)
    {
        prods[i] = prods[i - 1];
    }
    prods[0] = temp;
}

int main()
{
    printf("Setze die ersten 3 Produkte:\n");
    setThreeProds();

    printf("Anzeigen aller Produkte:\n");
    displayProds();

    printf("Nach dem Verschieben:\n");
    moveProds();
    displayProds();

    return 0;
}
