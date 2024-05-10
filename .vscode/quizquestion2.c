//all of this is your stuff that sets us up with a bank for each scale
#include <stdio.h>

typedef enum Mode {
    Ionian, Dorian, Phrygian
} Mode;

typedef struct Note {
    unsigned char pitch;
    unsigned char velocity;
    unsigned char channel;
} Note;

typedef struct Scale {
    Note notes[7];
    unsigned char rootNote;
} Scale;

int main() {
    Scale ionian = {{
        {0, 127, 1},
        {2, 127, 1},
        {4, 127, 1},
        {5, 127, 1},
        {7, 127, 1},
        {9, 127, 1},
        {11, 127, 1}
    }, 60};
    
    Scale dorian = {{
        {0, 127, 1},
        {2, 127, 1},
        {3, 127, 1},
        {5, 127, 1},
        {7, 127, 1},
        {9, 127, 1},
        {10, 127, 1}
    }, 60};
    
    Scale phrygian = {{
        {0, 127, 1},
        {1, 127, 1},
        {3, 127, 1},
        {5, 127, 1},
        {7, 127, 1},
        {8, 127, 1},
        {10, 127, 1}
    }, 60};
//okay so here I am making an int for modeChoice cause we are gonna need it for someone to call on
    int modeChoice;
    printf("Enter the mode (0 for Ionian, 1 for Dorian, 2 for Phrygian): ");
    //here we scan user input for a double using scanf then pointing it to the int name to change it
    scanf("%d", &modeChoice);
//same idea here just for the root note
    int rootNote;
    printf("Enter the root note (0 ~ 127): ");
    scanf("%d", &rootNote);
//now we are calling on the scale structure that was provided using switch statements
//just makes the most sense with the tools we've learned
    Scale selectedScale;
    switch (modeChoice) {
        case Ionian:
            selectedScale = ionian;
            break;
        case Dorian:
            selectedScale = dorian;
            break;
        case Phrygian:
            selectedScale = phrygian;
            break;
        default:
            printf("Invalid mode choice.\n");
            return 1;
    }

    selectedScale.rootNote = rootNote;
//pretty simply just printing out the scale with seven notes as all scales in this example have. we can deal with pentatonic stuff another day haha
    printf("Pitches in the selected mode:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", selectedScale.notes[i].pitch + selectedScale.rootNote);
    }
    printf("\n");

    return 0;
}