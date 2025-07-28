#include <iostream>
#include <conio.h>  // For _getch()
#include <cstdlib>  // For system("cls")

using namespace std;

// Node structure for 4D linked list
struct Node {
    char data;         // Character data
    Node* up;          // Link to previous line
    Node* down;        // Link to next line
    Node* left;        // Link to previous character in the same line
    Node* right;       // Link to next character in the same line

    // Constructor to initialize the node
    Node(char c) : data(c), up(NULL), down(NULL), left(NULL), right(NULL) {}
};

// Notepad class to manage the 4D linked list
class Notepad {
private:
    Node* head;           // Head of the text
    Node* currentLine;    // Current line in the text
    Node* currentChar;    // Current character in the line
    int cursorPos;        // Track horizontal position of the cursor for up and down movement

    char lastDeletedChar; // Store the last deleted character
    Node* lastDeletedNode; // Store the node where the character was deleted from
    bool isLastDeleted; // Flag to check if the last operation was a delete

public:
    Notepad() {
        head = NULL;
        currentLine = NULL;
        currentChar = NULL;
        cursorPos = 0;
        lastDeletedChar = ' ';  // Initialize with empty space
        lastDeletedNode = NULL;
        isLastDeleted = false;
    }

    // Initialize the notepad with a single empty node
    void initNotepad() {
        Node* newNode = new Node(' '); // Start with a blank node
        head = newNode;
        currentLine = newNode; 
        currentChar = newNode;
    }

    // Function to insert a character
    void insertCharacter(char c) {
        Node* newNode = new Node(c);
        newNode->up = currentLine->up;
        newNode->down = currentLine->down;
        newNode->left = currentChar;
        newNode->right = currentChar->right;

        if (currentChar->right) {
            currentChar->right->left = newNode; // Link the right neighbor
        }
        currentChar->right = newNode;  // Link currentChar to the new node
        currentChar = newNode;         // Move to the new node
        cursorPos++;                   // Move cursor right

        isLastDeleted = false;         // Reset delete flag after insert
    }

    // Function to delete a character
    void deleteCharacter() {
        if (currentChar && currentChar->left) {  // If not at the start of the line
            lastDeletedChar = currentChar->data;  // Save the deleted character
            lastDeletedNode = currentChar;        // Save the node from where it's deleted

            Node* temp = currentChar;
            currentChar = currentChar->left;
            currentChar->right = temp->right;  // Skip over the node to be deleted

            if (temp->right) {
                temp->right->left = currentChar;  // Maintain left link of the next node
            }
            delete temp;
            cursorPos--; // Update the cursor position

            isLastDeleted = true;  // Mark the last operation as delete
        }
    }

    // Function to undo the last operation (insert or delete)
    void undo() {
        if (isLastDeleted) {
            // If last operation was delete, restore the character
            Node* undoNode = new Node(lastDeletedChar);
            undoNode->up = currentLine->up;
            undoNode->down = currentLine->down;
            undoNode->left = currentChar->left;
            undoNode->right = currentChar;

            if (currentChar->left) {
                currentChar->left->right = undoNode;  // Link left neighbor
            }
            currentChar->left = undoNode;  // Link the new node
            currentChar = undoNode;        // Move to the new node
            cursorPos++;                   // Move cursor right after restore
            isLastDeleted = false;         // Reset delete flag
        } else {
            // If last operation was insert, undo it by deleting the last inserted character
            if (currentChar) {
                Node* temp = currentChar;
                currentChar = currentChar->left;  // Move left
                currentChar->right = temp->right; // Remove reference to the inserted character

                if (temp->right) {
                    temp->right->left = currentChar;  // Maintain right link of the next node
                }
                delete temp;
                cursorPos--; // Update the cursor position
            }
        }
    }

    // Function to handle the Enter key and create a new line
    void insertNewLine() {
        Node* newLine = new Node(' '); // Create a new blank node for the new line
        newLine->up = currentLine;
        newLine->down = currentLine->down;

        if (currentLine->down) {
            currentLine->down->up = newLine;  // Link the current line down pointer
        }
        currentLine->down = newLine; // Link the current line to the new line
        currentLine = newLine;       // Move to the new line
        currentChar = newLine;       // Move to the start of the new line
        cursorPos = 0;               // Reset cursor position
    }

    // Function to display the notepad content
    void display() {
        Node* tempLine = head;
        while (tempLine != NULL) {
            Node* tempChar = tempLine;
            while (tempChar != NULL) {
                cout << tempChar->data; // Display character
                tempChar = tempChar->right;
            }
            cout << endl;
            tempLine = tempLine->down;
        }
        cout << endl;
    }

    // Function to handle user input from console
    void handleInput() {
        while (true) {
            int input = _getch(); // Get a single character input from user

            if (input == 27) { // Escape key to exit
                break;
            } else if (input == 224) { // Arrow keys (Windows specific extended key codes)
                input = _getch(); // Get the actual arrow key
                if (input == 72) { // Up arrow
                    moveUp();
                } else if (input == 80) { // Down arrow
                    moveDown();
                } else if (input == 75) { // Left arrow
                    moveLeft();
                } else if (input == 77) { // Right arrow
                    moveRight();
                }
            } else if (input == 8) { // Backspace key to delete character
                deleteCharacter();
            } else if (input == 13) { // Enter key to create a new line
                insertNewLine();
            } else if (input == 90) { // 'Z' for undo
                undo();
            } else { // Any other key, insert the character
                insertCharacter(input);
            }

            system("cls"); // Clear the console window
            display();     // Display the updated content
        }
    }

private:
    // Cursor movement functions (left, right, up, down)
    void moveUp() {
        if (currentLine && currentLine->up) {
            currentLine = currentLine->up;
            currentChar = currentLine;
            cursorPos = 0;
            while (currentChar->right) {
                currentChar = currentChar->right;
                cursorPos++;
            }
        }
    }

    void moveDown() {
        if (currentLine && currentLine->down) {
            currentLine = currentLine->down;
            currentChar = currentLine;
            cursorPos = 0;
            while (currentChar->right) {
                currentChar = currentChar->right;
                cursorPos++;
            }
        }
    }

    void moveLeft() {
        if (currentChar && currentChar->left) {
            currentChar = currentChar->left;
            cursorPos--;
        }
    }

    void moveRight() {
        if (currentChar && currentChar->right) {
            currentChar = currentChar->right;
            cursorPos++;
        }
    }
};

int main() {
    Notepad notepad;

    notepad.initNotepad(); // Initialize notepad

    cout << "Simple Notepad (Press ESC to exit)\n";
    notepad.display(); // Display initial content

    notepad.handleInput(); // Start taking user input

    return 0;
}