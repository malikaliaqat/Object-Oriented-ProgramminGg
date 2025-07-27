#include <iostream>
#include <list>
#include <queue>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

// Tree Node Structure for Maze
struct TreeNode {
    char value;          // ' ' for empty, 'K' for key, 'B' for bomb
    list<TreeNode*> children;
    TreeNode* parent;
    int x, y;  // Position in the maze

    TreeNode(char val, int xPos, int yPos) : value(val), x(xPos), y(yPos), parent(NULL) {}
};

// Linked List Node for Bombs
struct BombNode {
    int x, y;
    int timer;
    BombNode* next;

    BombNode(int x, int y, int timer) : x(x), y(y), timer(timer), next(NULL) {}
};

// Function Prototype
void displayMaze(TreeNode* root, int playerX, int playerY, int keysFound, int gemsRemaining, class BombList& bombList, int bombCount);
TreeNode* findKeyNode(TreeNode* root, int x, int y);

// Function to Create Maze
TreeNode* createMaze() {
    TreeNode* root = new TreeNode(' ', 0, 0);

    // Adding paths and keys at fixed locations
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i != 0 || j != 0) {
                root->children.push_back(new TreeNode(' ', i, j));  // Add empty spaces as nodes
            }
        }
    }

    // Keys placed at (2, 3) and (4, 1)
    root->children.push_back(new TreeNode('K', 2, 3));  // Key at (2, 3)
    root->children.push_back(new TreeNode('K', 4, 1));  // Key at (4, 1)

    return root;
}

// Linked List to Handle Bomb Placement
class BombList {
public:
    BombNode* head;
    BombList() : head(NULL) {}

    void placeBomb(int x, int y, int timer) {
        BombNode* newBomb = new BombNode(x, y, timer);
        newBomb->next = head;
        head = newBomb;
    }

    void updateBombs(int& keysFound, TreeNode* maze, int& bombCount) {
        BombNode* current = head;
        BombNode* prev = NULL;

        while (current) {
            current->timer--;

            if (current->timer <= 0) {
                cout << "* Bomb at (" << current->x << ", " << current->y << ") exploded!" << endl;

                // Check if there is a key at the bomb's position
                TreeNode* keyNode = findKeyNode(maze, current->x, current->y);
                if (keyNode && keyNode->value == 'K') {
                    // Collect the key and remove it
                    keyNode->value = ' '; // Empty the spot where the key was
                    keysFound++; // Increment keys found
                    cout << "Key collected at bomb location!" << endl;
                } else {
                    bombCount--; // Decrease bomb count if no key was found
                }

                // Remove the bomb from the list
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                BombNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    bool isBombAt(int x, int y) {
        BombNode* current = head;
        while (current) {
            if (current->x == x && current->y == y) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// Function to set cursor position
void setCursorPosition(int x, int y) {
    COORD coord = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to find key node at specific position
TreeNode* findKeyNode(TreeNode* root, int x, int y) {
    if (!root) return NULL;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode* current = nodes.front();
        nodes.pop();
        if (current->x == x && current->y == y) {
            return current;
        }
        // Use an iterator to access the children list in C++98
        for (list<TreeNode*>::iterator it = current->children.begin(); it != current->children.end(); ++it) {
            nodes.push(*it);
        }
    }
    return NULL;
}

// Function to display the maze
void displayMaze(TreeNode* root, int playerX, int playerY, int keysFound, int gemsRemaining, BombList& bombList, int bombCount) {
    system("cls");
    cout << "Keys Found: " << keysFound << "/2\n";
    cout << "Gems Remaining: " << gemsRemaining << "/1\n";
    cout << "Bombs Left: " << bombCount << "/8\n";
    cout << "===========================\n";

    // Loop to display the maze grid
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (x == playerX && y == playerY) {
                cout << " P ";  // Player position
            } else if (bombList.isBombAt(x, y)) {
                cout << " B ";  // Bomb position
            } else {
                // Check if there's a key at this position
                TreeNode* keyNode = findKeyNode(root, x, y);
                if (keyNode && keyNode->value == 'K') {
                    cout << " K ";  // Key position
                } else {
                    cout << " _ ";  // Empty path
                }
            }
        }
        cout << endl;
    }
    cout << "===========================\n";
}

// Function to handle player movement
void movePlayer(char direction, int& playerX, int& playerY) {
    if (direction == 'w') playerY = max(0, playerY - 1);
    if (direction == 's') playerY = min(4, playerY + 1);
    if (direction == 'a') playerX = max(0, playerX - 1);
    if (direction == 'd') playerX = min(4, playerX + 1);
}

// Main Function
int main() {
    TreeNode* maze = createMaze();
    BombList bombList;
    int playerX = 0, playerY = 0;
    int keysFound = 0, gemsRemaining = 1;
    int bombCount = 8; // Updated to 8 bombs

    while (bombCount > 0 && keysFound < 2) {
        displayMaze(maze, playerX, playerY, keysFound, gemsRemaining, bombList, bombCount);
        bombList.updateBombs(keysFound, maze, bombCount);
        cout << "Use WASD to move, B to place a bomb, Q to quit: ";
        char input = _getch();

        if (input == 'q') break;
        if (input == 'b' && bombCount > 0) bombList.placeBomb(playerX, playerY, 5);
        else movePlayer(input, playerX, playerY);
    }

    cout << "\nGame Over! Keys Collected: " << keysFound << "/2\n";
    return 0;
}

