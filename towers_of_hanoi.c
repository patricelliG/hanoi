// This program emulates and solves the classic towers of hanoi problem using recursion

#include <stdio.h>
#include <string.h>
#include "stack.c"


struct Towers
{

    // Define the three towers
    struct Stack a;
    struct Stack b;
    struct Stack c;

    // Number of moves
    int moves;
};

// Simple helper function that prints disks with formatting
void print_disk(int disk)
{
    if(disk == -1)
    {
        // this is an empty spot
        printf("\t ");
    }
    else
    {
        // This is actually a disk
        printf("\t%i", disk);
    }
}

void print_towers(struct Towers *t)
{
    int i = STACK_SIZE - 1;
    for(i; i >= 0; i--)
    {
        // Translate the characters
        int int_a = index_peek(t->a, i); 
        int int_b = index_peek(t->b, i); 
        int int_c = index_peek(t->c, i); 

        // Print each row of the towers starting from the top
        print_disk(int_a);
        print_disk(int_b);
        print_disk(int_c);
        printf("\n");

    }
    printf("\t-----------------\n");
    printf("\tA\tB\tC\n");
    printf("\n\n\n\n\n");
}

void move_disk(struct Stack *source, struct Stack *dest, struct Towers *t)
{
    // Add error checking here for placement
    push(dest, pop(source));
    // Print instructions and visual representation
    printf("Move the top disk from %s to %s\n", source->name, dest->name); 
    t->moves++;
    print_towers(t);
}

// Caution, recursion ahead!
void move_tower(int n, struct Towers *t, struct Stack *source, struct Stack *dest, struct Stack *temp)
{
    if(n == 1)
    {
        move_disk(source, dest, t);
    }
    else
    {
        move_tower(n-1, t, source, temp, dest);
        move_disk(source, dest, t);
        move_tower(n-1, t, temp, dest, source);
    }

}

// Initialize towers with n rings
struct Towers initialize_towers(int n)
{
    struct Towers t = {{.top=-1},{.top=-1},{.top=-1}};
    // Name the towers
    strcpy(t.a.name, "Tower A");
    strcpy(t.b.name, "Tower B");
    strcpy(t.c.name, "Tower C");
    
    // Put the rings on Tower A
    int i = n;
    for(i; i > 0; i--)
    {
        push(&t.a, i);
    }

    printf("\nStarting position with %i rings...", n);
    print_towers(&t);
   
    t.moves = 0;
    return t;
}


int main(char *argv[], int argc)
{
    printf("Please enter the number of rings...\n>");
    int n = 0;
    scanf("%i", &n);
    //n = 2;
    struct Towers t = initialize_towers(n);
    move_tower(n, &t, &t.a, &t.c, &t.b);
    printf("Completed in %i moves!",t.moves); 
}
